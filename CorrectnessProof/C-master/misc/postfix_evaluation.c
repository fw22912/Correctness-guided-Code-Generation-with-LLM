
 
#include <stdio.h>	
#include <string.h>	
#include <ctype.h>	
#include <stdlib.h>	
#include <stdint.h>	
#include <assert.h>	


struct Stack {
	int8_t stack[20];		
	int top;		
};
struct Stack st;		


void push(int8_t opd) {
	if(st.top == 19)	{		
		printf("Stack overflow...");
		exit(1);
	}
	st.top++;
	st.stack[st.top] = opd;
}


int8_t pop() {
	int8_t item;				
	if(st.top == -1) {		
		printf("Stack underflow...");
		exit(1);
	}
	item = st.stack[st.top];
	st.top--;
	return item;
}


int8_t evaluate(char post[]) {
	int8_t it1;
	int8_t it2;
	int8_t temp;
	int8_t number;
    int i;
    for(i = 0; i < strlen(post); i++) {
		if(post[i] == ' ') {
			continue;			
		}
		else if(isdigit(post[i])) {
			number = 0;
			do {
				number = number * 10 + (post[i]-'0');
				i++;
			} while(i < strlen(post) && isdigit(post[i]));
			push(number);
		}
		else {
			it2 = pop();
			it1 = pop();
			switch(post[i]) {
				case '+':
				temp = it1 + it2; break;
				case '-':
				temp = it1 - it2; break;
				case '*':
				temp = it1 * it2; break;
				case '/':
				temp = it1 / it2; break;
				case '%':
				temp = it1 % it2; break;
				default:
				printf("Invalid operator"); exit(1);
			}
			push(temp);
		}
	}
	return pop();
}


static void test() {
    
	char temp1[50] = "2 10 + 9 6 - /";
	assert(evaluate(temp1) == 4); 			
	
	char temp2[50] = "4 2 + 3 5 1 - * +";
	assert(evaluate(temp2) == 18); 			
	printf("All tests have successfully passed!\n");
}


int main() {
	st.top = -1;			
	test();				
	return 0;
}
