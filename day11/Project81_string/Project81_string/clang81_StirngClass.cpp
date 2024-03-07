#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    int len;    // 문자열 길이를 저장하는 멤버 변수
    char* str;  // 문자열을 저장하는 포인터

public:
    // 생성자
    String();
    String(const char* s);
    String(const String& s);
    // 소멸자
    ~String();
    // 대입 연산자 오버로딩
    String& operator= (const String& s);
    // 복합 대입 연산자 오버로딩
    String& operator+= (const String& s);
    // 동등 비교 연산자 오버로딩
    bool operator== (const String& s);
    // 문자열 연결 연산자 오버로딩
    String operator+ (const String& s);

    // 출력 연산자 오버로딩
    friend ostream& operator<< (ostream& os, const String& s);
    // 입력 연산자 오버로딩
    friend istream& operator>> (istream& is, String& s);
};

// 기본 생성자 구현
String::String()
{
    len = 0;
    str = nullptr; // 포인터를 초기화
}

// 문자열을 받아서 초기화하는 생성자 구현
String::String(const char* s)
{
    len = strlen(s) + 1; // 널 종단 문자까지 고려하여 문자열 길이 계산
    str = new char[len]; // 동적으로 메모리 할당
    strcpy_s(str, len, s); // 문자열 복사
}

// 복사 생성자 구현
String::String(const String& s)
{
    len = s.len;
    str = new char[len];
    strcpy_s(str, len, s.str); // 문자열 복사
}

// 소멸자 구현
String::~String()
{
    if (str != nullptr)
        delete[] str; // 동적으로 할당된 메모리 해제
}

// 대입 연산자 오버로딩
String& String::operator= (const String& s)
{
    if (str != nullptr)
        delete[] str; // 이전 메모리 해제

    len = s.len;
    str = new char[len];
    strcpy_s(str, len, s.str); // 문자열 복사

    return *this;
}

// 복합 대입 연산자 오버로딩
String& String::operator+= (const String& s)
{
    len += (s.len - 1); // 현재 문자열 길이에 추가할 문자열 길이만큼 더함
    char* tempstr = new char[len];
    strcpy_s(tempstr, len, str); // 이전 문자열 복사
    strcat_s(tempstr, len, s.str); // 이후 문자열 추가

    if (str != nullptr)
        delete[] str; // 이전 메모리 해제

    str = tempstr; // 포인터 갱신
    return *this;
}

// 동등 비교 연산자 오버로딩
bool String::operator== (const String& s)
{
    return strcmp(str, s.str) == 0; // strcmp 함수 결과에 따라 true 또는 false 반환
}

// 문자열 연결 연산자 오버로딩
String String::operator+ (const String& s)
{
    char* tempstr = new char[len + s.len - 1];
    strcpy_s(tempstr, len + s.len - 1, str); // 첫 번째 문자열 복사
    strcat_s(tempstr, len + s.len - 1, s.str); // 두 번째 문자열 추가

    String temp(tempstr); // 새로운 String 객체 생성
    delete[] tempstr; // 동적으로 할당된 메모리 해제
    return temp; // 새로운 객체 반환
}

// 출력 연산자 오버로딩
ostream& operator<< (ostream& os, const String& s)
{
    os << s.str; // 문자열 출력
    return os; // 스트림 반환
}

// 입력 연산자 오버로딩
istream& operator>> (istream& is, String& s)
{
    char str[100];
    is >> str; // 문자열 입력 받기
    s = String(str); // 입력 받은 문자열로 String 객체 초기화
    return is; // 스트림 반환
}

int main(void)
{
    String str1 = "I like "; // String 객체 생성 및 초기화
    String str2 = "string class"; // String 객체 생성 및 초기화
    String str3 = str1 + str2; // 두 문자열을 연결하여 새로운 String 객체 생성

    cout << str1 << endl; // 문자열 출력
    cout << str2 << endl; // 문자열 출력
    cout << str3 << endl; // 문자열 출력

    str1 += str2; // 문자열 연결하여 기존 객체에 대입
    if (str1 == str3) // 문자열 동등 비교
        cout << "동일 문자열!" << endl;
    else
        cout << "동일하지 않은 문자열!" << endl;

    String str4; // 빈 문자열 객체 생성
    cout << "문자열 입력: ";
    cin >> str4; // 문자열 입력 받기
    cout << "입력한 문자열: " << str4 << endl; // 입력한 문자열 출력
    return 0;
}
