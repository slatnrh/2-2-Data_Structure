#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

ListNode* insert_last(ListNode* head, int data){
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;

    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link; 
        head->link = node; 
        head = node; 
    }

    return head; 
}

ListNode *search(ListNode *head, int data){
    ListNode *node = head;
    while(node != NULL){
        if(node->data == data){
            return node;
        }
        node = node->link;
    }

    return NULL;
}

int main() {
    ListNode *head = NULL;
    
    head = insert_last(head, 10);
    head = insert_last(head, 20);
    head = insert_last(head, 30);

    ListNode *found = search(head, 40);
    if(found != NULL){
        printf("Found node with data: %d\n", found->data);
    }
    else{
        printf("Node not found\n");
    }
    
    // 메모리 해제를 위한 코드
    ListNode *current = head;
    ListNode *temp;
    while (current != NULL) {
        temp = current;
        current = current->link;
        free(temp); // 할당한 메모리 해제
    }

    return 0;
}