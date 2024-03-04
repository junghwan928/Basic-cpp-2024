#include <iostream>
#include <string>

using namespace std;

// TV 클래스 정의
class TV {
public:
    virtual void on() = 0;
};

// 삼성 TV 클래스 정의
class SamsungTV : public TV {
public:
    void on() override {
        cout << "Samsung TV is Turn on." << endl;
        cout << endl;
    }
};

// LG TV 클래스 정의
class LGTV : public TV {
public:
    void on() override {
        cout << "LG TV is Turn on." << endl;
        cout << endl;
    }
};

// 리모컨 클래스 정의
class RemoteControl {
private:
    TV* Tv; // 연결된 TV 객체에 대한 포인터
public:
    // 생성자: TV 객체를 연결
    RemoteControl(TV* Tv) : Tv(Tv) {}

    // TV를 켜는 함수
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
    // 삼성 TV 객체 생성
    SamsungTV samsungTV;
    // 리모컨 객체 생성 및 삼성 TV와 연결
    RemoteControl remoteForSamsung(&samsungTV);
    // 리모컨으로 TV를 켬
    remoteForSamsung.on(); // 삼성 TV 켜짐 출력

    // LG TV 객체 생성
    LGTV lgTV;
    // 리모컨 객체 생성 및 LG TV와 연결
    RemoteControl remoteForLG(&lgTV);
    // 리모컨으로 TV를 켬
    remoteForLG.on(); // LG TV 켜짐 출력

    return 0;
}

/*
RemoteControl 클래스, SamsungTv 클래스, LgTv클래스를 설계하고,
remote->on() 호출하면 연결된 TV에 따라서
"삼성tv on" or "엘지tv on" 이 출력 되도록 프로그램 완성
*/