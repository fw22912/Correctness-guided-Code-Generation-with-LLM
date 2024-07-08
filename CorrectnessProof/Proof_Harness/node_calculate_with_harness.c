#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Node
{
    int data;
    struct Node *llink;
    struct Node *rlink;
} node;


node *create_node(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->rlink = ptr->llink = NULL;
    ptr->data = data;
    return ptr;
}


void insert_bt(node **root, int data)
{
    node *new_node = create_node(data);
    node *temp;      node *prev;      if (*root == NULL)
    {
        *root = new_node;
    }
    else
    {
        temp = *root;
        prev = NULL;
        while (temp != NULL)
        {
            if (new_node->data > temp->data)
            {
                prev = temp;
                temp = temp->rlink;
            }
            else if (new_node->data < temp->data)
            {
                prev = temp;
                temp = temp->llink;
            }
            else
            {
                return;
            }
        }

        if (new_node->data > prev->data)
        {
            prev->rlink = new_node;
        }
        else
        {
            prev->llink = new_node;
        }
    }
}


void search(node *root, int ele)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == ele)
        {
            break;
        }
        else if (ele > temp->data)
        {
            temp = temp->rlink;
        }
        else
        {
            temp = temp->llink;
        }
    }

    if (temp == NULL)
    {
        printf("%s\n", "Element not found.");
    }
    else
        printf("%s\n", "Element found.");
}


void inorder_display(node *curr)
{
    if (curr != NULL)
    {
        inorder_display(curr->llink);
        printf("%d\t", curr->data);
        inorder_display(curr->rlink);
    }
}


void postorder_display(node *curr)
{
    if (curr != NULL)
    {
        postorder_display(curr->llink);
        postorder_display(curr->rlink);
        printf("%d\t", curr->data);
    }
}


void preorder_display(node *curr)
{
    if (curr != NULL)
    {
        printf("%d\t", curr->data);
        preorder_display(curr->llink);
        preorder_display(curr->rlink);
    }
}


void delete_bt(node **root, int ele)
{
    node *temp;
    node *prev;
    if (*root == NULL)
        return;
    else
    {
        temp = *root;
        prev = NULL;
                while (temp != NULL)
        {
            if (temp->data == ele)
            {
                break;
            }
            else if (ele > temp->data)
            {
                prev = temp;
                temp = temp->rlink;
            }
            else
            {
                prev = temp;
                temp = temp->llink;
            }
        }
    }

    if (temp == NULL)
        return;
    else
    {
        node *replacement;          node *t;
        if (temp->llink == NULL && temp->rlink == NULL)
        {
            replacement = NULL;
        }
        else if (temp->llink == NULL && temp->rlink != NULL)
        {
            replacement = temp->rlink;
        }
        else if (temp->llink != NULL && temp->rlink == NULL)
        {
            replacement = temp->llink;
        }
        else
        {
            replacement = temp->rlink;              t = replacement;
            while (t->llink != NULL)
            {
                t = t->llink;
            }
            t->llink =
                temp->llink;                                        }

        if (temp == *root)
        {
            free(*root);
            *root = replacement;
        }
        else if (prev->llink == temp)
        {
            free(prev->llink);
            prev->llink = replacement;
        }
        else if (prev->rlink == temp)
        {
            free(prev->rlink);
            prev->rlink = replacement;
        }
    }
}


int main()
{
    printf("BINARY THREADED TREE: \n");
    node *root = NULL;
    int choice, n;
    do
    {
        printf("%s\n", "1. Insert into BT");
        printf("%s\n", "2. Print BT - inorder");
        printf("%s\n", "3. Print BT - preorder");
        printf("%s\n", "4. print BT - postorder");
        printf("%s\n", "5. delete from BT");
        printf("%s\n", "6. search in BT");
        printf("%s\n", "Type 0 to exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("%s\n", "Enter a no:");
            scanf("%d", &n);
            insert_bt(&root, n);
            break;
        case 2:
            inorder_display(root);
            printf("\n");
            break;
        case 3:
            preorder_display(root);
            printf("\n");
            break;
        case 4:
            postorder_display(root);
            printf("\n");
            break;
        case 5:
            printf("%s\n", "Enter a no:");
            scanf("%d", &n);
            delete_bt(&root, n);
            break;
        case 6:
            printf("%s\n", "Enter a no:");
            scanf("%d", &n);
            search(root, n);
            break;
        }
    } while (choice != 0);
    return 0;
}

void proof_harness_create_node() {
    int data;
    __CPROVER_assume(data >= 0 && data <= 2147483647);
    node *ptr = create_node(data);
    assert(ptr != NULL);
    assert(ptr->data == data);
    assert(ptr->llink == NULL);
    assert(ptr->rlink == NULL);
    free(ptr);
}

void proof_harness_insert_bt() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0 && data <= 2147483647);
    insert_bt(&root, data);
    assert(root != NULL);
    assert(root->data == data);
    assert(root->llink == NULL);
    assert(root->rlink == NULL);
    free(root);
}

void proof_harness_search() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0 && data <= 2147483647);
    insert_bt(&root, data);
    int ele;
    __CPROVER_assume(ele >= 0 && ele <= 2147483647);
    search(root, ele);
    free(root);
}

void proof_harness_inorder_display() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0 && data <= 2147483647);
    insert_bt(&root, data);
    inorder_display(root);
    free(root);
}

void proof_harness_postorder_display() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0 && data <= 2147483647);
    insert_bt(&root, data);
    postorder_display(root);
    free(root);
}

void proof_harness_preorder_display() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0 && data <= 2147483647);
    insert_bt(&root, data);
    preorder_display(root);
    free(root);
}

void proof_harness_delete_bt() {
    node *root = NULL;
    int data;
    __CPROVER_assume(data >= 0 && data <= 2147483647);
    insert_bt(&root, data);
    int ele;
    __CPROVER_assume(ele >= 0 && ele <= 2147483647);
    delete_bt(&root, ele);
    free(root);
}