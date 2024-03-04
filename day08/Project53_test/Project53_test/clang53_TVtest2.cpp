#include <iostream>
#include <string>
#include <cstdlib> // srand, rand �Լ��� ����ϱ� ���� ����
#include <ctime>   // time �Լ��� ����ϱ� ���� ����

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
        cout << "Samsung TV is turned on." << endl;
    }
};

// LG TV Ŭ���� ����
class LGTV : public TV {
public:
    void on() override {
        cout << "LG TV is turned on." << endl;
    }
};

// ������ Ŭ���� ����
class RemoteControl {
private:
    TV* tv; // ����� TV ��ü�� ���� ������
public:
    // ������: TV ��ü�� ����
    RemoteControl(TV* tv) : tv(tv) {}

    // TV�� �Ѵ� �Լ�
    void on() {
        if (tv != nullptr) {
            tv->on();
        }
        else {
            cout << "TV is not connected." << endl;
        }
    }
};

int main() {
    // �Ｚ TV ��ü ����
    SamsungTV samsungTV;
    // LG TV ��ü ����
    LGTV lgTV;

    // TV ��ü���� �迭�� ����
    TV* tvs[] = { &samsungTV, &lgTV };

    // ���� ������ �ʱ�ȭ
    srand(time(nullptr));

    // 0 �Ǵ� 1�� ������ ���� �����Ͽ� �ش��ϴ� TV�� ��
    int randomIndex = rand() % 2;
    RemoteControl remote(tvs[randomIndex]);
    remote.on(); // �����ϰ� ���õ� TV ���� ���

    return 0;
}
