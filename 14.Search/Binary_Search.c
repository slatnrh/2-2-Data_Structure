#include <stdio.h>

#define MAX_SIZE 1000
int list[MAX_SIZE];

void init_list(){
	int i;
	for(i = 0; i < 1000; i++)
		list[i] = 7 * i;
}

int search_binary(int key, int low, int high){
    int middle;

    if(low <= high){
        middle = (low + high) / 2;
        if(key == list[middle])     // key값과 중간값이 같을 경우
	        return middle;
        else if(key < list[middle])     // key값이 중간값보다 작을 경우 
	        return search_binary(key, low, middle - 1);
        else        // key값이 중간값보다 클 경우 
	        return search_binary(key, middle + 1, high);
    }
    return -1;      // 탐색 실패
}

int search_binary2(int key, int low, int high){
    int middle;   

	while(low <= high){     // 아직 숫자들이 남아 있으면
	    middle = (low + high) / 2;
	    if(key == list[middle])
	        return middle;      // 탐색 성공
	    else if(key > list[middle])
			low = middle + 1;       // 왼쪽 부분리스트 탐색
		else
			high = middle - 1;      // 오른쪽 부분리스트 탐색
	}
	return -1;      // 탐색 실패
}

void main(){
	int i =0;
	init_list();
	
    i = search_binary2(49, 0, 999);
	if(i >= 0){
		printf("탐색 성공 i = %d\n", i);
	}
	else{
	    printf("탐색 실패\n");
	}
}