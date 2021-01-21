#include <stdlib.h>
#include <stdio.h>
//동적 배열 스택
typedef int element;
typedef struct{
    element *data;
    int top; //가장 맨 위에 있는 값
    int capacity; //수용할 수 있는 공간(size)
} StackType;

void init_stack(StackType *s){
    s->top = -1 ;
    s->capacity = 1;
    s->data = (element*) malloc(s->capacity * sizeof(element));
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == (s->capacity - 1));
}

element pop(StackType *s){
    if(is_empty(s)){
        printf("비었어요!");
        return -1;
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s){
    if(is_empty(s)){
        printf("비었어요!");
        return -1;
    }
    else return s->data[(s->top)];
}

void push(StackType *s, element item){
    if(is_full(s)){
        s->capacity *= 2;
        s->data = (element *) realloc(s->data, s->capacity * sizeof(element));
    }
    s->data [++(s->top)] = item;
}
int main(){
    StackType s;
    init_stack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    free(s.data);
    return 0;
}

