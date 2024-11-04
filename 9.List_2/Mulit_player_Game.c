#include <stdio.h>
#include <stdlib.h>

typedef char element[100];
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

typedef struct CListType{
	ListNode *head;
} CListType;

void print_list(CListType* L){
	ListNode* p;

	if(L->head == NULL) return;
	p = L->head->link;
	do{
		printf("%s->", p->data);
		p = p->link;
	} while (p != L->head);
	printf("%s->", p->data);        // 변경된 head 포인터 반환
}

void insert_first(CListType* L, element data){
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	strcpy(node->data, data);

	if(L->head == NULL){
		L->head = node;
		node->link = L->head;
	}
	else{
		node->link = L->head->link;
		L->head->link = node;
	}
}

int main(){
	CListType list = { NULL };

	insert_first(&list, "KIM");
	insert_first(&list, "PARK");
	insert_first(&list, "CHOI");

	ListNode* p = list.head;
	for(int i = 0; i< 10; i++) {
		printf("현재 차례=%s \n", p->data);
		p = p->link;
	}
    
	return 0;
}
