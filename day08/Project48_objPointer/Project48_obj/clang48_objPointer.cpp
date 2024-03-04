#include <iostream>
using namespace std;

// �⺻ Ŭ���� Person ����
class Person
{
public:
    // Sleep �Լ�: ��� ����� �� �� �ִ� ����
    void Sleep() { cout << "Sleep" << endl; }
};

// Person Ŭ������ ��ӹ޴� Student Ŭ���� ����
class Student : public Person
{
public:
    // Study �Լ�: �л��� �� �� �ִ� Ư���� ����
    void Study() { cout << "Study" << endl; }
};

// Student Ŭ������ ��ӹ޴� PartTimeStudent Ŭ���� ����
class PartTimeStudent : public Student
{
public:
    // Work �Լ�: ��ƮŸ�� �л��� �� �� �ִ� �߰����� ����
    void Work() { cout << "Work" << endl; }
};

int main(void)
{
    // Person Ÿ���� �����ͷ� Student ��ü�� ���� �Ҵ�
    Person* ptr1 = new Student();
    // Person Ÿ���� �����ͷ� PartTimeStudent ��ü�� ���� �Ҵ�
    Person* ptr2 = new PartTimeStudent();
    // Student Ÿ���� �����ͷ� PartTimeStudent ��ü�� ���� �Ҵ�
    Student* ptr3 = new PartTimeStudent();

    // Person Ŭ������ Sleep �Լ� ȣ�� (Student, PartTimeStudent ��� ���� ����)
    ptr1->Sleep(); // ���: Sleep
    ptr2->Sleep(); // ���: Sleep

    // Student Ŭ������ Study �Լ� ȣ�� (PartTimeStudent�� Student�� ��ӹ����Ƿ� ���� ����)
    ptr3->Study(); // ���: Study

    // ���� �Ҵ�� �޸� ����
    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}

/* �߰� ����
1. Person Ŭ������ ��� ����� ���������� �� �� �ִ� Sleep ������ ����.

2. Person Ŭ������ ��ӹ��� Student Ŭ������ �л��� �߰������� �� �� �ִ� Study ������ ����.

3. Student Ŭ������ �ٽ� ��ӹ��� PartTimeStudent Ŭ������ ��ƮŸ�� �л��� �߰������� �� �� �ִ� Work ������ ����
*/