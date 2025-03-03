#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define NULL ((void *)0)

struct node
{
    int data;
    struct node *next;
};

struct node *front, *rear;

/* This function initializes the queue to empty by making both front and rear as
 * NULL */
void createqueue() { front = rear = NULL; }

int empty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void insert(int x)
{
    struct node *pnode;

    pnode = (struct node *)malloc(sizeof(struct node));
    if (pnode == NULL)
    {
        printf("Memory overflow. Unable to insert.\n");
        exit(1);
    }

    pnode->data = x;
    pnode->next = NULL; /* New node is always last node */

    if (empty())
        front = rear = pnode;
    else
    {
        rear->next = pnode;
        rear = pnode;
    }
}

int removes()
{
    int min;
    struct node *follow, *follow1, *p, *p1;

    if (empty())
    {
        printf("\nQueue Underflow. Unable to remove.");
        exit(1);
    }

    /* finding the node with minimum value in the APQ.*/
    p = p1 = front;
    follow = follow1 = NULL;
    min = front->data;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
            follow1 = follow;
            p1 = p;
        }
        follow = p;
        p = p->next;
    }

    /* Deleting the node with min value */

    if (p1 == front) /* deleting first node.*/
    {
        front = front->next;
        if (front == NULL) /* Deleting the only one node */
            rear = NULL;
    }
    else if (p1 == rear) /* Deleting last node */
    {
        rear = follow1;
        rear->next = NULL;
    }
    else /* deleting any other node.*/
        follow1->next = p1->next;

    free(p1);
    return min; /* DONT FORGET LAST 2 STATEMENTS.*/
}

void show()
{
    struct node *p;

    if (empty())
        printf("Queue empty. No data to display \n");
    else
    {
        printf("Queue from front to rear is as shown: \n");

        p = front;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }

        printf("\n");
    }
}

void destroyqueue() { front = rear = NULL; }

int main()
{
    int x, ch;

    createqueue();

    do
    {
        printf("\n\n  Menu: \n");
        printf("1:Insert \n");
        printf("2:Remove \n");
        printf("3:exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%d", &x);
            insert(x);
            show();
            break;

        case 2:
            x = removes();
            printf("Element removed is: %d\n", x);
            show();
            break;

        case 3:
            break;
        }
    } while (ch != 3);

    destroyqueue();

    return 0;
}

/* Output of the Program*/

/*
  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 12
Queue from front to rear is as shown:
12


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 1
Queue from front to rear is as shown:
12 1


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 14
Queue from front to rear is as shown:
12 1 14


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 3
Queue from front to rear is as shown:
12 1 14 3


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 5
Queue from front to rear is as shown:
12 1 14 3 5


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 1
Queue from front to rear is as shown:
12 14 3 5


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 3
Queue from front to rear is as shown:
12 14 5


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 5
Queue from front to rear is as shown:
12 14


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 12
Queue from front to rear is as shown:
14


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 14
Queue empty. No data to display

*/

void proof_harness_createqueue() {
    createqueue();
    assert(front == NULL);
    assert(rear == NULL);
}

void proof_harness_empty() {
    createqueue();
    assert(empty() == 1);
    insert(1);
    assert(empty() == 0);
}

void proof_harness_insert() {
    createqueue();
    insert(1);
    assert(front->data == 1);
    assert(rear->data == 1);
    assert(front->next == NULL);
    insert(2);
    assert(front->data == 1);
    assert(rear->data == 2);
    assert(front->next->data == 2);
    assert(front->next->next == NULL);
}

void proof_harness_removes() {
    createqueue();
    insert(1);
    assert(removes() == 1);
    assert(front == NULL);
    assert(rear == NULL);
    insert(1);
    insert(2);
    assert(removes() == 1);
    assert(front->data == 2);
    assert(rear->data == 2);
    assert(front->next == NULL);
    insert(3);
    assert(removes() == 2);
    assert(front->data == 3);
    assert(rear->data == 3);
    assert(front->next == NULL);
}

void proof_harness_show() {
    createqueue();
    show();
    insert(1);
    show();
}

void proof_harness_destroyqueue() {
    createqueue();
    destroyqueue();
    assert(front == NULL);
    assert(rear == NULL);
}