#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    // 문자열 변수 선언 및 초기화
    string str1 = "I like ";
    string str2 = "string class";

    // 문자열 결합
    string str3 = str1 + str2;

    // 각 문자열 출력
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    // 문자열 결합 후 비교
    str1 += str2;
    if (str1 == str3)
        cout << "동일 문자열!" << endl;
    else
        cout << "동일하지 않은 문자열!" << endl;

    // 문자열 입력 받기
    string str4;
    cout << "문자열 입력: ";
    cin >> str4; // 공백을 포함하지 않는 문자열 입력 받음
    cout << "입력한 문자열: " << str4 << endl;

    return 0;
}
