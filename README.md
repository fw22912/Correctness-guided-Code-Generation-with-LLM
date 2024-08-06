# Correctness-guided-Code-Generation-with-LLM
A respository for 'Correctness-guided Code Generation with LLM' from University of Bristol.

Bellow is an example of a prompt used for Gemini to generate code based on counter examples:


     # Preamble
    You are given the original C code file, previous output, and the counter examples. Your job is to improve the 
    incorrect methods only based on the provided counter examples.
    
    #Original C code:




#include <stdio.h>
#include <stdlib.h>







struct node
{
    int data;
    struct node *next;
    struct node *pre;
} * head, *tmp;



int count = 0;



void create();
void push(int x);
int pop();
int peek();
int size();
int isEmpty();




int main(int argc, char const *argv[])
{
    int x, y, z;

    create();
    push(4);
    x = pop();
    
    printf("%d.\t\tCount: %d.\tEmpty: %d.\n", x, size(), isEmpty());

    push(1);
    push(2);
    push(3);
    x = pop();
    y = pop();
    
    printf("%d, %d.\t\tCount: %d.\tEmpty: %d.\n", x, y, size(), isEmpty());
    pop();  

    push(5);
    push(6);
    x = peek();
    push(7);
    y = pop();
    push(8);
    z = pop();
    
    printf("%d, %d, %d.\tCount: %d.\tEmpty: %d.\n", x, y, z, size(), isEmpty());

    return 0;
}


void create() { head = NULL; }


void push(int x)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(1 * sizeof(struct node));
        head->next = NULL;
        head->pre = NULL;
        head->data = x;
    }
    else
    {
        tmp = (struct node *)malloc(1 * sizeof(struct node));
        tmp->data = x;
        tmp->next = NULL;
        tmp->pre = head;
        head->next = tmp;
        head = tmp;
    }
    ++count;
}


int pop()
{
    int returnData;
    if (head == NULL)
    {
        printf("ERROR: Pop from empty stack.\n");
        exit(1);
    }
    else
    {
        returnData = head->data;

        if (head->pre == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            head = head->pre;
            free(head->next);
        }
    }
    --count;
    return returnData;
}


int peek()
{
    if (head != NULL)
        return head->data;
    else
    {
        printf("ERROR: Peeking from empty stack.");
        exit(1);
    }
}


int size() { return count; }


int isEmpty()
{
    if (count == 0)
        return 1;
    return 0;
}

    
    #Assistant's previous response:
1: #include <stdio.h>
2: #include <stdlib.h>
3: #include <assert.h>
4: #include <stdbool.h>
5: 
6: 
7: 
8: 
9: 
10: 
11: 
12: struct node
13: {
14:     int data;
15:     struct node *next;
16:     struct node *pre;
17: } * head, *tmp;
18: 
19: 
20: 
21: int count = 0;
22: 
23: 
24: 
25: void create();
26: void push(int x);
27: int pop();
28: int peek();
29: int size();
30: int isEmpty();
31: 
32: 
33: 
34: 
35: int main(int argc, char const *argv[])
36: {
37:     int x, y, z;
38: 
39:     create();
40:     push(4);
41:     x = pop();
42:     
43:     printf("%d.\t\tCount: %d.\tEmpty: %d.\n", x, size(), isEmpty());
44: 
45:     push(1);
46:     push(2);
47:     push(3);
48:     x = pop();
49:     y = pop();
50:     
51:     printf("%d, %d.\t\tCount: %d.\tEmpty: %d.\n", x, y, size(), isEmpty());
52:     pop();  
53: 
54:     push(5);
55:     push(6);
56:     x = peek();
57:     push(7);
58:     y = pop();
59:     push(8);
60:     z = pop();
61:     
62:     printf("%d, %d, %d.\tCount: %d.\tEmpty: %d.\n", x, y, z, size(), isEmpty());
63: 
64:     return 0;
65: }
66: 
67: 
68: void create() { head = NULL; }
69: 
70: 
71: void push(int x)
72: {
73:     if (head == NULL)
74:     {
75:         head = (struct node *)malloc(1 * sizeof(struct node));
76:         head->next = NULL;
77:         head->pre = NULL;
78:         head->data = x;
79:     }
80:     else
81:     {
82:         tmp = (struct node *)malloc(1 * sizeof(struct node));
83:         tmp->data = x;
84:         tmp->next = NULL;
85:         tmp->pre = head;
86:         head->next = tmp;
87:         head = tmp;
88:     }
89:     ++count;
90: }
91: 
92: 
93: int pop()
94: {
95:     int returnData;
96:     if (head == NULL)
97:     {
98:         printf("ERROR: Pop from empty stack.\n");
99:         exit(1);
100:     }
101:     else
102:     {
103:         returnData = head->data;
104: 
105:         if (head->pre == NULL)
106:         {
107:             free(head);
108:             head = NULL;
109:         }
110:         else
111:         {
112:             head = head->pre;
113:             free(head->next);
114:         }
115:     }
116:     --count;
117:     return returnData;
118: }
119: 
120: 
121: int peek()
122: {
123:     if (head != NULL)
124:         return head->data;
125:     else
126:     {
127:         printf("ERROR: Peeking from empty stack.");
128:         exit(1);
129:     }
130: }
131: 
132: 
133: int size() { return count; }
134: 
135: 
136: int isEmpty()
137: {
138:     if (count == 0)
139:         return 1;
140:     return 0;
141: }
142: 
143:     
144:     void proof_harness_create() {
145:         create();
146:         assert(head == NULL);
147:     }
148:     
149:     
150:     void proof_harness_push() {
151:         struct node *tmp_node;
152:         int x;
153:         
154:         __CPROVER_assume(x >= 0);
155:         
156:         create();
157:         
158:         push(x);
159:         if (head != NULL) {
160:             assert(head->data == x);
161:             assert(head->next == NULL);
162:             assert(head->pre == NULL);
163:             tmp_node = head;
164:         } else {
165:             assert(head == NULL);
166:         }
167:         
168:         __CPROVER_assume(x >= 0);
169:         
170:         push(x);
171:         if (head != NULL) {
172:             assert(head->data == x);
173:             assert(head->next == NULL);
174:             assert(head->pre == tmp_node);
175:             tmp_node = head;
176:         } else {
177:             assert(head == NULL);
178:         }
179:     }
180:     
181:     
182:     void proof_harness_pop() {
183:         int x;
184:         int popped;
185:         struct node *tmp_node;
186:         create();
187:         
188:         __CPROVER_assume(x >= 0);
189:         push(x);
190:         
191:         popped = pop();
192:         assert(popped == x);
193:         
194:         if (head != NULL) {
195:             assert(head->data == x);
196:             assert(head->next == NULL);
197:             assert(head->pre == NULL);
198:             tmp_node = head;
199:         } else {
200:             assert(head == NULL);
201:         }
202:         __CPROVER_assume(x >= 0);
203:         push(x);
204:         
205:         popped = pop();
206:         assert(popped == x);
207:         
208:         if (head != NULL) {
209:             assert(head->data == x);
210:             assert(head->next == NULL);
211:             assert(head->pre == NULL);
212:             tmp_node = head;
213:         } else {
214:             assert(head == NULL);
215:         }
216:     }
217:     
218:     
219:     void proof_harness_peek() {
220:         int x;
221:         int peeked;
222:         create();
223:         
224:         __CPROVER_assume(x >= 0);
225:         push(x);
226:         peeked = peek();
227:         assert(peeked == x);
228:         
229:         __CPROVER_assume(x >= 0);
230:         push(x);
231:         peeked = peek();
232:         assert(peeked == x);
233:     }
234:     
235:     
236:     void proof_harness_size() {
237:         create();
238:         assert(size() == 0);
239:         
240:         push(42);
241:         assert(size() == 1);
242:         
243:         pop();
244:         assert(size() == 0);
245:     }
246:     
247:     
248:     void proof_harness_isEmpty() {
249:         create();
250:         assert(isEmpty() == 1);
251:         
252:         push(42);
253:         assert(isEmpty() == 0);
254:         
255:         pop();
256:         assert(isEmpty() == 1);
257:     }
258:     
259:     
260:     void proof_harness_main() {
261:         int x, y, z;
262:         
263:         create();
264:         push(4);
265:         x = pop();
266:         
267:         printf("%d.\t\tCount: %d.\tEmpty: %d.\n", x, size(), isEmpty());
268:         
269:         push(1);
270:         push(2);
271:         push(3);
272:         x = pop();
273:         y = pop();
274:         
275:         printf("%d, %d.\t\tCount: %d.\tEmpty: %d.\n", x, y, size(), isEmpty());
276:         pop();  
277:         
278:         push(5);
279:         push(6);
280:         x = peek();
281:         push(7);
282:         y = pop();
283:         push(8);
284:         z = pop();
285:         
286:         printf("%d, %d, %d.\tCount: %d.\tEmpty: %d.\n", x, y, z, size(), isEmpty());
287:         
288:         return;
289:     }
290:     
291:     
292:     void combined_proof_harness() {
293:         proof_harness_create();
294:         proof_harness_push();
295:         proof_harness_pop();
296:         proof_harness_peek();
297:         proof_harness_size();
298:         proof_harness_isEmpty();
299:         proof_harness_main();
300:     }
    
    That is incorrect on the following inputs:
    #Counterexamples
Counter example 1:
On line 238 in function 'proof_harness_size',the test for 'assertion size() == 0' failed under the following counter example: 
When x has input value 0 under the data type integer

Counter example 2:
On line 241 in function 'proof_harness_size',the test for 'assertion size() == 1' failed under the following counter example: 
When x has input value 0 under the data type integer

Counter example 3:
On line 244 in function 'proof_harness_size',the test for 'assertion size() == 0' failed under the following counter example: 
When x has input value 0 under the data type integer

Counter example 4:
On line 250 in function 'proof_harness_isEmpty',the test for 'assertion isEmpty() == 1' failed under the following counter example: 
When x has input value 0 under the data type integer

Counter example 5:
On line 256 in function 'proof_harness_isEmpty',the test for 'assertion isEmpty() == 1' failed under the following counter example: 
When x has input value 0 under the data type integer


    
# Constraints
    Here are some constraints that you should respect:
    - Give me only the translated code, don't add explanations or anything else. 
    - Use only safe C.
    - Do not use custom generics. # fuzzer limitation
    - Do not remove any code from the original code you have received.
    - Ensure that all libraries needed, including <assert.h> and <stdbool.h>, are declared at the beginning of the code.
    
