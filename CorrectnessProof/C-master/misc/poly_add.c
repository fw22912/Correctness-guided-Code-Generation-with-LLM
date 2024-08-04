
#include <stdio.h>  
#include <stdlib.h>


struct term
{
    int coef;          
    int pow;           
    struct term *next; 
};


void free_poly(struct term *poly)
{
    while (poly)
    {
        struct term *next = poly->next;
        free(poly);
        poly = next;
    }
}


void create_polynomial(struct term **poly, int coef, int pow)
{
    
    struct term **temp1 = poly;

    while (*temp1)
    {
        temp1 = &(*temp1)->next;
    }

    
    *temp1 = (struct term *)malloc(
        sizeof(struct term));  
    (*temp1)->coef = coef;
    (*temp1)->pow = pow;
    (*temp1)->next = NULL;
}



void poly_add(struct term **pol, struct term *poly1, struct term *poly2)
{
    
    struct term *temp = (struct term *)malloc(sizeof(struct term));
    temp->next = NULL;
    *pol =
        temp;  /
        if (poly1->pow > poly2->pow)
        {
            temp->coef = poly1->coef;
            temp->pow = poly1->pow;
            poly1 = poly1->next;
        }
        
        else if (poly1->pow < poly2->pow)
        {
            temp->coef = poly2->coef;
            temp->pow = poly2->pow;
            poly2 = poly2->next;
        }
        
        else
        {
            temp->coef = poly1->coef + poly2->coef;
            temp->pow = poly1->pow;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
        if (poly1 && poly2)
        {
            temp->next = (struct term *)malloc(
                sizeof(struct term));  
            temp = temp->next;         
            temp->next = NULL;
        }
    }
    
    while (poly1 || poly2)
    {
        temp->next = (struct term *)malloc(
            sizeof(struct term));  
        temp = temp->next;         
        temp->next = NULL;

        
        if (poly1)
        {
            temp->coef = poly1->coef;
            temp->pow = poly1->pow;
            poly1 = poly1->next;
        }
        
        else if (poly2)
        {
            temp->coef = poly2->coef;
            temp->pow = poly2->pow;
            poly2 = poly2->next;
        }
    }
}


void display_polynomial(struct term *poly)
{
    while (poly != NULL)
    {
        printf("%d x^%d", poly->coef, poly->pow);
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
        }
    }
}


static void test1(struct term *poly1, struct term *poly2, struct term *poly3)
{
    printf("\n----Test 1----\n");
    printf("\nFirst Polynomial:\n");  
    create_polynomial(&poly1, 5, 2);
    create_polynomial(&poly1, 3, 1);
    create_polynomial(&poly1, 2, 0);
    display_polynomial(poly1);

    printf("\nSecond Polynomial:\n");  
    create_polynomial(&poly2, 7, 3);
    create_polynomial(&poly2, 9, 1);
    create_polynomial(&poly2, 10, 0);
    display_polynomial(poly2);

    poly_add(&poly3, poly1, poly2);  
    printf("\nResultant polynomial:\n");
    display_polynomial(poly3);
    printf("\n");

    
    free_poly(poly1);
    free_poly(poly2);
    free_poly(poly3);
}


static void test2(struct term *poly1, struct term *poly2, struct term *poly3)
{
    printf("\n----Test 2----\n");
    printf("\nFirst Polynomial:\n");  
    create_polynomial(&poly1, 3, 5);
    create_polynomial(&poly1, 1, 4);
    create_polynomial(&poly1, 2, 3);
    create_polynomial(&poly1, -2, 1);
    create_polynomial(&poly1, 5, 0);

    display_polynomial(poly1);

    printf("\nSecond Polynomial:\n");  
    create_polynomial(&poly2, 2, 5);
    create_polynomial(&poly2, 3, 3);
    create_polynomial(&poly2, 7, 1);
    create_polynomial(&poly2, 2, 0);

    display_polynomial(poly2);

    poly_add(&poly3, poly1, poly2);  
    printf("\nResultant polynomial:\n");
    display_polynomial(poly3);
    printf("\n");

    
    free_poly(poly1);
    free_poly(poly2);
    free_poly(poly3);
}


static void test3(struct term *poly1, struct term *poly2, struct term *poly3)
{
    printf("\n----Test 3----\n");
    printf("\nFirst Polynomial:\n");  
    create_polynomial(&poly1, -12, 0);
    create_polynomial(&poly1, 8, 1);
    create_polynomial(&poly1, 4, 3);

    display_polynomial(poly1);

    printf("\nSecond Polynomial:\n");  
    create_polynomial(&poly2, 5, 0);
    create_polynomial(&poly2, -13, 1);
    create_polynomial(&poly2, 3, 3);

    display_polynomial(poly2);

    poly_add(&poly3, poly1, poly2);  
    printf("\nResultant polynomial:\n");
    display_polynomial(poly3);
    printf("\n");

    
    free_poly(poly1);
    free_poly(poly2);
    free_poly(poly3);
}


int main(void)
{
    struct term *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    test1(poly1, poly2, poly3);
    test2(poly1, poly2, poly3);
    test3(poly1, poly2, poly3);

    return 0;
}
