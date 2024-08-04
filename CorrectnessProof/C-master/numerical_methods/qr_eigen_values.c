
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "qr_decompose.h"
#ifdef _OPENMP
#include <omp.h>
#endif

#define LIMS 9        
#define EPSILON 1e-10 


void create_matrix(double **A, int N)
{
    int i, j, tmp, lim2 = LIMS >> 1;

#ifdef _OPENMP
#pragma omp for
#endif
    for (i = 0; i < N; i++)
    {
        A[i][i] = (rand() % LIMS) - lim2;
        for (j = i + 1; j < N; j++)
        {
            tmp = (rand() % LIMS) - lim2;
            A[i][j] = tmp;
            A[j][i] = tmp;
        }
    }
}


double **mat_mul(double **A, double **B, double **OUT, int R1, int C1, int R2,
                 int C2)
{
    if (C1 != R2)
    {
        perror("Matrix dimensions mismatch!");
        return OUT;
    }

    int i;
#ifdef _OPENMP
#pragma omp for
#endif
    for (i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            OUT[i][j] = 0.f;
            for (int k = 0; k < C1; k++) OUT[i][j] += A[i][k] * B[k][j];
        }
    }
    return OUT;
}


double eigen_values(double **A, double *eigen_vals, int mat_size,
                    char debug_print)
{
    if (!eigen_vals)
    {
        perror("Output eigen value vector cannot be NULL!");
        return -1;
    }
    double **R = (double **)malloc(sizeof(double *) * mat_size);
    double **Q = (double **)malloc(sizeof(double *) * mat_size);
    if (!Q || !R)
    {
        perror("Unable to allocate memory for Q & R!");
        if (Q)
        {
            free(Q);
        }
        if (R)
        {
            free(R);
        }
        return -1;
    }

    
    for (int i = 0; i < mat_size; i++)
    {
        R[i] = (double *)malloc(sizeof(double) * mat_size);
        Q[i] = (double *)malloc(sizeof(double) * mat_size);
        if (!Q[i] || !R[i])
        {
            perror("Unable to allocate memory for Q & R.");
            for (; i >= 0; i--)
            {
                free(R[i]);
                free(Q[i]);
            }
            free(Q);
            free(R);
            return -1;
        }
    }

    if (debug_print)
    {
        print_matrix(A, mat_size, mat_size);
    }

    int rows = mat_size, columns = mat_size;
    int counter = 0, num_eigs = rows - 1;
    double last_eig = 0;

    clock_t t1 = clock();
    while (num_eigs > 0) 
    {
        
        while (fabs(A[num_eigs][num_eigs - 1]) > EPSILON)
        {
            last_eig = A[num_eigs][num_eigs];
            for (int i = 0; i < rows; i++) A[i][i] -= last_eig; 
            qr_decompose(A, Q, R, rows, columns);

            if (debug_print)
            {
                print_matrix(A, rows, columns);
                print_matrix(Q, rows, columns);
                print_matrix(R, columns, columns);
                printf("-------------------- %d ---------------------\n",
                       ++counter);
            }

            mat_mul(R, Q, A, columns, columns, rows, columns);
            for (int i = 0; i < rows; i++) A[i][i] += last_eig; 
        }

        
        eigen_vals[num_eigs] = last_eig;

        if (debug_print)
        {
            printf("========================\n");
            printf("Eigen value: % g,\n", last_eig);
            printf("========================\n");
        }

        num_eigs--;
        rows--;
        columns--;
    }
    eigen_vals[0] = A[0][0];
    double dtime = (double)(clock() - t1) / CLOCKS_PER_SEC;

    if (debug_print)
    {
        print_matrix(R, mat_size, mat_size);
        print_matrix(Q, mat_size, mat_size);
    }

    
    for (int i = 0; i < mat_size; i++)
    {
        free(R[i]);
        free(Q[i]);
    }
    free(R);
    free(Q);

    return dtime;
}


void test1()
{
    int mat_size = 2;
    double X[][2] = {{5, 7}, {7, 11}};
    double y[] = {15.56158, 0.384227};  
    double eig_vals[2] = {0, 0};

    
    double **A = (double **)malloc(mat_size * sizeof(double *));
    for (int i = 0; i < mat_size; i++) A[i] = X[i];

    printf("------- Test 1 -------\n");

    double dtime = eigen_values(A, eig_vals, mat_size, 0);

    for (int i = 0; i < mat_size; i++)
    {
        printf("%d/5 Checking for %.3g --> ", i + 1, y[i]);
        char result = 0;
        for (int j = 0; j < mat_size && !result; j++)
        {
            if (fabs(y[i] - eig_vals[j]) < 0.1)
            {
                result = 1;
                printf("(%.3g) ", eig_vals[j]);
            }
        }

        
        assert(result != 0);
        printf("found\n");
    }
    printf("Test 1 Passed in %.3g sec\n\n", dtime);
    free(A);
}


void test2()
{
    int mat_size = 5;
    double X[][5] = {{-4, 4, 2, 0, -3},
                     {4, -4, 4, -3, -1},
                     {2, 4, 4, 3, -3},
                     {0, -3, 3, -1, -3},
                     {-3, -1, -3, -3, 0}};
    double y[] = {9.27648, -9.26948, 2.0181, -1.03516,
                  -5.98994};  
    double eig_vals[5];

    
    double **A = (double **)malloc(mat_size * sizeof(double *));
    for (int i = 0; i < mat_size; i++) A[i] = X[i];

    printf("------- Test 2 -------\n");

    double dtime = eigen_values(A, eig_vals, mat_size, 0);

    for (int i = 0; i < mat_size; i++)
    {
        printf("%d/5 Checking for %.3g --> ", i + 1, y[i]);
        char result = 0;
        for (int j = 0; j < mat_size && !result; j++)
        {
            if (fabs(y[i] - eig_vals[j]) < 0.1)
            {
                result = 1;
                printf("(%.3g) ", eig_vals[j]);
            }
        }

        
        assert(result != 0);
        printf("found\n");
    }
    printf("Test 2 Passed in %.3g sec\n\n", dtime);
    free(A);
}


int main(int argc, char **argv)
{
    srand(time(NULL));

    int mat_size = 5;
    if (argc == 2)
    {
        mat_size = atoi(argv[1]);
    }
    else
    {  
        test1();
        test2();
        printf("Usage: ./qr_eigen_values [mat_size]\n");
        return 0;
    }

    if (mat_size < 2)
    {
        fprintf(stderr, "Matrix size should be > 2\n");
        return -1;
    }

    int i;

    double **A = (double **)malloc(sizeof(double *) * mat_size);
    
    double *eigen_vals = (double *)malloc(sizeof(double) * mat_size);
    if (!eigen_vals)
    {
        perror("Unable to allocate memory for eigen values!");
        free(A);
        return -1;
    }
    for (i = 0; i < mat_size; i++)
    {
        A[i] = (double *)malloc(sizeof(double) * mat_size);
        eigen_vals[i] = 0.f;
    }

    
    create_matrix(A, mat_size);

    print_matrix(A, mat_size, mat_size);

    double dtime = eigen_values(A, eigen_vals, mat_size, 0);
    printf("Eigen vals: ");
    for (i = 0; i < mat_size; i++) printf("% 9.4g\t", eigen_vals[i]);
    printf("\nTime taken to compute: % .4g sec\n", dtime);

    for (int i = 0; i < mat_size; i++) free(A[i]);
    free(A);
    free(eigen_vals);
    return 0;
}
