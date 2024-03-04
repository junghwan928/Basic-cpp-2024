#include <iostream>
#include <string>

using namespace std;

// TV Ŭ���� ����
class TV {
public:
    virtual void on() = 0;
};

// ������ Ŭ���� ����
class RemoteControl {
protected:
    TV* tv; // ����� TV ��ü�� ���� ������
public:
    // ������: TV ��ü�� ����
    RemoteControl(TV* tv) : tv(tv) {}

    // TV�� �Ѵ� �Լ�
    virtual void on() {
        if (tv != nullptr) {
            tv->on();
        }
        else {
            cout << "TV�� ������� �ʾҽ��ϴ�." << endl;
        }
    }
};

// �Ｚ TV Ŭ���� ����
class SamsungTV : public RemoteControl {
public:
    SamsungTV() : RemoteControl(this) {} // �Ｚ TV�� ������ ����
    void on() override {
        cout << "�Ｚ TV�� �������ϴ�." << endl;
    }
};

// LG TV Ŭ���� ����
class LGTV : public RemoteControl {
public:
    LGTV() : RemoteControl(this) {} // LG TV�� ������ ����
    void on() override {
        cout << "LG TV�� �������ϴ�." << endl;
    }
};

int main() {
    // �Ｚ TV ��ü ����
    SamsungTV samsungTV;
    // ���������� TV�� ��
    samsungTV.on(); // �Ｚ TV ���� ���

    // LG TV ��ü ����
    LGTV lgTV;
    // ���������� TV�� ��
    lgTV.on(); // LG TV ���� ���

    return 0;
}
