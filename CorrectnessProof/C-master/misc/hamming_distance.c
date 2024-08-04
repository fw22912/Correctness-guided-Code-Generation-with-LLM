

#include <assert.h>  
#include <stdio.h>   


int hamming_distance(char* str1, char* str2)
{
    int i = 0, distance = 0;

    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            distance++;
        }
        i++;
    }

    return distance;
}


static void test()
{
    char str1[] = "karolin";
    char str2[] = "kathrin";

    assert(hamming_distance(str1, str2) == 3);

    char str3[] = "00000";
    char str4[] = "11111";

    assert(hamming_distance(str3, str4) == 5);
    printf("All tests have successfully passed!\n");
}

int main()
{
    test();  
    return 0;
}
