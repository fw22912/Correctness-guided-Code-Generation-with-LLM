

#include <assert.h>  
#include <inttypes.h>  
#include <stdio.h>     
#include <stdlib.h>  


typedef struct node
{
    struct node *prev, *next;  
    uint64_t value;            
} ListNode;


ListNode *create_node(uint64_t data)
{
    ListNode *new_list = (ListNode *)malloc(sizeof(ListNode));
    new_list->value = data;
    new_list->next = new_list;
    new_list->prev = new_list;
    return new_list;
}


ListNode *insert_at_head(ListNode *head, uint64_t data)
{
    if (head == NULL)
    {
        head = create_node(data);
        return head;
    }
    else
    {
        ListNode *temp;
        ListNode *new_node = create_node(data);
        temp = head->prev;
        new_node->next = head;
        head->prev = new_node;
        new_node->prev = temp;
        temp->next = new_node;
        head = new_node;
        return head;
    }
}


ListNode *insert_at_tail(ListNode *head, uint64_t data)
{
    if (head == NULL)
    {
        head = create_node(data);
        return head;
    }
    else
    {
        ListNode *temp1, *temp2;
        ListNode *new_node = create_node(data);
        temp1 = head;
        temp2 = head->prev;
        new_node->prev = temp2;
        new_node->next = temp1;
        temp1->prev = new_node;
        temp2->next = new_node;
        return head;
    }
}


ListNode *delete_from_head(ListNode *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }
    ListNode *temp1, *temp2;
    temp1 = head;
    temp2 = temp1->prev;
    if (temp1 == temp2)
    {
        free(temp2);
        head = NULL;
        return head;
    }
    temp2->next = temp1->next;
    (temp1->next)->prev = temp2;
    head = temp1->next;
    free(temp1);
    return head;
}


ListNode *delete_from_tail(ListNode *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    ListNode *temp1, *temp2;
    temp1 = head;
    temp2 = temp1->prev;
    if (temp1 == temp2)
    {
        free(temp2);
        head = NULL;
        return head;
    }
    (temp2->prev)->next = temp1;
    temp1->prev = temp2->prev;
    free(temp2);
    return head;
}


int getsize(ListNode *head)
{
    if (!head)
    {
        return 0;
    }
    int size = 1;
    ListNode *temp = head->next;
    while (temp != head)
    {
        temp = temp->next;
        size++;
    }
    return size;
}



void display_list(ListNode *head)
{
    printf("\nContents of your linked list: ");
    ListNode *temp;
    temp = head;
    if (head != NULL)
    {
        while (temp->next != head)
        {
            printf("%" PRIu64 " <-> ", temp->value);
            temp = temp->next;
        }
        if (temp->next == head)
        {
            printf("%" PRIu64, temp->value);
        }
    }
    else
    {
        printf("The list is empty");
    }
    printf("\n");
}


uint64_t get(ListNode *list, const int index)
{
    if (list == NULL || index < 0)
    {
        exit(EXIT_FAILURE);
    }
    ListNode *temp = list;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->value;
}


static void test()
{
    ListNode *testList = NULL;
    unsigned int array[] = {2, 3, 4, 5, 6};

    assert(getsize(testList) == 0);

    printf("Testing inserting elements:\n");
    for (int i = 0; i < 5; ++i)
    {
        display_list(testList);
        testList = insert_at_head(testList, array[i]);
        assert(testList->value == array[i]);
        assert(getsize(testList) == i + 1);
    }

    printf("\nTesting removing elements:\n");
    for (int i = 4; i > -1; --i)
    {
        display_list(testList);
        assert(testList->value == array[i]);
        testList = delete_from_head(testList);
        assert(getsize(testList) == i);
    }

    printf("\nTesting inserting at tail:\n");
    for (int i = 0; i < 5; ++i)
    {
        display_list(testList);
        testList = insert_at_tail(testList, array[i]);
        assert(get(testList, i) == array[i]);
        assert(getsize(testList) == i + 1);
    }

    printf("\nTesting removing from tail:\n");
    for (int i = 4; i > -1; --i)
    {
        display_list(testList);
        testList = delete_from_tail(testList);
        assert(getsize(testList) == i);
        
        
        if (testList != NULL)
        {
            assert(get(testList, i) == testList->value);
        }
        else
        {
            
            
            assert(i == 0);
        }
    }
}


int main()
{
    test();  
    return 0;
}
