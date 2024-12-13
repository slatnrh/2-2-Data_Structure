int seq_search1(int key, int low, int high){
	int i;
	for(i = low; i <= high; i++)
		if (list[i] == key)
			return i;		// 탐색 성공 
	return -1;      // 탐색 실패
}

int seq_search2(int key, int low, int high){
	int i;
	list[high + 1] = key;       // 키 값을 찾으면 종료
	for (i = low; list[i] != key; i++)
    	if (i == (high + 1))
            return -1;     // 탐색 실패
	    else return i;      // 탐색 성공
}