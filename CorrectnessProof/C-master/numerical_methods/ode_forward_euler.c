

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define order 2 


void problem(const double *x, double *y, double *dy)
{
    const double omega = 1.F;       
    dy[0] = y[1];                   
    dy[1] = -omega * omega * y[0];  
}


void exact_solution(const double *x, double *y)
{
    y[0] = cos(x[0]);
    y[1] = -sin(x[0]);
}


void forward_euler_step(const double dx, const double *x, double *y, double *dy)
{
    int o;
    problem(x, y, dy);
    for (o = 0; o < order; o++) y[o] += dx * dy[o];
}


double forward_euler(double dx, double x0, double x_max, double *y,
                     char save_to_file)
{
    double dy[order];

    FILE *fp = NULL;
    if (save_to_file)
    {
        fp = fopen("forward_euler.csv", "w+");
        if (fp == NULL)
        {
            perror("Error! ");
            return -1;
        }
    }

    
    clock_t t1 = clock();
    double x = x0;
    do  
    {
        if (save_to_file && fp)
            fprintf(fp, "%.4g,%.4g,%.4g\n", x, y[0], y[1]);  
        forward_euler_step(dx, &x, y, dy);  
        x += dx;                            
    } while (x <= x_max);  
    
    clock_t t2 = clock();

    if (save_to_file && fp)
        fclose(fp);

    return (double)(t2 - t1) / CLOCKS_PER_SEC;
}


int main(int argc, char *argv[])
{
    double X0 = 0.f;          
    double X_MAX = 10.F;      
    double Y0[] = {1.f, 0.f}; 
    double step_size;

    if (argc == 1)
    {
        printf("\nEnter the step size: ");
        scanf("%lg", &step_size);
    }
    else
        
        step_size = atof(argv[1]);

    
    double total_time = forward_euler(step_size, X0, X_MAX, Y0, 1);
    printf("\tTime = %.6g ms\n", total_time);

    
    FILE *fp = fopen("exact.csv", "w+");
    if (fp == NULL)
    {
        perror("Error! ");
        return -1;
    }
    double x = X0;
    double *y = &(Y0[0]);
    printf("Finding exact solution\n");
    clock_t t1 = clock();

    do
    {
        fprintf(fp, "%.4g,%.4g,%.4g\n", x, y[0], y[1]);  
        exact_solution(&x, y);
        x += step_size;
    } while (x <= X_MAX);

    clock_t t2 = clock();
    total_time = (t2 - t1) / CLOCKS_PER_SEC;
    printf("\tTime = %.6g ms\n", total_time);
    fclose(fp);

    return 0;
}
