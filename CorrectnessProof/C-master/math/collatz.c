

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    unsigned long long n, curr_no, num_steps = 0;
    if (argc == 2)
        n = strtoull(argv[1], NULL, 10);
    else
    {
        printf("Enter starting number: ");
        scanf("%lu", &n);  
    }

    curr_no = n;          
    while (curr_no != 1)  
    {
        num_steps++;
        printf("%llu->", curr_no);
        if (curr_no % 2 == 0)  
            curr_no = curr_no / 2;
        else
            curr_no = (curr_no * 3) + 1;  
    }
    printf("1\nNumber of steps: %llu\n", num_steps);
    return 0;
}
