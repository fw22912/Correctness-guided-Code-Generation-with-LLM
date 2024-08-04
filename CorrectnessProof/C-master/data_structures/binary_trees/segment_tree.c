

#include <assert.h>   
#include <inttypes.h> 
#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>   


typedef void (*combine_function)(const void *a, const void *b, void *result);


typedef struct segment_tree
{
    void *root;       
    void *identity;   
    size_t elem_size; 
    size_t length;    
    
    combine_function combine;
} segment_tree;


void segment_tree_build(segment_tree *tree)
{
    size_t elem_size = tree->elem_size;
    int index = (tree->length - 2);
    size_t b, l, r;
    char *ptr = (char *)tree->root;
    for (; index >= 0; index--)
    {
        b = index * elem_size;
        l = (2 * index + 1) * elem_size;
        r = (2 * index + 2) * elem_size;
        tree->combine(ptr + l, ptr + r, ptr + b);
    }
}


void segment_tree_update(segment_tree *tree, size_t index, void *val)
{
    size_t elem_size = tree->elem_size;
    index = index + tree->length - 1;
    char *base = (char *)tree->root;
    char *t = base + index * elem_size;
    memcpy(t, val, elem_size);
    while (index > 0)
    {
        index = ((index - 1) >> 1);
        tree->combine(base + (2 * index + 1) * elem_size,
                      base + (2 * index + 2) * elem_size,
                      base + index * elem_size);
    }
}


void segment_tree_query(segment_tree *tree, long long l, long long r, void *res)
{
    size_t elem_size = tree->elem_size;
    memcpy(res, tree->identity, elem_size);
    elem_size = tree->elem_size;
    char *root = (char *)tree->root;
    l += tree->length - 1;
    r += tree->length - 1;
    while (l <= r)
    {
        if (!(l & 1))
        {
            tree->combine(res, root + l * elem_size, res);
        }
        if (r & 1)
        {
            tree->combine(res, root + r * elem_size, res);
        }
        r = (r >> 1) - 1;
        l = (l >> 1);
    }
}


segment_tree *segment_tree_init(void *arr, size_t elem_size, size_t len,
                                void *identity, combine_function func)
{
    segment_tree *tree = malloc(sizeof(segment_tree));
    tree->elem_size = elem_size;
    tree->length = len;
    tree->combine = func;
    tree->root = malloc(sizeof(char) * elem_size * (2 * len - 1));
    tree->identity = malloc(sizeof(char) * elem_size);
    char *ptr = (char *)tree->root;
    memset(ptr, 0, (len - 1) * elem_size);  
    ptr = ptr + (len - 1) * elem_size;
    memcpy(ptr, arr, elem_size * len);  
    memcpy(tree->identity, identity, elem_size);  
    return tree;
}


void segment_tree_dispose(segment_tree *tree)
{
    free(tree->root);
    free(tree->identity);
}


void segment_tree_print_int(segment_tree *tree)
{
    char *base = (char *)tree->root;
    size_t i = 0;
    for (; i < 2 * tree->length - 1; i++)
    {
        printf("%d ", *(int *)(base + i * tree->elem_size));
    }
    printf("\n");
}


void minimum(const void *a, const void *b, void *c)
{
    *(int *)c = *(int *)a < *(int *)b ? *(int *)a : *(int *)b;
}


static void test()
{
    int32_t arr[10] = {1, 0, 3, 5, 7, 2, 11, 6, -2, 8};
    int32_t identity = __INT32_MAX__;
    segment_tree *tree =
        segment_tree_init(arr, sizeof(*arr), 10, &identity, minimum);
    segment_tree_build(tree);
    int32_t result;
    segment_tree_query(tree, 3, 6, &result);
    assert(result == 2);
    segment_tree_query(tree, 8, 9, &result);
    assert(result == -2);
    result = 12;
    segment_tree_update(tree, 5, &result);
    segment_tree_update(tree, 8, &result);
    segment_tree_query(tree, 0, 3, &result);
    assert(result == 0);
    segment_tree_query(tree, 8, 9, &result);
    assert(result == 8);
    segment_tree_dispose(tree);
}


int main()
{
    test();
    return 0;
}
