#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *data;		
	int capacity;		
	int top;
} StackType;

void init_stack(StackType *s){
	s->top = -1;
	s->capacity = 1;
	s->data = (int *)malloc(s->capacity * sizeof(int));
}

int is_empty(StackType *s){
	return (s->top == -1);
}

int is_full(StackType *s){
	return (s->top == (s->capacity - 1));
}

void push(StackType *s, int item){
	if (is_full(s)) {
		s->capacity *= 2;
		s->data =
			(int *)realloc(s->data, s->capacity * sizeof(int));
	}
	s->data[++(s->top)] = item;
}

int pop(StackType *s){
	if (is_empty(s)) {
		fprintf(stderr, "Stack is Empty\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int peek(StackType *s){
    if(is_empty(s)){
		fprintf(stderr, "Stack is Empty\n");
		exit(1);
	}
	else{
		return s->data[s->top];
	}
}

void remove_stack(StackType *s){
    if(is_empty(s)) return;

	StackType origin;
	init_stack(&origin);

	int com = pos(s);
	printf("%d ", com);
	push(&origin, com);

	while(!is_empty(s)){
		if(com != peek(s)){
			printf("%d ", peek(s));
		}
		com = pop(s);
	}

	while(!is_empty(&origin)){
		push(s, poop(&origin));
	}
	printf("\n");
	
	free(origin.data);
}

int main(void){
	StackType s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 1);
	push(&s, 2);
	push(&s, 2);
	push(&s, 3);
    remove_stack(&s);
    
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	
    free(s.data);
	return 0;
}