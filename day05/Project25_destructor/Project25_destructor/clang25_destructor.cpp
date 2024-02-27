#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;  // ���ڿ��� �����ϱ� ���� ������ ��� ����
    int age;     // ���̸� �����ϴ� ��� ����

public:
    // ������: �̸��� ���̸� �޾� ��� ������ �ʱ�ȭ��
    Person(const char* myname, int myage) { // �Է� 2���� ���� ������
        // ���ڿ��� ���̸� ����Ͽ� �������� �޸𸮸� �Ҵ��ϰ� �̸��� ������
        int len = strlen(myname) + 1;  // strlen()�� ���ڿ��� ���̸� ���ϴ� �Լ�
        name = new char[len];
        cout << "char Size: " << sizeof(char) << endl;
        cout << endl;
        strcpy_s(name, len, myname);

        age = myage;  // ���̸� �ʱ�ȭ��
    }

    // ��ü�� ������ ����ϴ� �Լ�
    void ShowPersonInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << endl;
    }

    // �Ҹ���: �������� �Ҵ�� �޸𸮸� ������
    ~Person() {
        delete[] name;  // �������� �Ҵ�� �޸𸮸� ������
        cout << "Call Destructor" << endl;
    }
};

int main(void) {
    // Person Ŭ������ �̿��Ͽ� �� ���� ��ü�� ������
    Person man1("Lee", 29);
    Person man2("Jang", 41);

    // ��ü�� ������ �����
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}
/*
1. Person Ŭ������ �����ϰ�, 
-> �ش� Ŭ������ ��ü�� �����Ͽ� ����� �̸��� ���̸� �����ϰ� ����ϴ� ����

2.Person Ŭ������ ���ڿ��� �����ϱ� ���� name ��� ������ ���̸� �����ϱ� ���� age ��� ������ ������ ����
-> �����ڴ� ��ü�� ������ �� �̸��� ���̸� �޾Ƽ� ��� ������ �ʱ�ȭ
--> name ��� ������ ���ؼ��� �������� �޸𸮸� �Ҵ��Ͽ� ���ڿ��� ����
---> �Ҹ��ڴ� ��ü�� �Ҹ�� �� �������� �Ҵ�� �޸𸮸� ����

3. main �Լ������� Person Ŭ������ �� ���� ��ü�� �����ϰ� �� ��ü�� ������ ���
*/