#include <iostream> // 표준 입출력 라이브러리 헤더 파일을 포함함.

namespace mystd // mystd 네임스페이스를 정의함.
{
    using namespace std; // 표준 네임스페이스(std)를 사용함.

    class ostream // 사용자 정의 ostream 클래스를 정의함.
    {
    public:
        // const char* 형식의 문자열 출력을 처리하는 연산자 오버로딩.
        void operator<< (const char* str)
        {
            printf("%s", str); // 문자열을 출력함.
        }

        // char 형식의 문자 출력을 처리하는 연산자 오버로딩.
        void operator<< (char str)
        {
            printf("%c", str); // 문자를 출력함.
        }

        // int 형식의 정수 출력을 처리하는 연산자 오버로딩.
        void operator<< (int num)
        {
            printf("%d", num); // 정수를 출력함.
        }

        // double 형식의 실수 출력을 처리하는 연산자 오버로딩.
        void operator<< (double e)
        {
            printf("%g", e); // 실수를 출력함.
        }

        // 사용자 정의 함수 포인터를 받아들여 처리하는 연산자 오버로딩.
        void operator<< (ostream& (*fp)(ostream& ostm))
        {
            fp(*this); // 함수 포인터를 호출하여 출력을 처리함.
        }
    };

    // 사용자 정의 endl 함수를 정의함. 이 함수는 개행 문자를 출력하고 출력 버퍼를 비움.
    ostream& endl(ostream& ostm)
    {
        ostm << '\n'; // 개행 문자를 출력함.
        fflush(stdout); // 출력 버퍼를 비움.
        return ostm; // ostream 객체를 반환함.
    }

    ostream cout; // 사용자 정의 ostream 객체를 생성함.
}

// 메인 함수
int main(void)
{
    using mystd::cout; // mystd 네임스페이스의 cout을 사용함.
    using mystd::endl; // mystd 네임스페이스의 endl을 사용함.

    cout << "Simple String"; // 문자열을 출력함.
    cout << endl; // 개행 문자를 출력하고 출력 버퍼를 비움.
    cout << 3.14; // 실수를 출력함.
    cout << endl; // 개행 문자를 출력하고 출력 버퍼를 비움.
    cout << 123; // 정수를 출력함.
    endl(cout); // 개행 문자를 출력하고 출력 버퍼를 비움.

    return 0; // 프로그램 종료
}
