#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    int front, rear;
    element data[MAX_QUEUE_SIZE]
} QueueType;

// 오류 함수
void error(char *message){
    fprintf(stderr, "%s\n" , message);
    exit(1);
}

void init_Queue(QueueType *q){
    q->front = q->rear = -1;
}

void print_Queue(QueueType *q){
    for(int i = 0; i < MAX_QUEUE_SIZE; i++){
        if(i <= q->front || i > q->rear){
            printf("  | ");
        }
        else{
            printf("%d | ", q->data[i]);
        }
    }
    printf("\n");
}

int is_Full(QueueType *q){
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

int is_Empty(QueueType *q){
    return (q->front == q->rear);
}

void enQueue(QueueType *q, int item){
    if(is_Full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    q->data[++(q->rear)] = item;
}

int deQueue(QueueType *q){
    if(is_Empty(q)){
        error("큐가 공백상태입니다.");
        return;
    }
    return q->data[++(q->front)];
}

int main(){
    QueueType q;
    init_Queue(&q);

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);

    printf("%d \n", deQueue(&q));
    printf("%d \n", deQueue(&q));
    printf("%d \n", deQueue(&q));

    return 0;
}