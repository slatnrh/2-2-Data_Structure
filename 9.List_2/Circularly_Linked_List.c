#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void print_list(ListNode* head){
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do{
		printf("%d->", p->data);
		p = p->link;
	} while(p != head);

	printf("%d->", p->data);
}

ListNode* insert_first(ListNode* head, element data){
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if(head == NULL){
		head = node;
		node->link = head;
	}
	else{
		node->link = head->link;
		head->link = node;
	}
	return head;	// 변경된 head 포인터 반환
}

ListNode* insert_last(ListNode* head, element data){
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;

	if(head == NULL){
		head = node;
		node->link = head;
	}
	else{
		node->link = head->link;
		head->link = node;
		head = node;		// 마지막 node가 바뀌었으니 head 포인터 변경
	}
	return head;	// 변경된 head 포인터 반환
}

int main(){
	ListNode *head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);

	return 0;
}