
 
#include <stdio.h>	
#include <string.h>	
#include <ctype.h>	
#include <stdlib.h>	
#include <stdint.h>	
#include <assert.h>	


struct Stack {
	char stack[10];		
	int top;		
};
struct Stack st;		


void push(char opd) {
	if(st.top == 9)	{		
		printf("Stack overflow...");
		exit(1);
	}
	st.top++;
	st.stack[st.top] = opd;
}


char pop() {
	char item;				
	if(st.top == -1) {		
		printf("Stack underflow...");
		exit(1);
	}
	item = st.stack[st.top];
	st.top--;
	return item;
}


uint16_t isEmpty() {
	if(st.top == -1) {
		return 1;
	}
	return 0;
}


char Top() {
	return st.stack[st.top];
}


int16_t priority(char opr) {
	if(opr == '+' || opr == '-') {
		return 0;
	}
	else if(opr == '/' || opr == '*' || opr == '%') {
		return 1;
	}
	else {
		return -1;
	}
}


char *convert(char inf[]) {
	static char post[25];				
	int i;								
	int j = 0;							
	for(i = 0; i < strlen(inf); i++) {
		if(isalnum(inf[i]))	{			
			post[j] = inf[i];			
			j++;
		}
		else if(inf[i] == '(') {		
			push(inf[i]);				
		}
		else if(inf[i] == ')') {		
			while(Top() != '(') {		
				post[j] = pop();		
				j++;
			}
			pop();						
		}
		else {							
			while( (!isEmpty()) && (priority(inf[i]) <= priority(Top())) ) {	
				post[j] = pop();												
				j++;															
			}																	
			push(inf[i]);				
		}
	}
	while(!isEmpty()) {					
		post[j] = pop();
		j++;
	}
	post[j] = '\0';						
	return post;
}


static void test() {
    
	assert(strcmp(convert("(A/(B-C)*D+E)"), "ABC-/D*E+") == 0); 			
	
	assert(strcmp(convert("7-(2*3+5)*(8-4/2)"), "723*5+842/-*-") == 0); 			
	printf("All tests have successfully passed!\n");
}


int main() {
	st.top = -1;			
	test();				
	char inf[25];			
	printf("Enter infix: ");
	scanf("%s", inf);
	printf("Postfix: %s", convert(inf));
	return 0;
}
