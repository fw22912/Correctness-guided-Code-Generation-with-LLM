
#include <assert.h>  
#include <inttypes.h>  
#include <stdio.h>     
#include <stdlib.h>  

typedef struct DArrayStack
{
    int capacity, top;  
    int *arrPtr;        
} DArrayStack;


DArrayStack *create_stack(int cap)
{
    DArrayStack *ptr;
    ptr = (DArrayStack *)malloc(sizeof(DArrayStack));
    ptr->capacity = cap;
    ptr->top = -1;
    ptr->arrPtr = (int *)malloc(sizeof(int) * cap);
    printf("\nStack of capacity %d is successfully created.\n", ptr->capacity);
    return (ptr);
}


DArrayStack *double_array(DArrayStack *ptr, int cap)
{
    int newCap = 2 * cap;
    int *temp;
    temp = (int *)malloc(sizeof(int) * newCap);
    for (int i = 0; i < (ptr->top) + 1; i++)
    {
        temp[i] = ptr->arrPtr[i];
    }
    free(ptr->arrPtr);
    ptr->arrPtr = temp;
    ptr->capacity = newCap;
    return ptr;
}


DArrayStack *shrink_array(DArrayStack *ptr, int cap)
{
    int newCap = cap / 2;
    int *temp;
    temp = (int *)malloc(sizeof(int) * newCap);
    for (int i = 0; i < (ptr->top) + 1; i++)
    {
        temp[i] = ptr->arrPtr[i];
    }
    free(ptr->arrPtr);
    ptr->arrPtr = temp;
    ptr->capacity = newCap;
    return ptr;
}


int push(DArrayStack *ptr, int data)
{
    if (ptr->top == (ptr->capacity) - 1)
    {
        ptr = double_array(ptr, ptr->capacity);
        ptr->top++;
        ptr->arrPtr[ptr->top] = data;
    }
    else
    {
        ptr->top++;
        ptr->arrPtr[ptr->top] = data;
    }
    printf("Successfully pushed : %d\n", data);
    return ptr->top;
}


int pop(DArrayStack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is empty UNDERFLOW \n");
        return -1;
    }
    int ele = ptr->arrPtr[ptr->top];
    ptr->arrPtr[ptr->top] = 0;
    ptr->top = (ptr->top - 1);
    if ((ptr->capacity) % 2 == 0)
    {
        if (ptr->top <= (ptr->capacity / 2) - 1)
        {
            ptr = shrink_array(ptr, ptr->capacity);
        }
    }
    printf("Successfully popped: %d\n", ele);
    return ele;
}


int peek(DArrayStack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is empty UNDERFLOW \n");
        return -1;
    }
    return ptr->arrPtr[ptr->top];
}


int show_capacity(DArrayStack *ptr) { return ptr->capacity; }


int isempty(DArrayStack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}


int stack_size(DArrayStack *ptr) { return ptr->top + 1; }


static void test()
{
    DArrayStack *NewStack;
    int capacity = 1;
    NewStack = create_stack(capacity);
    uint64_t arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    printf("\nTesting Empty stack: ");
    assert(stack_size(NewStack) == 0);
    assert(isempty(NewStack) == 1);
    printf("Size of an empty stack is %d\n", stack_size(NewStack));

    printf("\nTesting PUSH operation:\n");
    for (int i = 0; i < 12; ++i)
    {
        int topVal = push(NewStack, arr[i]);
        printf("Size: %d, Capacity: %d\n\n", stack_size(NewStack),
               show_capacity(NewStack));
        assert(topVal == i);
        assert(peek(NewStack) == arr[i]);
        assert(stack_size(NewStack) == i + 1);
        assert(isempty(NewStack) == 0);
    }

    printf("\nTesting POP operation:\n");
    for (int i = 11; i > -1; --i)
    {
        peek(NewStack);
        assert(peek(NewStack) == arr[i]);
        int ele = pop(NewStack);
        assert(ele == arr[i]);
        assert(stack_size(NewStack) == i);
    }

    printf("\nTesting Empty stack size: ");
    assert(stack_size(NewStack) == 0);
    assert(isempty(NewStack) == 1);
    printf("Size of an empty stack is %d\n", stack_size(NewStack));

    printf("\nTesting POP operation on empty stack: ");
    assert(pop(NewStack) == -1);
}


int main()
{
    test();  
    return 0;
}
