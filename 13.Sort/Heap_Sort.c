#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct{
	int key;
} element;

typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// Heap 생성
HeapType* create(){
	return (HeapType*)malloc(sizeof(HeapType));
}

// Heap 초기화
void init(HeapType* h){
	h->heap_size = 0;
}

// max_heap 삽입 연산
void insert_max_heap(HeapType* h, element item){
	int i;
	i = ++(h->heap_size);

	// 부모와 비교하여 exchange
	while((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;      // 기준이 i에서 parent로 넘어가서 기준 변경 
}

// max_heap 삭제 연산
element delete_max_heap(HeapType* h){
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while(child <= h->heap_size){
		// 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		if((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if(temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	
    return item;
}

void heap_sort(element a[], int n){
	int i;
	HeapType* h;

	h = create();
	init(h);
	for(i = 0; i < n; i++){
		insert_max_heap(h, a[i]);
	}
	for(i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}

	free(h);
}

#define SIZE 8
int main(){
	element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, SIZE);
	for(int i = 0; i < SIZE; i++){
		printf("%d ", list[i].key);
	}
	printf("\n");

	return 0;
}