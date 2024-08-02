


#include <stdio.h>  


struct Stack
{
    char arr[10];  
    int tos;       
};


void push(struct Stack *p, char ch);  
char pop(struct Stack *p);            
int isOprnd(char ch);                 
int isEmpty(struct Stack s);          
int getPrecedence (char op1, char op2);        
void convert(char infix[],
             char postfix[]);  


int main()
{
    char infix[20], postfix[20];  

    printf("Enter infix expression: ");  
    scanf("%s", infix);                  

    convert(infix, postfix);
    printf("Postfix expression is %s", postfix);  

    return 0;
}


void push(struct Stack *p, char x)
{
    if (p->tos == 9)  
    {
        printf("Stack Overflow!");
        return;
    }

    p->tos += 1;         
    p->arr[p->tos] = x;  
}


char pop(struct Stack *p)
{
    char x;

    if (p->tos == -1)
    {
        printf("Stack Underflow!");
        return '\0';
    }

    x = p->arr[p->tos];  
    p->tos -= 1;         

    return x;
}


int isOprnd(char ch)
{
    if ((ch >= 65 && ch <= 90) ||
        (ch >= 97 && ch <= 122) ||  
        (ch >= 48 && ch <= 57))     
    {
        return 1;  
    }
    else
    {
        return 0;  
    }
}


int isEmpty(struct Stack s)
{
    if (s.tos == -1)  
    {
        return 1;  
    }
    else
    {
        return 0;  
    }
}


void convert(char infix[], char postfix[])
{
    struct Stack s;  
    s.tos = -1;      

    int i, j = 0, pr;
    char ch, temp;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isOprnd(ch) == 1)  
        {
            postfix[j] = ch;  
            j++;              
        }
        else
        {
            if (ch == '(')
            {
                push(&s, ch);
            }
            else
            {
                if (ch == ')')
                {
                    while ((temp = pop(&s)) != '(')
                    {
                        postfix[j] = temp;
                        j++;
                    }
                }
                else
                {
                    while (isEmpty(s) == 0)  
                    {
                        pr = getPrecedence (ch,
                                   s.arr[s.tos]);  

                        if (pr == 1)
                        {
                            break;  
                                    
                        }

                        postfix[j] = pop(&s);
                        j++;
                    }

                    push(&s, ch);  
                }
            }
        }
    }

    while (isEmpty(s) == 0)  
    {
        postfix[j] = pop(&s);
        j++;
    }

    postfix[j] = '\0';
}


int getPrecedence (char op1, char op2)
{
    if (op2 == '$')
    {
        return 0;
    }
    else if (op1 == '$')
    {
        return 1;
    }
    else if (op2 == '*' || op2 == '/' || op2 == '%')
    {
        return 0;
    }
    else if (op1 == '*' || op1 == '/' || op1 == '%')
    {
        return 1;
    }
    else if (op2 == '+' || op2 == '-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
