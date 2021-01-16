#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 4
int stack[MAX_STACK_SIZE];
int top = -1; //초기에는 아무 것도 없으니 최상단이 -1
bool is_empty(){
    if(top==-1) return true;
    else return false;
}
bool is_full(){
    if(top == MAX_STACK_SIZE-1) return true;
    else return false;
}

void push(int pushed){
    if(is_full()){
        printf("스택이 꽉 찼습니다. ㅠㅠ 들어갈 공간이 없어요\n");
        return;
    }
    top++;
    stack[top]=pushed;
}

int pop(){
    if(is_empty()) {
        printf("아무것도 없는데 어떻게 pop하나요ㄷㄷ\n");
        return 0;
    }
    return stack[top--];
}
int main(){
    printf("**아무것도 안 넣었을 때, 즉 스택이 비었을 때**\n");
    printf("is_empty확인 %d\n",is_empty()); //처음에는 비어있으니 0이 아닌 값이 나온다. (0이면 거짓, 0이 아니면 참)
    printf("is_full확인 %d\n",is_full()); //처음에는 full이 아니므로 0이 나온다.
    
    printf("**하나씩 넣어보기**n");
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("is_full확인 %d\n",is_full()); //꽉 차있으므로 0이 아닌 값이 나온다.
    
    printf("**하나씩 제거해보기**\n");
    pop();
    printf("%d\n",stack[3]);
    pop();
    printf("%d\n",stack[3]);
    pop();
    pop();
    pop();
    return 0;
}

