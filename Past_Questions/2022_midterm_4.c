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

	StackType unique;
	init_stack(&unique);

	while(!is_empty(s)){
		int value = pop(s);
		if(is_empty(&unique) || peek(&unique) != value){
			push(&unique, value);
		}
	}

	while(!is_empty(&unique)){
		push(s, pop(&unique));
	}

	for(int i = 0; i <= s->top; i++){
		printf("%d ", s->data[i]);
	}
	printf("\n");

	free(unique.data);
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