#include <stdio.h>
#include <assert.h>

// Euclid's algorithm
int GCD(int x, int y)
{
    if (y == 0)
        return x;
    return GCD(y, x % y);
}

int main()
{
    int a, b;
    printf("Input two numbers:\n");
    scanf("%d %d", &a, &b);
    printf("Greatest common divisor: %d\n", GCD(a, b));
}

void proof_harness_GCD() {
    int x;
    int y;
    int expected_result;
    
    x = 0;
    y = 0;
    expected_result = 0;
    assert(GCD(x, y) == expected_result);
    
    x = 0;
    y = 1;
    expected_result = 1;
    assert(GCD(x, y) == expected_result);
    
    x = 1;
    y = 0;
    expected_result = 1;
    assert(GCD(x, y) == expected_result);
    
    x = 1;
    y = 1;
    expected_result = 1;
    assert(GCD(x, y) == expected_result);
    
    x = 2;
    y = 1;
    expected_result = 1;
    assert(GCD(x, y) == expected_result);
    
    x = 1;
    y = 2;
    expected_result = 1;
    assert(GCD(x, y) == expected_result);
    
    x = 2;
    y = 2;
    expected_result = 2;
    assert(GCD(x, y) == expected_result);
    
    x = 4;
    y = 2;
    expected_result = 2;
    assert(GCD(x, y) == expected_result);
    
    x = 2;
    y = 4;
    expected_result = 2;
    assert(GCD(x, y) == expected_result);
    
    x = 4;
    y = 8;
    expected_result = 4;
    assert(GCD(x, y) == expected_result);
    
    x = 8;
    y = 4;
    expected_result = 4;
    assert(GCD(x, y) == expected_result);
    
    x = 12;
    y = 8;
    expected_result = 4;
    assert(GCD(x, y) == expected_result);
    
    x = 8;
    y = 12;
    expected_result = 4;
    assert(GCD(x, y) == expected_result);
    
    x = 12;
    y = 16;
    expected_result = 4;
    assert(GCD(x, y) == expected_result);
    
    x = 16;
    y = 12;
    expected_result = 4;
    assert(GCD(x, y) == expected_result);
}