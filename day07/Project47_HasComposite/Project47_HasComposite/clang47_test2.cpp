#include <iostream>
#include <cstring>
using namespace std;

class Myclass {
private:
    char name[30];
    int age;

public:
    // �̸��� ���̸� �����ϴ� ��� �Լ�
    void setNameAge(const char* _name, int _age) {
        strncpy_s(name, _name, sizeof(name)); // ���ڿ� ���� (_name�� ���̸� �ʰ��ϸ� �ڵ����� NULL ���� �߰�)
        age = _age;
    }

    // �̸��� ��ȯ�ϴ� ��� �Լ�
    const char* getName() const {
        return name;
    }

    // ���̸� ��ȯ�ϴ� ��� �Լ�
    int getAge() const {
        return age;
    }
};

class MyInfo : public Myclass {
private:
    char pNumber[20]; // ��ȭ��ȣ�� �����ϴ� ��� ����

public:
    // ��ȭ��ȣ�� �����ϴ� ��� �Լ�
    void setPhoneNumber(const char* _pNumber) {
        strncpy_s(pNumber, _pNumber, sizeof(pNumber)); // ���ڿ� ���� (_pNumber�� ���̸� �ʰ��ϸ� �ڵ����� NULL ���� �߰�)
    }

    // ���� ������ ����ϴ� ��� �Լ�
    void printMyInfo() {
        cout << "���� �̸��� " << getName() << "�̰� ���̴� " << getAge() << "���̸� ��ȭ��ȣ�� " << pNumber << "�Դϴ�." << endl;
    }
};

int main() {
    MyInfo myInfoObj; // MyInfo ��ü ����

    myInfoObj.setNameAge("LEE", 28); // �̸��� ���� ����
    myInfoObj.setPhoneNumber("010-5888-9280"); // ��ȭ��ȣ ����
    myInfoObj.printMyInfo(); // ���� ���

    return 0;
}

/* �߰� ����
1. Myclass: �̸��� ���̸� �����ϴ� Ŭ����. 
    -> setNameAge �Լ��� �̸��� ���̸� �����ϰ�, getName�� getAge �Լ��� �̸��� ���̸� ��ȯ.

2. MyInfo: Myclass�� ��ӹ��� Ŭ������, ��ȭ��ȣ�� �߰��� �����ϴ� Ŭ����. 
    -> setPhoneNumber �Լ��� ��ȭ��ȣ�� �����ϰ�, printMyInfo �Լ��� �̸�, ����, ��ȭ��ȣ�� ���.

*/