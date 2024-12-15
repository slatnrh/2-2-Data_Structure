#include <stdio.h>
#include <stdlib.h>

void print_list(int list[]){
	int n = 7;
	for(int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}

void inc_insertion_sort(int list[], int first, int last, int gap){
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap){
		key = list[i];
		for (j = i - gap; j >= first && key<list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n){      // n = size
	int i, gap;
	for(gap = n / 2; gap > 0; gap = gap / 2){
		printf("gap: %d \n", gap);
		if((gap % 2) == 0) gap++;
		for(i = 0; i < gap; i++)     // 부분 리스트의 개수는 gap
			inc_insertion_sort(list, i, n - 1, gap);
		print_list(list);	
	}
}

int main(){
	int list[]={5,3,8,4,9,1,2};
	shell_sort(list, 7);

	print_list(list);

	return 0;
}