#include <iostream>
#include <string>
#include <cstdlib> // srand, rand 함수를 사용하기 위해 포함
#include <ctime>   // time 함수를 사용하기 위해 포함

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
        cout << "Samsung TV is turned on." << endl;
    }
};

// LG TV 클래스 정의
class LGTV : public TV {
public:
    void on() override {
        cout << "LG TV is turned on." << endl;
    }
};

// 리모컨 클래스 정의
class RemoteControl {
private:
    TV* tv; // 연결된 TV 객체에 대한 포인터
public:
    // 생성자: TV 객체를 연결
    RemoteControl(TV* tv) : tv(tv) {}

    // TV를 켜는 함수
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
    // 삼성 TV 객체 생성
    SamsungTV samsungTV;
    // LG TV 객체 생성
    LGTV lgTV;

    // TV 객체들을 배열에 저장
    TV* tvs[] = { &samsungTV, &lgTV };

    // 난수 생성기 초기화
    srand(time(nullptr));

    // 0 또는 1의 랜덤한 값을 생성하여 해당하는 TV를 켬
    int randomIndex = rand() % 2;
    RemoteControl remote(tvs[randomIndex]);
    remote.on(); // 랜덤하게 선택된 TV 켜짐 출력

    return 0;
}
