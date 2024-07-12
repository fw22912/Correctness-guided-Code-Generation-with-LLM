/**
 * @file
 * \brief Compute factorial of arbitrarily large numbers by
 * storing individual digits in a byte.
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/**
 * dynamically large number
 */
typedef struct _large_num
{
    char *digits;            /**< array to store individual digits */
    unsigned int num_digits; /**< number of digits in the number */
} large_num;

/**
 * create a new large number
 * \returns pointer to a large number
 */
large_num *new_number(void)
{
    large_num *new_num = (large_num *)malloc(sizeof(large_num));
    new_num->num_digits = 1;
    new_num->digits = (char *)malloc(1 * sizeof(char));
    new_num->digits[0] = 1;
    return new_num;
}

/**
 * delete all memory allocated for large number
 * \param[in] num pointer to large_num to delete
 */
void delete_number(large_num *num)
{
    free(num->digits);
    free(num);
}

/**
 * add a digit to the large number
 * \param[in,out] num
 * \param[in] value value of the digit to insert
 */
void add_digit(large_num *num, unsigned int value)
{
    if (value > 9)
    {
        fprintf(stderr, "digit > 9!!\n");
        delete_number(num);
        exit(EXIT_FAILURE);
    }

    num->num_digits++;
    num->digits = (char *)realloc(num->digits, num->num_digits * sizeof(char));
    num->digits[num->num_digits - 1] = value;
}

/**
 * multiply large number with another integer and
 * store the result in the same large number
 */
void multiply(large_num *num, unsigned long n)
{
    int i;
    unsigned long carry = 0, temp;
    for (i = 0; i < num->num_digits; i++)
    {
        temp = num->digits[i] * n;
        temp += carry;
        if (temp < 10)
            carry = 0;
        else
        {
            carry = temp / 10;
            temp = temp % 10;
        }
        num->digits[i] = temp;
    }

    while (carry != 0)
    {
        add_digit(num, carry % 10);
        carry /= 10;
    }
}

/**
 * main function
 */
int main(int argc, char *argv[])
{
    int number, i;

    // Asks for the number/position of term in Fibonnacci sequence
    if (argc == 2)
        number = atoi(argv[1]);
    else
    {
        printf("Enter the value of n(n starts from 0 ): ");
        scanf("%d", &number);
    }

    large_num *result = new_number();

    clock_t start_time = clock();
    for (i = 2; i <= number; i++) /* Multiply every number from 2 thru N */
        multiply(result, i);
    double time_taken = (clock() - start_time) * (double)1e3 / CLOCKS_PER_SEC;
    // time_taken = (clock() - start_time) / (double) CLOCKS_PER_SEC;

    printf("%d! = ", number);
    for (i = result->num_digits; i > 0; i--)
        putchar(result->digits[i - 1] + '0');
    printf("\nTime taken: %.4g ms\n", time_taken);

    delete_number(result);
    return 0;
}

void proof_harness_new_number() {
    large_num *new_num = new_number();
    assert(new_num->num_digits == 1);
    assert(new_num->digits[0] == 1);
    delete_number(new_num);
}

void proof_harness_delete_number() {
    large_num *num = new_number();
    delete_number(num);
    // No assertions can be made after calling delete_number
}

void proof_harness_add_digit() {
    large_num *num = new_number();
    unsigned int value;
    __CPROVER_assume(value >= 0);
    __CPROVER_assume(value <= 9);
    add_digit(num, value);
    assert(num->num_digits == 2);
    assert(num->digits[1] == value);
    delete_number(num);
}

void proof_harness_multiply() {
    large_num *num = new_number();
    unsigned long n;
    __CPROVER_assume(n >= 0);
    multiply(num, n);
    // Assertions are difficult to formulate for multiply as the result is dependent on the input 'n'
    delete_number(num);
}