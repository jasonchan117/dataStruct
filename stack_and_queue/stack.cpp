/*************************************************************************
	> File Name: stack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月19日 星期四 13时24分21秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define data_type int
#define NULL_VALUE 0

typedef struct Stack {
    data_type *data;
    int top, size;

} Stack;

Stack *init(int n);
void clear(Stack *);
data_type top(Stack *);
int push(Stack *, data_type);
int pop(Stack *);
int empty(Stack *);
void output(Stack *);

int main() {
    srand(time(0));
    Stack *s = init(20);
    for (int i = 0; i < 20; i++) {
        int op = rand() % 2, value = rand() % 100;
        switch (op) {
            case 0: {
                printf("push element = %d to stack\n", value);
                push(s, value);
                output(s);            
            } break;
            case 1: {
                printf("pop element from stack\n");
                pop(s);
                output(s);            
            } break;
            default:
            fprintf(stderr, "error operator = %d\n", op);
            break;        
        }
    }
    clear(s);
    return 0;

}

/*void output(Stack *s) {
    int ret = 0, last_pos = 0;
    ret += printf("[");
    for (int i = 0; i < s->size; i++) {
        if (i <= s->top) {
            ret += printf("%d", s->data[i]);
            last_pos = ret - 1;        
        }
        ret += printf(",");
            
    }
    ret += printf("]\n");
    for (int i = 0; i < last_pos; i++) {
        printf(" ");
            
    }
    printf("^\n");
    for (int i = 0; i < last_pos; i++) {
        printf(" ");
            
    }
    printf("|\n");
    for (int i = 0; i < last_pos - 1; i++) {
        printf(" ");
            
    }
    printf("top\n\n");
    return ;
}*/
int bin(int x){
    int sum=0;
    while(x){
        x/=10;
        sum++;
    }
    return sum;
}
void output(Stack *s) {
    printf("[");
    int diff=s->size-s->top-1;
    int ind=0;
    for(int i=0;i<=s->top;i++){
        ind+=(bin(s->data[i])+1);
        printf("%d,",s->data[i]);
    }
    ind-=2;
    for(int j=0;j<diff;j++) printf(",");
    printf("]\n");
    for(int i=1;i<=ind+1;i++) printf(" ");
    printf("^\n");
    for(int i=1;i<=ind+1;i++) printf(" ");
    printf("|\n");
    for(int i=1;i<=ind+2;i++) printf(" ");
    printf("top\n");
}
Stack *init(int n) {
        Stack *s = (Stack *)malloc(sizeof(Stack));    
        s->data = (data_type *)malloc(sizeof(data_type) * n);
        s->size = n;
        s->top = -1;
        return s;

}

void clear(Stack *s) {
        if (s == NULL) return ;
        free(s->data);
        free(s);
        return ;

}

data_type top(Stack *s) {
        if (empty(s)) return NULL_VALUE;
        return s->data[s->top];

}

int push(Stack *s, data_type value) {
    if (s->top + 1 == s->size) {
        return 0;
            
    }
    s->top += 1;
    s->data[s->top] = value;
    return 1;
}

int pop(Stack *s) {
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;

}

int empty(Stack *s) {
    return s->top == -1;
}
