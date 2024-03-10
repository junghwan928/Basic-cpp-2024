#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    int len;    // 문자열의 길이를 저장하는 변수
    char * str; // 문자열을 저장하는 포인터
public:
    // 기본 생성자
    String();
    // 문자열을 받아 초기화하는 생성자
    String(const char * s);
    // 복사 생성자
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

    // 스트림 출력 연산자 오버로딩을 위한 friend 선언
    friend ostream& operator<< (ostream& os, const String& s);
    // 스트림 입력 연산자 오버로딩을 위한 friend 선언
    friend istream& operator>> (istream& is, String& s);
};

// 기본 생성자
String::String()
{
    len = 0;    // 길이 0으로 초기화
    str = NULL; // NULL로 초기화
}

// 문자열을 받아 초기화하는 생성자
String::String(const char* s)
{
    len = strlen(s) + 1;    // 문자열의 길이 계산
    str = new char[len];    // 동적 할당
    strcpy(str, s);         // 문자열 복사
}

// 복사 생성자
String::String(const String& s)
{
    len = s.len;                // 길이 복사
    str = new char[len];        // 동적 할당
    strcpy(str, s.str);         // 문자열 복사
}

// 소멸자
String::~String() 
{
    if(str != NULL)
        delete [] str; // 동적 할당 해제
}

// 대입 연산자 오버로딩
String& String::operator= (const String& s)
{
    if(str != NULL)
        delete [] str; // 기존 할당된 메모리 해제
    len = s.len;            // 길이 복사
    str = new char[len];    // 새로운 메모리 할당
    strcpy(str, s.str);     // 문자열 복사
    return *this;
}

// 복합 대입 연산자 오버로딩
String& String::operator+= (const String& s)
{
    len += (s.len - 1);             // 새로운 길이 계산
    char* tempstr = new char[len];  // 새로운 메모리 할당
    strcpy(tempstr, str);           // 기존 문자열 복사
    strcat(tempstr, s.str);         // 새로운 문자열 추가
    if(str != NULL)
        delete [] str;              // 이전 메모리 해제
    str = tempstr;                  // 포인터 업데이트
    return *this;
}

// 동등 비교 연산자 오버로딩
bool String::operator== (const String& s)
{
    return strcmp(str, s.str) ? false : true; // strcmp 결과에 따라 true 또는 false 반환
}

// 문자열 연결 연산자 오버로딩
String String::operator+ (const String& s)
{
    char* tempstr = new char[len + s.len - 1]; // 새로운 메모리 할당
    strcpy(tempstr, str);                        // 기존 문자열 복사
    strcat(tempstr, s.str);                      // 새로운 문자열 추가
    String temp(tempstr);                        // 새로운 String 객체 생성
    delete [] tempstr;                           // 메모리 해제
    return temp;                                // 새로운 String 객체 반환
}

// 스트림 출력 연산자 오버로딩
ostream& operator<< (ostream& os, const String& s)
{
    os << s.str; // 문자열 출력
    return os;
}

// 스트림 입력 연산자 오버로딩
istream& operator>> (istream& is, String& s)
{
    char str[100];   // 입력 받을 임시 배열
    is >> str;       // 문자열 입력
    s = String(str); // String 객체로 변환하여 대입
    return is;
}

int main(void)
{
    String str1 = "I like ";    // String 객체 생성
    String str2 = "string class"; // String 객체 생성
    String str3 = str1 + str2;    // 두 문자열 연결하여 새로운 객체 생성

    cout << str1 << endl; // 문자열 출력
    cout << str2 << endl; // 문자열 출력
    cout << str3 << endl; // 문자열 출력

    str1 += str2; // 문자열 연결
    if(str1 == str3)     // 두 문자열이 동일한지 확인
        cout << "동일 문자열!" << endl; // 동일하면 출력
    else
        cout << "동일하지 않은 문자열!" << endl; // 다르면 출력

    String str4; // String 객체 생성
    cout << "문자열 입력: ";
    cin >> str4; // 문자열 입력
    cout << "입력한 문자열: " << str4 << endl; // 입력한 문자열 출력
    return 0;
}
