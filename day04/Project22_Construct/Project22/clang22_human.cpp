#include <iostream>
#include <string>

using namespace std;

// human 구조체 정의
struct Human {
    string name;
    int age;
    string job;
    string residentNumber; // 주민등록번호 추가
};

// Human 구조체를 매개변수로 받는 함수 정의
void showHuman(const Human& h1) {
    cout << "name: " << h1.name << ", age: " << h1.age << ", job: " << h1.job << ", resident number: " << h1.residentNumber << endl;
}

int main() {
    // human 구조체 변수 생성 및 초기화
    Human h1 = { "홍길동", 30, "개발자", "123456-1234567" }; // 주민등록번호 추가

    // showHuman 함수 호출하여 구조체 정보 출력
    showHuman(h1);

    return 0;
}
