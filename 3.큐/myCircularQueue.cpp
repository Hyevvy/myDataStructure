#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char* message){
    fprintf(stderr,"%s\n", message);
    exit(1);
}
void init_queue(QueueType *q){
    q->front = q->rear =0;
}

int is_empty(QueueType *q){
    return (q->front == q->rear);
}

int is_full(QueueType *q){
    return ( (q->rear +1 ) % MAX_QUEUE_SIZE == q->front);
}
