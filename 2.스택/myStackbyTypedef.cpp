#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 4

typedef int element;
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
        printf(" 스택이 꽉 찼습니다. 들어갈 공간이 없어요!");
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

int main(){
    StackType s;
    init_stack(&s);
    push(&s,1);
    push(&s,2);
    printf("가장 꼭대기에 있는 값은 %d\n", peek(&s));
    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    printf("%d\n", peek(&s));
    printf("가장 꼭대기에 있는 값은 %d\n", peek(&s));
    printf("pop: %d\n", pop(&s));
    return 0;
}
