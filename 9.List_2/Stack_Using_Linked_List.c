#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode{
	element data;
	struct StackNode *link;
} StackNode;

typedef struct{         // 여러 개의 stack이 있을 때 top을 구분하기 위해서
	StackNode *top;
} LinkedStackType;      // int count 같은 걸 추가해서 활용성 높일 수 있음

void init(LinkedStackType *s){
	s->top = NULL;
}

int is_empty(LinkedStackType *s){
	return (s->top == NULL);
}

int is_full(LinkedStackType *s){        // Linked List로 stack을 구현할 경우 메모리는 무한이다(아마 무한은 아니지만 명시적으로 말한듯)
	return 0;
}

void push(LinkedStackType *s, element item){
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

void print_stack(LinkedStackType *s){
	for(StackNode *p = s->top; p != NULL; p = p->link){
		printf("%d->", p->data);
    }
	printf("NULL \n");
}

element pop(LinkedStackType *s){
	if(is_empty(s)){
		fprintf(stderr, "stack is empty \n");
		exit(1);
	}
	else{
		StackNode *temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

element peek(LinkedStackType *s){
	if (is_empty(s)) {
		fprintf(stderr, "stack is empty \n");
		exit(1);
	}
	else{
		return s->top->data;
	}
}

int main(){
	LinkedStackType s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);

	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	
    return 0;
}