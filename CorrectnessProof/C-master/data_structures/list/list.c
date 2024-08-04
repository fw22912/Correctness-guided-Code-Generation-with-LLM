#include "list.h"
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define L List_T


L List_init(void)
{
    L list;
    list = (L)malloc(sizeof(L));
    list->next = NULL;
    return list;
}


L List_push(L list, void *val)
{
    L new_elem = (L)malloc(sizeof(L));
    new_elem->val = val;
    new_elem->next = list;
    return new_elem;
}


int List_length(L list)
{
    int n;
    for (n = 0; list; list = list->next) n++;
    return n - 1;
}


void **List_toArray(L list)
{
    int i, n = List_length(list) + 1;
    void **array = (void **)malloc((n + 1) * sizeof(*array));

    for (i = 0; i < n; i++)
    {
        array[i] = list->val;
        list = list->next;
    }
    array[i] = NULL;
    return array;
}


L List_list(L list, void *val, ...)
{
    va_list ap;
    L *p = &list;

    va_start(ap, val);
    for (; val; val = va_arg(ap, void *))
    {
        *p = malloc(sizeof(L));
        (*p)->val = val;
        p = &(*p)->next;
    }
    *p = NULL;
    va_end(ap);
    return list;
}


L List_append(L list, L tail)
{
    L *p = &list;
    while ((*p)->next)
    {
        p = &(*p)->next;
    }

    *p = tail;
    return list;
}
