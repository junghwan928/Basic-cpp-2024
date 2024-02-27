/*
메모리 동적할당 : new 연산자 사용
*/
#include <iostream>
using namespace std;

int main() {
    // int 자료형의 크기를 출력.
    cout << "int Size : " << sizeof(int) << endl;

    // 동적으로 int 형 변수를 할당.
    // new 연산자를 통해 heap 영역에 int(4byte) 크기만큼 메모리를 할당.
    // 이때, 할당된 메모리의 주소를 포인터 변수 pi에 저장.
    int* pi = new int;

    // 포인터 변수 pi가 가리키는 메모리에 값을 저장합니다.
    // 이때, * 연산자를 사용하여 값을 저장.
    *pi = 10;

    // 포인터 변수 pi가 가리키는 곳에서 저장된 값을 출력.
    cout << "Pi가 가리키는 곳에서 저장된 값 : " << *pi << endl;

    // 동적으로 할당받은 메모리 공간을 반환.
    delete pi;

    // 배열 형태로 할당합니다.
    // new 연산자를 사용하여 int 형 배열을 10개 요소로 할당받음.
    // 할당된 메모리의 시작 주소를 포인터 변수 pary에 저장.
    int* pary = new int[10];
    cout << sizeof(pary) << endl;

    // 배열 pary의 각 요소에 값을 할당.
    for (int i = 0; i < 10; i++) {
        // 배열의 각 방에 원소(요소)값을 집어 넣음 => ex) pary[0] = 10
        pary[i] = i + 10;
    }

    // 배열 pary의 각 요소에 저장된 값을 출력.
    for (int i = 0; i < 10; i++) {
        printf("pary[%d] : %d\n", i, pary[i]);
    }


    // 배열로 -> 동적으로 할당받은 배열의 메모리 공간을 반환.
    delete[] pary;

    return 0;
}

/* 추가 설명
   1. 위 코드에서는 new 연산자를 사용하여 배열 형태로 메모리를 동적으로 할당, 
   -> 각 요소에 값을 할당한 후 출력. 

   2. 마지막으로 delete[] 연산자를 사용하여 할당된 배열의 메모리 공간을 반환. 
   -> 이렇게 동적으로 할당된 배열은 더 이상 사용되지 않을 때 메모리 누수를 방지하기 위해 반환
*/