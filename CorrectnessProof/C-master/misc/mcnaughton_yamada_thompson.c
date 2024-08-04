

#include <assert.h> 
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h> 




struct ASTNode {
    char content;          
    struct ASTNode* left;  
    struct ASTNode* right; 
};

struct ASTNode* createNode(char content);
void destroyNode(struct ASTNode* node);
char* preProcessing(const char* input);
struct ASTNode* buildAST(const char* input);


struct transRule {
    struct NFAState* target; 
    char cond;               
};

struct transRule* createRule(struct NFAState* state, char c);
void destroyRule(struct transRule* rule);


struct NFAState {
    int ruleCount;            
    struct transRule** rules; 
};

struct NFAState* createState(void);
void destroyState(struct NFAState* state);


struct NFA {
    int stateCount;                  
    struct NFAState** statePool;     
    int ruleCount;                   
    struct transRule** rulePool;     
    int CSCount;                     
    struct NFAState** currentStates; 
    int subCount;                    
    struct NFA** subs;               
    int wrapperFlag;                 
};

struct NFA* createNFA(void);
void destroyNFA(struct NFA* nfa);
void addState(struct NFA* nfa, struct NFAState* state);
void addRule(struct NFA* nfa, struct transRule* rule, int loc);
void postProcessing(struct NFA* nfa);
void transit(struct NFA* nfa, char input);
int isAccepting(const struct NFA* nfa);




int isLiteral(const char ch) {
    return !(ch == '(' || ch == ')' || ch == '*' || ch == '\n' || ch == '|');
}


char* preProcessing(const char* input) {
    const size_t len = strlen(input);
    if(len == 0) {
        char* str = malloc(1);
        str[0] = '\0';
        return str;
    }

    char* str = malloc(len * 2);
    size_t op = 0;

    for (size_t i = 0; i < len - 1; ++i) {
        char c = input[i];
        str[op++] = c;
        
        char c1 = input[i + 1];

        if( (isLiteral(c) && isLiteral(c1)) ||
            (isLiteral(c) && c1 == '(') ||
            (c == ')' && c1 == '(') ||
            (c == ')' && isLiteral(c1)) ||
            (c == '*' && isLiteral(c1)) ||
            (c == '*' && c1 == '(')
                ) {
            
            
            str[op++] = '\n';
        }
    }

    str[op++] = input[len - 1];
    str[op] = '\0';
    return str;
}


size_t indexOf(const char* str, char key) {
    int depth = 0;

    for (size_t i = 0; i < strlen(str); ++i) {
        const char c = str[i];

        if(depth == 0 && c == key) {
            return i;
        }
        if(c == '(') depth++;
        if(c == ')') depth--;
    }
    
    
    
    
    return 0;
}


char* subString(const char* str, size_t begin, size_t end) {
    char* res = malloc(end - begin + 2);
    strncpy(res, str + begin, end - begin + 1);
    res[end - begin + 1] = '\0';
    return res;
}


struct ASTNode* buildAST(const char* input) {

    struct ASTNode* node = createNode('\0');
    node->left = NULL;
    node->right = NULL;
    const size_t len = strlen(input);
    size_t index;

    
    if(len == 0) return node;

    
    if(len == 1) {
        node->content = input[0];
        return node;
    }

    
    if(input[0] == '(' && input[len - 1] == ')') {
        char* temp = subString(input, 1, len - 2);
        destroyNode(node);
        node = buildAST(temp);

        free(temp);
        return node;
    }

    
    index = indexOf(input, '|');
    if(index) {
        node->content = '|';

        char* temp1 = subString(input, 0, index - 1);
        char* temp2 = subString(input, index + 1, len - 1);
        node->left = buildAST(temp1);
        node->right = buildAST(temp2);

        free(temp2);
        free(temp1);
        return node;
    }

    
    index = indexOf(input, '\n');
    if(index) {
        node->content = '\n';

        char* temp1 = subString(input, 0, index - 1);
        char* temp2 = subString(input, index + 1, len - 1);
        node->left = buildAST(temp1);
        node->right = buildAST(temp2);

        free(temp2);
        free(temp1);
        return node;
    }

    
    
    
    node->content = '*';
    char* temp = subString(input, 0, len - 2);
    node->left = buildAST(temp);
    node->right = NULL;

    free(temp);
    return node;
}




void redirect(struct NFA* nfa, struct NFAState* src, struct NFAState* dest) {
    for (int i = 0; i < nfa->subCount; ++i) {
        redirect(nfa->subs[i], src, dest);
    }
    for (int i = 0; i < nfa->ruleCount; ++i) {
        struct transRule* rule = nfa->rulePool[i];
        if (rule->target == src) {
            rule->target = dest;
        }
    }
}

struct NFA* compileFromAST(struct ASTNode* root) {

    struct NFA* nfa = createNFA();

    
    if (root->content == '\0') {
        addRule(nfa, createRule(nfa->statePool[1], '\0'), 0);
        return nfa;
    }

    
    if (isLiteral(root->content)) {
        addRule(nfa, createRule(nfa->statePool[1], root->content), 0);
        return nfa;
    }

    switch (root->content) {

        case '\n': {
            struct NFA* ln = compileFromAST(root->left);
            struct NFA* rn = compileFromAST(root->right);

            
            
            redirect(ln, ln->statePool[1], rn->statePool[0]);

            
            
            destroyNFA(nfa);
            struct NFA* wrapper = malloc(sizeof(struct NFA));
            wrapper->stateCount = 2;
            wrapper->statePool = malloc(sizeof(struct NFAState*) * 2);
            wrapper->subCount = 0;
            wrapper->subs = malloc(sizeof(struct NFA*) * 2);
            wrapper->ruleCount = 0;
            wrapper->rulePool = malloc(sizeof(struct transRule*) * 3);
            wrapper->CSCount = 0;
            wrapper->currentStates = malloc(sizeof(struct NFAState*) * 2);
            wrapper->wrapperFlag = 1;
            wrapper->subs[wrapper->subCount++] = ln;
            wrapper->subs[wrapper->subCount++] = rn;

            
            
            wrapper->statePool[0] = ln->statePool[0];
            wrapper->statePool[1] = rn->statePool[1];

            return wrapper;
        }
        case '|': {

            struct NFA* ln = compileFromAST(root->left);
            struct NFA* rn = compileFromAST(root->right);
            nfa->subs[nfa->subCount++] = ln;
            nfa->subs[nfa->subCount++] = rn;

            
            addRule(nfa, createRule(ln->statePool[0], '\0'), 0);
            addRule(ln, createRule(nfa->statePool[1], '\0'), 1);
            addRule(nfa, createRule(rn->statePool[0], '\0'), 0);
            addRule(rn, createRule(nfa->statePool[1], '\0'), 1);

            return nfa;
        }
        case '*': {
            struct NFA* ln = compileFromAST(root->left);
            nfa->subs[nfa->subCount++] = ln;

            addRule(ln, createRule(ln->statePool[0], '\0'), 1);
            addRule(nfa, createRule(ln->statePool[0], '\0'), 0);
            addRule(ln, createRule(nfa->statePool[1], '\0'), 1);
            addRule(nfa, createRule(nfa->statePool[1], '\0'), 0);

            return nfa;
        }
    }

    
    destroyNFA(nfa);
    return NULL;
}




void addState(struct NFA* nfa, struct NFAState* state) {
    nfa->statePool[nfa->stateCount++] = state;
}


void addRule(struct NFA* nfa, struct transRule* rule, int loc) {
    nfa->rulePool[nfa->ruleCount++] = rule;
    struct NFAState* state = nfa->statePool[loc];
    state->rules[state->ruleCount++] = rule;
}


void postProcessing(struct NFA* nfa) {
    
    
    for (int i = 0; i < nfa->subCount; ++i) {
        postProcessing(nfa->subs[i]);
    }

    
    
    
    
    for (int i = 0; i < nfa->stateCount; ++i) {

        struct NFAState* pState = nfa->statePool[i];
        int f = 0;
        for (int j = 0; j < pState->ruleCount; ++j) {
            if(pState->rules[j]->cond == '\0') {
                f = 1;
                break;
            }
        }

        if (!f) {
            addRule(nfa, createRule(pState, '\0'), i);
        }
    }
}


int contains(struct NFAState** states, int len, struct NFAState* state) {
    int f = 0;
    for (int i = 0; i < len; ++i) {
        if(states[i] == state) {
            f = 1;
            break;
        }
    }
    return f;
}


void findEmpty(struct NFAState* target, struct NFAState** states, int *sc) {
    for (int i = 0; i < target->ruleCount; ++i) {
        const struct transRule *pRule = target->rules[i];

        if (pRule->cond == '\0' && !contains(states, *sc, pRule->target)) {
            states[(*sc)++] = pRule->target;
            
            
            findEmpty(pRule->target, states, sc);
        }
    }
}


void transit(struct NFA* nfa, char input) {
    struct NFAState** newStates = malloc(sizeof(struct NFAState*) * 10);
    int NSCount = 0;

    if (input == '\0') {
        
        
        
        for (int i = nfa->CSCount - 1; i > -1; --i) {
            struct NFAState *pState = nfa->currentStates[i];
            nfa->CSCount--;

            struct NFAState** states = malloc(sizeof(struct NFAState*) * 10);
            int sc = 0;
            findEmpty(pState, states, &sc);

            for (int j = 0; j < sc; ++j) {
                if(!contains(newStates,NSCount, states[j])) {
                    newStates[NSCount++] = states[j];
                }
            }
            free(states);
        }
    } else {
        
        for (int i = nfa->CSCount - 1; i > -1; --i) {
            struct NFAState *pState = nfa->currentStates[i];
            
            
            nfa->CSCount--;

            
            for (int j = 0; j < pState->ruleCount; ++j) {
                const struct transRule *pRule = pState->rules[j];

                if(pRule->cond == input) {
                    if(!contains(newStates, NSCount, pRule->target)) {
                        newStates[NSCount++] = pRule->target;
                    }
                }
            }
        }
    }

    nfa->CSCount = NSCount;
    for (int i = 0; i < NSCount; ++i) {
        nfa->currentStates[i] = newStates[i];
    }
    free(newStates);
}


int isAccepting(const struct NFA* nfa) {
    for (int i = 0; i < nfa->CSCount; ++i) {
        if(nfa->currentStates[i] == nfa->statePool[1]) {
            return 1;
        }
    }
    return 0;
}




void testHelper(const char* regex, const char* string, const int expected) {
    char* temp = preProcessing(regex);
    struct ASTNode* node = buildAST(temp);

    struct NFA* nfa = compileFromAST(node);
    postProcessing(nfa);

    
    
    nfa->currentStates = realloc(nfa->currentStates, sizeof(struct NFAState*) * 100);
    
    nfa->currentStates[nfa->CSCount++] = nfa->statePool[0];

    
    
    for (size_t i = 0; i < strlen(string); ++i) {
        transit(nfa, '\0');
        transit(nfa, string[i]);
    }
    transit(nfa, '\0');

    assert(isAccepting(nfa) == expected);

    destroyNFA(nfa);
    destroyNode(node);
    free(temp);
}


static void test(void) {
    testHelper("(c|a*b)", "c", 1);
    testHelper("(c|a*b)", "aab", 1);
    testHelper("(c|a*b)", "ca", 0);
    testHelper("(c|a*b)*", "caaab", 1);
    testHelper("(c|a*b)*", "caba", 0);
    testHelper("", "", 1);
    testHelper("", "1", 0);
    testHelper("(0|(1(01*(00)*0)*1)*)*","11",1);
    testHelper("(0|(1(01*(00)*0)*1)*)*","110",1);
    testHelper("(0|(1(01*(00)*0)*1)*)*","1100",1);
    testHelper("(0|(1(01*(00)*0)*1)*)*","10000",0);
    testHelper("(0|(1(01*(00)*0)*1)*)*","00000",1);

    printf("All tests have successfully passed!\n");
}


int main(void) {
    test(); 
    return 0;
}




struct ASTNode* createNode(const char content) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    node->content = content;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void destroyNode(struct ASTNode* node) {
    if(node->left != NULL) {
        destroyNode(node->left);
    }

    if(node->right != NULL) {
        destroyNode(node->right);
    }

    free(node);
}


struct transRule* createRule(struct NFAState* state, char c) {
    struct transRule* rule = malloc(sizeof(struct transRule));
    rule->target = state;
    rule->cond = c;
    return rule;
}


void destroyRule(struct transRule* rule) {
    free(rule);
}


struct NFAState* createState(void) {
    struct NFAState* state = malloc(sizeof(struct NFAState));
    state->ruleCount = 0;
    state->rules = malloc(sizeof(struct transRule*) * 3);
    return state;
}


void destroyState(struct NFAState* state) {
    free(state->rules);
    free(state);
}


struct NFA* createNFA(void) {
    struct NFA* nfa = malloc(sizeof(struct NFA));

    nfa->stateCount = 0;
    nfa->statePool = malloc(sizeof(struct NFAState*) * 5);
    nfa->ruleCount = 0;
    nfa->rulePool = malloc(sizeof(struct transRule*) * 10);
    nfa->CSCount = 0;
    nfa->currentStates = malloc(sizeof(struct NFAState*) * 5);
    nfa->subCount = 0;
    nfa->subs = malloc(sizeof(struct NFA*) * 5);
    nfa->wrapperFlag = 0;

    addState(nfa, createState());
    addState(nfa, createState());
    return nfa;
}


void destroyNFA(struct NFA* nfa) {
    for (int i = 0; i < nfa->subCount; ++i) {
        destroyNFA(nfa->subs[i]);
    }

    
    
    if (!nfa->wrapperFlag) {
        for (int i = 0; i < nfa->stateCount; ++i) {
            destroyState(nfa->statePool[i]);
        }
    }
    for (int i = 0; i < nfa->ruleCount; ++i) {
        destroyRule(nfa->rulePool[i]);
    }
    free(nfa->statePool);
    free(nfa->currentStates);
    free(nfa->rulePool);
    free(nfa->subs);
    free(nfa);
}
