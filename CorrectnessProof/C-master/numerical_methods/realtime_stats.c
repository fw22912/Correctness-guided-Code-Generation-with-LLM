
#include <assert.h>
#include <math.h>
#include <stdio.h>


void stats_computer1(float x, float *mean, float *variance, float *std)
{
    
    static unsigned int n = 0;
    static float Ex = 0.f, Ex2 = 0.f;
    static float K = 0.f;

    if (n == 0)
        K = x;
    n++;
    float tmp = x - K;
    Ex += tmp;
    Ex2 += tmp * tmp;

    
    if (mean != NULL)
        *mean = K + Ex / n;

    
    if (variance != NULL)
        *variance = (Ex2 - (Ex * Ex) / n) / (n - 1);

    
    if (std != NULL)
        *std = sqrtf(*variance);
}


void stats_computer2(float x, float *mean, float *variance, float *std)
{
    
    static unsigned int n = 0;
    static float mu = 0, M = 0;

    n++;
    float delta = x - mu;
    mu += delta / n;
    float delta2 = x - mu;
    M += delta * delta2;

    
    if (mean != NULL)
        *mean = mu;

    
    if (variance != NULL)
        *variance = M / n;

    
    if (std != NULL)
        *std = sqrtf(*variance);
}


void test_function(const float *test_data, const int number_of_samples)
{
    float ref_mean = 0.f, ref_variance = 0.f;
    float s1_mean = 0.f, s1_variance = 0.f, s1_std = 0.f;
    float s2_mean = 0.f, s2_variance = 0.f, s2_std = 0.f;

    for (int i = 0; i < number_of_samples; i++)
    {
        stats_computer1(test_data[i], &s1_mean, &s1_variance, &s1_std);
        stats_computer2(test_data[i], &s2_mean, &s2_variance, &s2_std);
        ref_mean += test_data[i];
    }
    ref_mean /= number_of_samples;

    for (int i = 0; i < number_of_samples; i++)
    {
        float temp = test_data[i] - ref_mean;
        ref_variance += temp * temp;
    }
    ref_variance /= number_of_samples;

    printf("<<<<<<<< Test Function >>>>>>>>\n");
    printf("Expected: Mean: %.4f\t Variance: %.4f\n", ref_mean, ref_variance);
    printf("\tMethod 1:\tMean: %.4f\t Variance: %.4f\t Std: %.4f\n", s1_mean,
           s1_variance, s1_std);
    printf("\tMethod 2:\tMean: %.4f\t Variance: %.4f\t Std: %.4f\n", s2_mean,
           s2_variance, s2_std);

    assert(fabs(s1_mean - ref_mean) < 0.01);
    assert(fabs(s2_mean - ref_mean) < 0.01);
    assert(fabs(s2_variance - ref_variance) < 0.01);

    printf("(Tests passed)\n\n");
}


int main(int argc, char **argv)
{
    const float test_data1[] = {3, 4, 5, -1.4, -3.6, 1.9, 1.};
    test_function(test_data1, sizeof(test_data1) / sizeof(test_data1[0]));

    float s1_mean = 0.f, s1_variance = 0.f, s1_std = 0.f;
    float s2_mean = 0.f, s2_variance = 0.f, s2_std = 0.f;

    printf("Enter data. Any non-numeric data will terminate the data input.\n");

    while (1)
    {
        float val;
        printf("Enter number: ");

        
        
        if (!scanf("%f", &val))
            break;

        stats_computer1(val, &s1_mean, &s1_variance, &s1_std);
        stats_computer2(val, &s2_mean, &s2_variance, &s2_std);

        printf("\tMethod 1:\tMean: %.4f\t Variance: %.4f\t Std: %.4f\n",
               s1_mean, s1_variance, s1_std);
        printf("\tMethod 2:\tMean: %.4f\t Variance: %.4f\t Std: %.4f\n",
               s2_mean, s2_variance, s2_std);
    }

    return 0;
}
