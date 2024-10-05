#include <stdio.h>
#define MAX_SIZE 100

// 스택 구조체 정의
typedef struct{
    int data[MAX_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void initStack(StackType *s){
    s->top = -1;
}

// 스택이 비어있는지 확인하는 함수(비어있으면 1, 아니면 0을 출력하는 함수)
int isEmpty(StackType *s){
    return s->top == -1;
}

// 스택이 가득 찼는지 확인하는 함수
int isFull(StackType *s){
    return s->top == MAX_SIZE - 1;
}

// 스택에 값을 넣는 함수: push
void push(StackType *s, int value){
    if(!isFull(s)){
        s->data[++(s->top)] = value;
    }
    else{
        printf("스택이 가득 찼습니다.\n");
    }
}

// 스택에 값을 꺼내는 함수: pop
int pop(StackType *s){
    if(!isEmpty(s)){
        return s->data[(s->top)--];
    }
    else{
        printf("스택이 비어 있습니다.\n");
        return -1;
    }
}


int main(){
    StackType
 stack;
    int size, value;

    initStack(&stack);
    printf("정수 배열의 크기: ");
    scanf("%d", &size);

    printf("%d개의 정수를 입력하시오: ", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &value);
        push(&stack, value);
    }

    printf("반전된 정수 배열: ");
    while(!isEmpty(&stack)){
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}

// 스택을 이용하여 배열에 들어있는 정수의 순서를 거꾸로 하는 프로그램을 작성하시오.
// 1)배열의 크기와 정수들은 사용자로부터 입력 받음
// 2)입력받은 정수를 역순으로 하여 화면에 출력
// 3)스택은 1차원 배열을 이용하여 구현
// (실행 예시)
// [Output] 정수 배열의 크기: [Input] 5 
// [Output] 5개의 정수를 입력하시오: [Input] 1 2 3 4 5 
// [Output] 반전된 정수 배열: 5 4 3 2 1