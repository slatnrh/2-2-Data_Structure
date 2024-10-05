#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 오류 함수
void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 큐 초기화 함수
void initQueue(QueueType *q){
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int isEmpty(QueueType *q){
    return q->front == q->rear;
}

// 포화 상태 검출 함수
int isFull(QueueType *q){
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// 삽입 함수
void enqueue(QueueType *q, element item){
    if(isFull(q)){
        error("큐가 포화상태입니다");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q){
    if(isEmpty(q)){
        error("큐가 공백상태입니다");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int get_count(QueueType *q){
    if(isEmpty(q)){
        return 0;
    }
    else if(isFull(q)){
        return MAX_QUEUE_SIZE;
    }
    else{
        if(q->front < q->rear){
            return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        }
    }
}

int main(){
    QueueType queue;

    queue.front = 0;
    queue.rear = MAX_QUEUE_SIZE - 1;

    printf("큐에 들어있는 아이템의 개수: %d\n", get_count(&queue));

    return 0;
}

// 원형큐가 1차원 배열로 구현되어 있다고 가정할 때, 현 시점에서 원형큐에 들어있는 아이템의 개수를 반환하는 연산 get_count(QueueType *q)를 구현하시오.
// 원형큐의 1차원 배열 구현은 교재 (프로그램 5.2) 참고
// (실행 예시)
// [Output] 4