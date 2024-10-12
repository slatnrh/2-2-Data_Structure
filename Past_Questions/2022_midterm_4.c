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
    if(s->top == -1){
        fprintf(stderr, "Stack is Empty \n");
        exit(1);
    }
    else return s->data[s->top];
}

void remove_stack(StackType *s){
    if(s->top == -1){
        fprintf(stderr, "Stack is Empty \n");
        exit(1);
    }

    int *unique = (int *)malloc(s->capacity * sizeof(int));
    int unique_top = -1;

    for(int i = 0; i <= s->top ; i++){
        int is_duplicate = 0;

        for(int j = 0; j <= unique_top; j++){
            if(s->data[i] == unique[j]){
                is_duplicate = 1;
                break;
            }
        }

        if(!is_duplicate){
            unique[++unique_top] = s->data[i];
        }
    }

    for(int i = unique_top ; i >= 0; i--){
        printf("%d\n", unique[i]);
    }
    free(unique);
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