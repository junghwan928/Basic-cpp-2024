#include <iostream>
#include <cstdlib> // std::exit 함수를 사용하기 위해 필요
using namespace std;

class BoundCheckIntArray
{
private:
    int* arr; // 동적으로 할당된 정수 배열을 가리키는 포인터
    int arrlen; // 배열의 길이

public:
    // 생성자: 정수 배열의 길이를 인자로 받아 해당 크기의 배열을 동적 할당
    BoundCheckIntArray(int len) :arrlen(len)
    {
        arr = new int[len];
    }

    // 배열에 접근하는 연산자 오버로딩 함수
    int& operator[] (int idx)
    {
        // 인덱스가 배열 범위를 벗어났는지 검사
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1); // 프로그램을 비정상 종료
        }

        return arr[idx]; // 범위 내이면 해당 원소의 참조 반환
    }

    // 소멸자: 동적 할당된 배열의 메모리를 해제
    ~BoundCheckIntArray()
    {
        delete[] arr;
    }
};

int main(void)
{
    BoundCheckIntArray arr(5); // 길이가 5인 배열을 생성

    // 배열에 값을 초기화
    for (int i = 0; i < 5; i++)
        arr[i] = (i + 1) * 11;

    // 배열의 내용을 출력 (마지막 인덱스 5는 배열 범위를 벗어남)
    for (int i = 0; i < 6; i++)
        cout << arr[i] << endl;

    return 0;
}

/* 상세 설명
1. main 함수에서 BoundCheckIntArray 타입의 객체 arr를 길이 5로 생성함.

2. 이어서 for 루프를 사용해 배열의 각 원소에 값을 할당합니다. 각 원소의 값은 (i + 1) * 11으로 설정됨.

3. 다음 for 루프에서 배열의 내용을 출력하려고 합니다. 여기서 중요한 점은 이 루프가 0부터 5까지 실행되므로, 
    -> 마지막 반복에서는 배열의 범위를 벗어난 인덱스에 접근하려고 시도함.

4. BoundCheckIntArray 클래스의 operator[] 함수는 인덱스가 배열의 범위를 벗어났는지 확인하고, 
    -> 범위를 벗어난 경우 "Array index out of bound exception" 메시지를 출력한 후 프로그램을 종료함.

5. 프로그램이 exit(1) 호출로 비정상 종료되기 전까지 배열의 원소들을 성공적으로 출력함
*/

/* 배열이름은 배열의 시작주소
int ary[3] => 배열 선언부에서 배열 인덱스에 있는 숫자 방의 크기
ary[2] => 코드 실행에서 배열 인덱스에 있는 숫자는 방번호를 나타냄


ary[0] = 10; => 0번방, 첫번째 방의 데이터
*(ary + 0) = 10;=> *(배열의 시작주소 + 0) = 10


*(ary + 1) = 20; == ary[1] == 20; => 1번방에다가 20을 집어 넣어라
ary의 주소가 0x0011이라면 다음 방, 1번방(두번째방) 주소는 0x0015이다
*/