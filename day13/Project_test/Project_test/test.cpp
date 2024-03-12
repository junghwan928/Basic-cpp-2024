/*
char ary[] = {'a','b', 'c', 'd', 'e', 'f'}

조건: while문과 if 문만으로 배열 순서 바꾸어서 저장후 출력
*/

#include <iostream>
using namespace std;

int main() {
    char ary[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int size = sizeof(ary) / sizeof(ary[0]);
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // if 문을 사용해 특정 조건 하에서만 요소를 교환
        // 여기서는 단순히 예시를 보여주기 위해 모든 경우에 true인 조건을 사용
        if (start < end) {
            char temp = ary[start];
            ary[start] = ary[end];
            ary[end] = temp;
        }

        start++;
        end--;

        // 여기서 if 문을 사용할 수 있는 다른 예는,
        // 특정 조건(예: 인덱스가 짝수일 때) 하에서만 인덱스를 증가시키거나 감소시키는 것입니다.
        // 이는 배열을 뒤집는 기본 로직과는 관련이 없으므로 주의해야 합니다.
    }

    // 뒤집힌 배열 출력
    for (int i = 0; i < size; i++) {
        cout << ary[i] << ' ';
    }
    cout << endl;

    return 0;
}


