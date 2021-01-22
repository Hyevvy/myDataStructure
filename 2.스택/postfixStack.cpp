//후위표기식 계산
#include <stdlib.h>
#include <iostream>
#define MAX_STACK_SIZE 4
typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, element item){
    if(is_full(s)){
        printf(" 스택이 꽉 찼습니다. 들어갈 공간이 없어요!");
        return ;
    }
    else s->data[++(s-> top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)){
        printf("비어서 pop할 수가 없어요!");
        return -1;
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s){
    if(is_empty(s)){
        printf("비어있어서 peek을 할 수 없어요!");
        return -1;
    }
    else return s->data[(s->top)];
}


int eval(char exp[]){
    int op1, op2, value, i=0;
    int len=strlen(exp);
    char ch;
    StackType s;
    
    init_stack(&s);
    for(i=0; i<len; i++){
        ch =exp[i];
        if(ch!='+' && ch!='-' && ch!='*' && ch!='/'){
            value = ch-'0';
            push(&s, value);
        }
        else {
            op2=pop(&s);
            op1=pop(&s);
            switch(ch){
                case '+': push(&s, op1+op2); break;
                case '-': push(&s, op1-op2); break;
                case '*': push(&s, op1*op2); break;
                case '/': push(&s, op1/op2); break;
            }
        }
    }
    return pop(&s);
}
int main(){
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result =eval("82/3-32*+");
    printf("결과값은 %d\n", result);
    return 0;
}












