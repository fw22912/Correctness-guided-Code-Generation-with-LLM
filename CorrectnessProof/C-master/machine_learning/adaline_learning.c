

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




#define MAX_ADALINE_ITER 500  


struct adaline
{
    double eta;      
    double *weights; 
    int num_weights; 
};


#define ADALINE_ACCURACY 1e-5


struct adaline new_adaline(const int num_features, const double eta)
{
    if (eta <= 0.f || eta >= 1.f)
    {
        fprintf(stderr, "learning rate should be > 0 and < 1\n");
        exit(EXIT_FAILURE);
    }

    
    int num_weights = num_features + 1;
    struct adaline ada;
    ada.eta = eta;
    ada.num_weights = num_weights;
    ada.weights = (double *)malloc(num_weights * sizeof(double));
    if (!ada.weights)
    {
        perror("Unable to allocate error for weights!");
        return ada;
    }

    
    for (int i = 0; i < num_weights; i++) ada.weights[i] = 1.f;
    

    return ada;
}


void delete_adaline(struct adaline *ada)
{
    if (ada == NULL)
        return;

    free(ada->weights);
};


int adaline_activation(double x) { return x > 0 ? 1 : -1; }


char *adaline_get_weights_str(const struct adaline *ada)
{
    static char out[100];  

    sprintf(out, "<");
    for (int i = 0; i < ada->num_weights; i++)
    {
        sprintf(out, "%s%.4g", out, ada->weights[i]);
        if (i < ada->num_weights - 1)
            sprintf(out, "%s, ", out);
    }
    sprintf(out, "%s>", out);
    return out;
}


int adaline_predict(struct adaline *ada, const double *x, double *out)
{
    double y = ada->weights[ada->num_weights - 1];  

    for (int i = 0; i < ada->num_weights - 1; i++) y += x[i] * ada->weights[i];

    if (out)  
        *out = y;

    
    return adaline_activation(y);
}


double adaline_fit_sample(struct adaline *ada, const double *x, const int y)
{
    
    int p = adaline_predict(ada, x, NULL);
    int prediction_error = y - p;  
    double correction_factor = ada->eta * prediction_error;

    
    for (int i = 0; i < ada->num_weights - 1; i++)
    {
        ada->weights[i] += correction_factor * x[i];
    }
    ada->weights[ada->num_weights - 1] += correction_factor;  

    return correction_factor;
}


void adaline_fit(struct adaline *ada, double **X, const int *y, const int N)
{
    double avg_pred_error = 1.f;

    int iter;
    for (iter = 0;
         (iter < MAX_ADALINE_ITER) && (avg_pred_error > ADALINE_ACCURACY);
         iter++)
    {
        avg_pred_error = 0.f;

        
        for (int i = 0; i < N; i++)
        {
            double err = adaline_fit_sample(ada, X[i], y[i]);
            avg_pred_error += fabs(err);
        }
        avg_pred_error /= N;

        
        
        printf("\tIter %3d: Training weights: %s\tAvg error: %.4f\n", iter,
               adaline_get_weights_str(ada), avg_pred_error);
    }

    if (iter < MAX_ADALINE_ITER)
        printf("Converged after %d iterations.\n", iter);
    else
        printf("Did not converged after %d iterations.\n", iter);
}




void test1(double eta)
{
    struct adaline ada = new_adaline(2, eta);  

    const int N = 10;  
    const double saved_X[10][2] = {{0, 1},  {1, -2},   {2, 3},   {3, -1},
                                   {4, 1},  {6, -5},   {-7, -3}, {-8, 5},
                                   {-9, 2}, {-10, -15}};

    double **X = (double **)malloc(N * sizeof(double *));
    const int Y[10] = {1,  -1, 1, -1, -1,
                       -1, 1,  1, 1,  -1};  
    for (int i = 0; i < N; i++)
    {
        X[i] = (double *)saved_X[i];
    }

    printf("------- Test 1 -------\n");
    printf("Model before fit: %s\n", adaline_get_weights_str(&ada));

    adaline_fit(&ada, X, Y, N);
    printf("Model after fit: %s\n", adaline_get_weights_str(&ada));

    double test_x[] = {5, -3};
    int pred = adaline_predict(&ada, test_x, NULL);
    printf("Predict for x=(5,-3): % d\n", pred);
    assert(pred == -1);
    printf(" ...passed\n");

    double test_x2[] = {5, 8};
    pred = adaline_predict(&ada, test_x2, NULL);
    printf("Predict for x=(5, 8): % d\n", pred);
    assert(pred == 1);
    printf(" ...passed\n");

    
    
    free(X);
    delete_adaline(&ada);
}


void test2(double eta)
{
    struct adaline ada = new_adaline(2, eta);  

    const int N = 50;  

    double **X = (double **)malloc(N * sizeof(double *));
    int *Y = (int *)malloc(N * sizeof(int));  
    for (int i = 0; i < N; i++) X[i] = (double *)malloc(2 * sizeof(double));

    
    
    int range = 500;          
    int range2 = range >> 1;  
    for (int i = 0; i < N; i++)
    {
        double x0 = ((rand() % range) - range2) / 100.f;
        double x1 = ((rand() % range) - range2) / 100.f;
        X[i][0] = x0;
        X[i][1] = x1;
        Y[i] = (x0 + 3. * x1) > -1 ? 1 : -1;
    }

    printf("------- Test 2 -------\n");
    printf("Model before fit: %s\n", adaline_get_weights_str(&ada));

    adaline_fit(&ada, X, Y, N);
    printf("Model after fit: %s\n", adaline_get_weights_str(&ada));

    int N_test_cases = 5;
    double test_x[2];
    for (int i = 0; i < N_test_cases; i++)
    {
        double x0 = ((rand() % range) - range2) / 100.f;
        double x1 = ((rand() % range) - range2) / 100.f;

        test_x[0] = x0;
        test_x[1] = x1;
        int pred = adaline_predict(&ada, test_x, NULL);
        printf("Predict for x=(% 3.2f,% 3.2f): % d\n", x0, x1, pred);

        int expected_val = (x0 + 3. * x1) > -1 ? 1 : -1;
        assert(pred == expected_val);
        printf(" ...passed\n");
    }

    for (int i = 0; i < N; i++) free(X[i]);
    free(X);
    free(Y);
    delete_adaline(&ada);
}


void test3(double eta)
{
    struct adaline ada = new_adaline(6, eta);  

    const int N = 50;  

    double **X = (double **)malloc(N * sizeof(double *));
    int *Y = (int *)malloc(N * sizeof(int));  
    for (int i = 0; i < N; i++) X[i] = (double *)malloc(6 * sizeof(double));

    
    
    int range = 200;          
    int range2 = range >> 1;  
    for (int i = 0; i < N; i++)
    {
        double x0 = ((rand() % range) - range2) / 100.f;
        double x1 = ((rand() % range) - range2) / 100.f;
        double x2 = ((rand() % range) - range2) / 100.f;
        X[i][0] = x0;
        X[i][1] = x1;
        X[i][2] = x2;
        X[i][3] = x0 * x0;
        X[i][4] = x1 * x1;
        X[i][5] = x2 * x2;
        Y[i] = (x0 * x0 + x1 * x1 + x2 * x2) <= 1 ? 1 : -1;
    }

    printf("------- Test 3 -------\n");
    printf("Model before fit: %s\n", adaline_get_weights_str(&ada));

    adaline_fit(&ada, X, Y, N);
    printf("Model after fit: %s\n", adaline_get_weights_str(&ada));

    int N_test_cases = 5;
    double test_x[6];
    for (int i = 0; i < N_test_cases; i++)
    {
        double x0 = ((rand() % range) - range2) / 100.f;
        double x1 = ((rand() % range) - range2) / 100.f;
        double x2 = ((rand() % range) - range2) / 100.f;
        test_x[0] = x0;
        test_x[1] = x1;
        test_x[2] = x2;
        test_x[3] = x0 * x0;
        test_x[4] = x1 * x1;
        test_x[5] = x2 * x2;
        int pred = adaline_predict(&ada, test_x, NULL);
        printf("Predict for x=(% 3.2f,% 3.2f): % d\n", x0, x1, pred);

        int expected_val = (x0 * x0 + x1 * x1 + x2 * x2) <= 1 ? 1 : -1;
        assert(pred == expected_val);
        printf(" ...passed\n");
    }

    for (int i = 0; i < N; i++) free(X[i]);
    free(X);
    free(Y);
    delete_adaline(&ada);
}


int main(int argc, char **argv)
{
    srand(time(NULL));  

    double eta = 0.1;  
    if (argc == 2)     
        eta = strtof(argv[1], NULL);

    test1(eta);

    printf("Press ENTER to continue...\n");
    getchar();

    test2(eta);

    printf("Press ENTER to continue...\n");
    getchar();

    test3(eta);

    return 0;
}
