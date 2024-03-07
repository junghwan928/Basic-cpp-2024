#include <iostream>
using namespace std;

// 템플릿 함수 정의
template <class T1, class T2>
void ShowData(double num)
{
    // 인자로 전달된 num을 T1과 T2 타입으로 변환하여 출력
    cout << (T1)num << ", " << (T2)num << endl;
}

int main(void)
{
    // ShowData 함수 호출 및 인자 전달
    ShowData<char, int>(65);        // 문자 'A'(ASCII 65), 정수 65 출력
    ShowData<char, int>(67);        // 문자 'C'(ASCII 67), 정수 67 출력
    ShowData<char, double>(68.9);   // 문자 'D'(ASCII 68), 실수 68.9 출력
    ShowData<short, double>(69.2);  // 정수 69, 실수 69.2 출력
    ShowData<short, double>(70.4);  // 정수 70, 실수 70.4 출력
    return 0;
}

/*
1. template <class T1, class T2> void ShowData(double num): 
    -> 템플릿 함수 ShowData의 정의됨. T1과 T2 두 가지 타입을 받아서, 
        -> 인자로 전달된 num을 해당 타입으로 형변환하여 출력됨.

2. ShowData<char, int>(65);: 
    -> 템플릿 함수를 호출하고, 첫 번째 템플릿 인자로 char을, 두 번째 템플릿 인자로 int를 전달하여 함수를 호출됨. 
        -> 65가 double 타입으로 전달되어 문자 'A'(ASCII 65)와 정수 65가 출력됨.

3. ShowData<char, int>(67);: 
    -> 위와 동일한 방식으로 함수를 호출하고, 
        -> 67이 double 타입으로 전달되어 문자 'C'(ASCII 67)와 정수 67이 출력됨.

4. ShowData<char, double>(68.9);: 
    -> 68.9가 double 타입으로 전달되어 문자 'D'(ASCII 68)와 실수 68.9가 출력됨.

5. ShowData<short, double>(69.2);: 
    -> 69.2가 double 타입으로 전달되어 정수 69과 실수 69.2가 출력됨.

6. ShowData<short, double>(70.4);: 
    -> 70.4가 double 타입으로 전달되어 정수 70과 실수 70.4가 출력됨
*/