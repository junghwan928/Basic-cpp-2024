#include <iostream>
#include <string>

using namespace std;

// TV 클래스 정의
class TV {
public:
    virtual void on() = 0;
};

// 리모컨 클래스 정의
class RemoteControl {
protected:
    TV* tv; // 연결된 TV 객체에 대한 포인터
public:
    // 생성자: TV 객체를 연결
    RemoteControl(TV* tv) : tv(tv) {}

    // TV를 켜는 함수
    virtual void on() {
        if (tv != nullptr) {
            tv->on();
        }
        else {
            cout << "TV가 연결되지 않았습니다." << endl;
        }
    }
};

// 삼성 TV 클래스 정의
class SamsungTV : public RemoteControl {
public:
    SamsungTV() : RemoteControl(this) {} // 삼성 TV와 리모컨 연결
    void on() override {
        cout << "삼성 TV가 켜졌습니다." << endl;
    }
};

// LG TV 클래스 정의
class LGTV : public RemoteControl {
public:
    LGTV() : RemoteControl(this) {} // LG TV와 리모컨 연결
    void on() override {
        cout << "LG TV가 켜졌습니다." << endl;
    }
};

int main() {
    // 삼성 TV 객체 생성
    SamsungTV samsungTV;
    // 리모컨으로 TV를 켬
    samsungTV.on(); // 삼성 TV 켜짐 출력

    // LG TV 객체 생성
    LGTV lgTV;
    // 리모컨으로 TV를 켬
    lgTV.on(); // LG TV 켜짐 출력

    return 0;
}
