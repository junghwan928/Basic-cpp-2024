#include <iostream>
using namespace std;

// 기본 클래스 Person 정의
class Person
{
public:
    // Sleep 함수: 모든 사람이 할 수 있는 행위
    void Sleep() { cout << "Sleep" << endl; }
};

// Person 클래스를 상속받는 Student 클래스 정의
class Student : public Person
{
public:
    // Study 함수: 학생이 할 수 있는 특별한 행위
    void Study() { cout << "Study" << endl; }
};

// Student 클래스를 상속받는 PartTimeStudent 클래스 정의
class PartTimeStudent : public Student
{
public:
    // Work 함수: 파트타임 학생이 할 수 있는 추가적인 행위
    void Work() { cout << "Work" << endl; }
};

int main(void)
{
    // Person 타입의 포인터로 Student 객체를 동적 할당
    // Student *ptr0 = new Student(); 
    // => 동일한 타입으로 사용하는 것이 원칙, 부모타입의 객체 포인터로 자식 객체를 가리킬수 있음.
    // => 하지만 자식타입의 객체 포인터로 부모 객체는 가리킬수 없음.
    // => 그리고 접근은 객체 포인터의 타입을 따름


    Person* ptr1 = new Student();
    // Person 타입의 포인터로 PartTimeStudent 객체를 동적 할당
    Person* ptr2 = new PartTimeStudent();
    // Student 타입의 포인터로 PartTimeStudent 객체를 동적 할당
    Student* ptr3 = new PartTimeStudent();

    // Person 클래스의 Sleep 함수 호출 (Student, PartTimeStudent 모두 접근 가능)
    ptr1->Sleep(); // 출력: Sleep
    ptr2->Sleep(); // 출력: Sleep

    // Student 클래스의 Study 함수 호출 (PartTimeStudent는 Student를 상속받으므로 접근 가능)
    ptr3->Study(); // 출력: Study

    // 동적 할당된 메모리 해제
    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}

/* 추가 설명
1. Person 클래스는 모든 사람이 공통적으로 할 수 있는 Sleep 행위를 정의.

2. Person 클래스를 상속받은 Student 클래스는 학생이 추가적으로 할 수 있는 Study 행위를 정의.

3. Student 클래스를 다시 상속받은 PartTimeStudent 클래스는 파트타임 학생이 추가적으로 할 수 있는 Work 행위를 정의
*/