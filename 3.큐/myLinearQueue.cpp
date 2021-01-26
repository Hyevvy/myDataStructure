//선형 큐 구현
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4
typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_Queue(QueueType *q){
    q->front=-1;
    q->rear=-1;
}

void queue_print(QueueType *q){
//    for(int i=front; i<rear; i++){
//        printf("%d ",q[i]);
//    }
    for(int i=0; i<MAX_QUEUE_SIZE; i++){
        if(i <= q->front || i> q->rear ){
            printf(" | ");
        }
        else {
            printf(" %d | ", q->data[i]);
        }
    }
    printf("\n");
}

int is_full(QueueType *q){
    if(q->rear == MAX_QUEUE_SIZE-1){
        return 1;
    }
    else return 0;
}

int is_empty(QueueType *q){
    if(q->front == q->rear){ //왜 q->front == -1 && q->rear == -1이라고 안 했을까
        return 1;
    }
    else return 0;
}

void enqueue(QueueType *q, int item){
    if(is_full(q)){
        error("포화상태입니다");
        return ;
    }
    q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q){
    if(is_empty(q)){
        error("비어있습니다.");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}

int peek(QueueType *q){
    if(is_empty(q)){
        error("비어있습니다.");
        return -1;
    }
    return q->data[q->front];
}
int main(){
    
    return 0;
}
