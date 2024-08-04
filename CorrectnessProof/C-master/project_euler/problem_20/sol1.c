
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct _big_int
{
    char value;                  
    struct _big_int *next_digit; 
    struct _big_int *prev_digit; 
} big_int;

#ifdef DEBUG

void print_digit(const big_int *my_int)
{
    printf("\tValue : %d\n\tNext : %p\n\tPrev : %p\n", my_int->value,
           my_int->next_digit, my_int->prev_digit);
}
#endif


big_int *add_digit(big_int *digit, char value)
{
    if (digit == NULL)
    {
        digit = (big_int *)malloc(sizeof(big_int));
        if (!digit)
        {
            perror("Unable to allocate memory!");
            return NULL;
        }
        digit->value = value;
        digit->next_digit = NULL;
        digit->prev_digit = NULL;

        return digit;
    }

    if (digit->next_digit)
    {
        digit->next_digit->value = value;
        return digit->next_digit;
    }

    digit->next_digit = (big_int *)malloc(sizeof(big_int));
    if (digit->next_digit == NULL)
    {
        perror("Unable to allocate memory!");
        return NULL;
    }
    digit->next_digit->value = value;
    digit->next_digit->next_digit = NULL;
    digit->next_digit->prev_digit = digit;
    return digit->next_digit;
}


char remove_digits(big_int *digit, int N)
{
    if (digit == NULL)
        return 0;

    if (digit->next_digit == NULL)
    {
        free(digit);
        digit = NULL;
        return 0;
    }

    if (N > 0)
        return remove_digits(digit->next_digit, N - 1);

    return remove_digits(digit->next_digit, 0);
}


int main(int argc, char **argv)
{
    unsigned int N = 5;
    big_int *ptr = add_digit(NULL, 1); 
    const big_int *ptr0 = ptr;         
    unsigned long sum_digits = 0;
    unsigned long num_digits = 0;

    if (argc == 2)
        N = atoi(argv[1]);

    clock_t start_time = clock();

    for (unsigned int i = 1; i <= N; i++)
    {
        int carry = 0;
#ifdef DEBUG
        printf("%3d: ", i);
#endif
        ptr = (big_int *)ptr0; 
        while (ptr)
        {
#ifdef DEBUG
            printf("%p\t", ptr);
#endif
            unsigned int tmp = ptr->value * i + carry;
            if (tmp >= 10)
            {
                div_t tmp2 = div(tmp, 10);
                carry = tmp2.quot;
                tmp = tmp2.rem;
            }
            else
                carry = 0;

            if (carry > 0 && ptr->next_digit == NULL)
                add_digit(ptr, 0);

            ptr->value = tmp;

            if (i == N)
                
                sum_digits += tmp;

            if (ptr->next_digit)
                
                ptr = ptr->next_digit;
            else
                
                break;
        }
#ifdef DEBUG
        printf("\n");
#endif
    }

    clock_t end_time = clock();

#ifdef DEBUG
    printf("ptr = %p\n", ptr);
    printf("%d! = ", N);
#endif

    
    
    
    
    
    do
    {
        putchar(ptr->value + 0x30); 
        ptr = ptr->prev_digit;
        num_digits++;
    } while (ptr); 

    printf("\nTime taken: %.4g millisecond\n",
           1e3 * (end_time - start_time) / CLOCKS_PER_SEC);
    printf(
        "Digit Sum = %lu\tNumber of digits = %lu\tStorage space = %.3gkb\t \n",
        sum_digits, num_digits, num_digits * sizeof(big_int) / 1024.0);

    remove_digits((big_int *)ptr0, -1);
    return 0;
}
