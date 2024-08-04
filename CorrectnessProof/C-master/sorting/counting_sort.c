

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, n, l = 0;

    printf("Enter size of array = ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements in array :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > l)
            l = a[i];
    }

    int *b = (int *)malloc((l + 1) * sizeof(int));
    memset(b, 0, (l + 1) * sizeof(b[0]));

    for (i = 0; i < n; i++) b[a[i]]++;  

    for (i = 0; i < (l + 1); i++)  
    {
        if (b[i] > 0)
        {
            while (b[i] != 0)  
            {
                printf("%d ", i);
                b[i]--;
            }
        }
    }

    free(a);
    free(b);
    return 0;
}
