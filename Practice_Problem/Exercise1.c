#include <stdio.h>
#include <math.h>

int main() {
    // 10개의 item을 저장할 수 있는 배열 선언
    int two[10];

    // 2의 거듭제곱을 계산하여 배열에 저장
    for (int i = 0; i < 10; i++) {
        two[i] = (int)pow(2, i); // pow 함수는 double을 반환하므로 int로 변환
    }

    // 배열의 모든 item을 출력
    for (int i = 0; i < 10; i++) {
        printf("two[%d] = %d\n", i, two[i]);
    }

    return 0;
}