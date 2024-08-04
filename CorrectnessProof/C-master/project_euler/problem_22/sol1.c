
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _OPENMP
#include <omp.h>
#endif

#define MAX_NAMES 6000  
#define MAX_NAME_LEN 20 


void shell_sort(char data[][MAX_NAME_LEN], int LEN)
{
    const int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    const int gap_len = 8;
    int i, j, g;

    for (g = 0; g < gap_len; g++)
    {
        int gap = gaps[g];
        for (i = gap; i < LEN; i++)
        {
            char tmp_buffer[MAX_NAME_LEN];
            strcpy(tmp_buffer, data[i]);

            for (j = i; j >= gap && strcmp(data[j - gap], tmp_buffer) > 0;
                 j -= gap)
                strcpy(data[j], data[j - gap]);
            strcpy(data[j], tmp_buffer);
        }
    }
#ifdef DEBUG
    for (i = 0; i < LEN; i++) printf("%s\t", data[i]);
#endif
}


void lazy_sort(char data[][MAX_NAME_LEN], int LEN)
{
    int i, j;
    for (i = 0; i < LEN; i++)
    {
        for (j = i + 1; j < LEN; j++)
        {
            if (strcmp(data[i], data[j]) > 0)
            {
                char tmp_buffer[MAX_NAME_LEN];
                strcpy(tmp_buffer, data[i]);
                strcpy(data[i], data[j]);
                strcpy(data[j], tmp_buffer);
            }
        }
    }
#ifdef DEBUG
    for (i = 0; i < LEN; i++) printf("%s\t", data[i]);
#endif
}


int main(int argc, char **argv)
{
    unsigned long COUNT = 0;
    char *fname = "names.txt";
    char names[MAX_NAMES][MAX_NAME_LEN];
    short method = 0; 

    if (argc == 2)
        method = atoi(argv[1]);

    FILE *fp = fopen(fname, "rt");
    if (!fp)
    {
        perror("Unable to open file");
        return -1;
    }

    
    do
    {
        int ret = fscanf(fp, "\"%[^\",]\",", names[COUNT++]);
        if (ret <= 0)
            continue;
        
    } while (!feof(fp));
    fclose(fp);

    printf("\nTotal number of names: %lu\n", COUNT);

    if (method == 0)
    {
        clock_t start_time = clock();
        shell_sort(names, COUNT);
        clock_t end_time = clock();
        printf("\nShell sort: %.4g millisecond\n",
               1e3 * (end_time - start_time) / CLOCKS_PER_SEC);
    }
    else if (method == 1)
    {
        clock_t start_time = clock();
        lazy_sort(names, COUNT);
        clock_t end_time = clock();
        printf("\nLazy sort: %.4g millisecond\n",
               1e3 * (end_time - start_time) / CLOCKS_PER_SEC);
    }

    long sum_score = 0;
    clock_t start_time = clock();
    int i;

#ifdef _OPENMP
#pragma omp parallel for schedule(runtime) reduction(+ : sum_score)
#endif
#ifdef DEBUG
    for (i = 935; i < 940; i++)
#else
    for (i = 0; i < COUNT; i++)
#endif
    {
        long score = 0;
        
        for (int j = 0; names[i][j] != '\0'; j++)
            score += names[i][j] - 'A' +
                     1; 
        sum_score += score * (i + 1);
#ifdef DEBUG
        printf("Name: %s\tScore: %u x %u = %lu\n", names[i], score, i + 1,
               (unsigned long)score * (i + 1));
#endif
    }
    clock_t end_time = clock();
    printf("Scoring time: %.4g millisecond\n",
           1e3 * (end_time - start_time) / CLOCKS_PER_SEC);

    printf("Total Score = %lu\n", sum_score);

    return 0;
}
