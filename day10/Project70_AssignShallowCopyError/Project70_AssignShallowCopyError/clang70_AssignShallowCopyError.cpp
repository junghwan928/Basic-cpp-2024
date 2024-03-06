#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char* name; // 사람의 이름을 저장하는 동적 문자열
    int age; // 사람의 나이

public:
    // 생성자: 이름과 나이를 인자로 받아 객체를 초기화함
    Person(const char* myname, int myage)
    {
        int len = strlen(myname) + 1; // 이름의 길이 + 널 종료 문자
        name = new char[len]; // 이름을 저장할 충분한 크기의 동적 메모리 할당
        strcpy_s(name, len, myname); // strcpy_s를 사용하여 이름을 안전하게 복사
        age = myage; // 나이를 멤버 변수에 저장
    }

    // 복사 생성자: 깊은 복사를 수행하여 객체를 복제함
    Person(const Person& copy) : age(copy.age)
    {
        name = new char[strlen(copy.name) + 1]; // 새로운 메모리 공간을 할당
        strcpy_s(name, strlen(copy.name) + 1, copy.name); // 이름을 안전하게 복사
    }

    // 대입 연산자 오버로딩: 깊은 복사를 수행하여 객체의 값을 다른 객체에 복사함
    Person& operator=(const Person& ref)
    {
        if (this != &ref) // 자기 자신에 대한 대입이 아닌 경우에만 작업을 수행
        {
            delete[] name; // 기존에 할당된 메모리 해제
            int len = strlen(ref.name) + 1; // 새 이름의 길이 + 널 종료 문자
            name = new char[len]; // 새로운 메모리 공간을 할당
            strcpy_s(name, len, ref.name); // 이름을 안전하게 복사
            age = ref.age; // 나이 정보 복사
        }
        return *this; // 현재 객체의 참조를 반환
    }

    // 정보 출력 함수: 객체의 이름과 나이를 출력함
    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }

    // 소멸자: 동적으로 할당된 메모리를 해제함
    ~Person()
    {
        delete[] name; // 동적으로 할당된 메모리 해제
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29); // 첫 번째 사람 객체 생성
    Person man2 = man1; // 복사 생성자를 통해 두 번째 사람 객체 생성 (깊은 복사)
    Person man3("Yoon ji yul", 22); // 세 번째 사람 객체 생성
    man3 = man1; // 대입 연산자를 통해 세 번째 객체에 첫 번째 객체의 값을 복사 (깊은 복사)
    man1.ShowPersonInfo(); // 첫 번째 객체의 정보 출력
    man2.ShowPersonInfo(); // 두 번째 객체의 정보 출력 (깊은 복사 결과 확인)
    man3.ShowPersonInfo(); // 세 번째 객체의 정보 출력 (깊은 복사 결과 확인)
    return 0; // 프로그램 종료
}
