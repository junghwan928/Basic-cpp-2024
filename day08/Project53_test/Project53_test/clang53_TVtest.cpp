#include <iostream>
#include <string>

using namespace std;

// TV Ŭ���� ����
class TV {
public:
    virtual void on() = 0;
};

// �Ｚ TV Ŭ���� ����
class SamsungTV : public TV {
public:
    void on() override {
        cout << "Samsung TV is Turn on." << endl;
        cout << endl;
    }
};

// LG TV Ŭ���� ����
class LGTV : public TV {
public:
    void on() override {
        cout << "LG TV is Turn on." << endl;
        cout << endl;
    }
};

// ������ Ŭ���� ����
class RemoteControl {
private:
    TV* Tv; // ����� TV ��ü�� ���� ������
public:
    // ������: TV ��ü�� ����
    RemoteControl(TV* Tv) : Tv(Tv) {}

    // TV�� �Ѵ� �Լ�
    void on() {
        if (Tv != nullptr) {
            Tv->on();
        }
        else {
            cout << "TV is not connected." << endl;
        }
    }
};

int main() {
    // �Ｚ TV ��ü ����
    SamsungTV samsungTV;
    // ������ ��ü ���� �� �Ｚ TV�� ����
    RemoteControl remoteForSamsung(&samsungTV);
    // ���������� TV�� ��
    remoteForSamsung.on(); // �Ｚ TV ���� ���

    // LG TV ��ü ����
    LGTV lgTV;
    // ������ ��ü ���� �� LG TV�� ����
    RemoteControl remoteForLG(&lgTV);
    // ���������� TV�� ��
    remoteForLG.on(); // LG TV ���� ���

    return 0;
}

/*
RemoteControl Ŭ����, SamsungTv Ŭ����, LgTvŬ������ �����ϰ�,
remote->on() ȣ���ϸ� ����� TV�� ����
"�Ｚtv on" or "����tv on" �� ��� �ǵ��� ���α׷� �ϼ�
*/