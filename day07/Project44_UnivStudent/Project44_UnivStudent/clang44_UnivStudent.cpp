#include <iostream>
#include <cstring> // strcpy_s를 사용하기 위한 헤더 파일 포함
using namespace std;

class Person
{
private:
    char name[50];
    int age;

public:
    // 생성자: 이름과 나이를 인자로 받아 멤버 변수를 초기화함
    Person(const char* myname, int myage) : age(myage)
    {
        strcpy_s(name, myname); // strcpy_s 함수를 사용하여 문자열 복사
    }

    // 이름을 출력하는 멤버 함수
    void whatYourName() const
    {
        cout << "My name is " << name << endl;
    }

    // 나이를 출력하는 멤버 함수
    void howOldAreYou() const
    {
        cout << "I am " << age << " years old" << endl;
    }
};

class UnivStudent : public Person // Person 클래스를 상속받음
{
private:
    char major[50]; // 전공을 나타내는 멤버 변수 추가

public:
    // 생성자: 이름, 나이, 전공을 인자로 받아 초기화
    UnivStudent(const char* myname, int myage, const char* mymajor) : Person(myname, myage)
    {
        strcpy_s(major, mymajor); // strcpy_s 함수를 사용하여 문자열 복사
    }

    // 개인 정보를 출력하는 멤버 함수
    void whoAreYou() const
    {
        whatYourName();
        howOldAreYou();
        cout << "My Major is " << major << endl;
        cout << endl;
    }
};

int main()
{
    // UnivStudent 객체 생성 및 초기화
    UnivStudent student1("John", 20, "Computer Science");
    student1.whoAreYou();

    UnivStudent student2("Lee", 21, "Electronic Eng.");
    student2.whoAreYou();

    return 0;
}

/*
1. Person 클래스:
    - name과 age 멤버 변수를 가지고 있습니다. name은 문자열을 저장하기 위한 배열이며, age는 정수형으로 나이를 저장함.
    - Person 클래스의 생성자는 이름(myname)과 나이(myage)를 인자로 받아 객체를 초기화합니다. 이때 strcpy_s 함수를 사용하여 이름을 복사함.
    - whatYourName() 함수는 객체의 이름을 출력함.
    - howOldAreYou() 함수는 객체의 나이를 출력함.

    
2. UnivStudent 클래스:
    - Person 클래스를 상속.
    - major 멤버 변수를 추가로 가지고 있습니다. 이는 학생의 전공을 나타냄.
    - UnivStudent 클래스의 생성자는 이름(myname), 나이(myage), 전공(mymajor)을 인자로 받아 객체를 초기화합니다. 이때 strcpy_s 함수를 사용하여 전공을 복사함.
    - whoAreYou() 함수는 Person 클래스의 whatYourName()과 howOldAreYou() 함수를 호출하여 학생의 이름, 나이, 전공을 출력합니다.


3. main() 함수:
    - UnivStudent 객체인 student1과 student2를 생성하고 초기화.
    - student1과 student2의 정보를 각각 출력.
*/