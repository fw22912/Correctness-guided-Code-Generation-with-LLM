
#include <assert.h>   
#include <stdbool.h>  
#include <stdio.h>    
#include <stdlib.h>  

 typedef struct node {
     int ID;             
     int AT;             
     int BT;             
     int priority;       
     int CT;             
     int WT;             
     int TAT;            
     struct node *next;  
 } node;


void insert(node **root, int id, int at, int bt, int prior)
{
    
    node *new = (node *)malloc(sizeof(node));
    node *ptr = *root;
    new->ID = id;
    new->AT = at;
    new->BT = bt;
    new->priority = prior;
    new->next = NULL;
    new->CT = 0;
    new->WT = 0;
    new->TAT = 0;
    
    if (*root == NULL)
    {
        *root = new;
        return;
    }
    
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    return;
}

void delete(node **root, int id)
{
    node *ptr = *root, *prev;
    
    if (ptr == NULL)
    {
        return;
    }
    
    if (ptr->ID == id)
    {
        *root = ptr->next;
        free(ptr);
        return;
    }
    
    while (ptr != NULL && ptr->ID != id)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        return;
    }
    prev->next = ptr->next;
    free(ptr);
}

void show_list(node *head)
{
    printf("Process Priority AT BT CT TAT WT \n");
    while (head != NULL)
    {
        printf("P%d. %d %d %d %d %d %d \n", head->ID, head->priority, head->AT,
               head->BT, head->CT, head->TAT, head->WT);
        head = head->next;
    }
}

int l_length(node **root)
{
    int count = 0;
    node *ptr = *root;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void update(node **root, int id, int ct, int wt, int tat)
{
    node *ptr = *root;
    
    if (ptr != NULL && ptr->ID == id)
    {
        if (ct != 0)
        {
            ptr->CT = ct;
        }
        if (wt != 0)
        {
            ptr->WT = wt;
        }
        if (tat != 0)
        {
            ptr->TAT = tat;
        }
        return;
    }
    
    while (ptr != NULL && ptr->ID != id)
    {
        ptr = ptr->next;
    }
    if (ct != 0)
    {
        ptr->CT = ct;
    }
    if (wt != 0)
    {
        ptr->WT = wt;
    }
    if (tat != 0)
    {
        ptr->TAT = tat;
    }
    return;
}

bool compare(node *a, node *b)
{
    if (a->AT == b->AT)
    {
        return a->priority < b->priority;
    }
    else
    {
        return a->AT < b->AT;
    }
}

float calculate_ct(node **root)
{
    
    node *ptr = *root, *prior, *rpt;
    int ct = 0, i, time = 0;
    int n = l_length(root);
    float avg, sum = 0;
    node *duproot = NULL;
    
    while (ptr != NULL)
    {
        insert(&duproot, ptr->ID, ptr->AT, ptr->BT, ptr->priority);
        ptr = ptr->next;
    }
    ptr = duproot;
    rpt = ptr->next;
    
    while (rpt != NULL)
    {
        if (!compare(ptr, rpt))
        {
            ptr = rpt;
        }
        rpt = rpt->next;
    }
    
    ct = ptr->AT + ptr->BT;
    time = ct;
    sum += ct;
    
    
    update(root, ptr->ID, ct, 0, 0);
    delete (&duproot, ptr->ID);
    
    for (i = 0; i < n - 1; i++)
    {
        ptr = duproot;
        while (ptr != NULL && ptr->AT > time)
        {
            ptr = ptr->next;
        }
        rpt = ptr->next;
        while (rpt != NULL)
        {
            if (rpt->AT <= time)
            {
                if (rpt->priority < ptr->priority)
                {
                    ptr = rpt;
                }
            }
            rpt = rpt->next;
        }
        ct += ptr->BT;
        time += ptr->BT;
        sum += ct;
        update(root, ptr->ID, ct, 0, 0);
        delete (&duproot, ptr->ID);
    }
    avg = sum / n;
    return avg;
}

float calculate_tat(node **root)
{
    float avg, sum = 0;
    int n = l_length(root);
    node *ptr = *root;
    
    if (ptr->CT == 0)
    {
        calculate_ct(root);
    }
    
    while (ptr != NULL)
    {
        ptr->TAT = ptr->CT - ptr->AT;
        sum += ptr->TAT;
        ptr = ptr->next;
    }
    avg = sum / n;
    return avg;
}

float calculate_wt(node **root)
{
    float avg, sum = 0;
    int n = l_length(root);
    node *ptr = *root;
    
    if (ptr->CT == 0)
    {
        calculate_ct(root);
    }
    
    while (ptr != NULL)
    {
        ptr->WT = (ptr->TAT - ptr->BT);
        sum += ptr->WT;
        ptr = ptr->next;
    }
    avg = sum / n;
    return avg;
}


static void test()
{
    
    
    
    
    
    
    

    node *root = NULL;
    insert(&root, 1, 0, 5, 1);
    insert(&root, 2, 1, 4, 2);
    insert(&root, 3, 2, 3, 3);
    insert(&root, 4, 3, 2, 4);
    insert(&root, 5, 4, 1, 5);
    float avgCT = calculate_ct(&root);
    float avgTAT = calculate_tat(&root);
    float avgWT = calculate_wt(&root);
    assert(avgCT == 11);
    assert(avgTAT == 9);
    assert(avgWT == 6);
    printf("[+] All tests have successfully passed!\n");
    
    
    
}


int main()
{
    test();  

    return 0;
}
