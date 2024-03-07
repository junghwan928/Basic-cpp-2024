#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Grade {
private:
    char name[5];
    int kr;
    int math;
    int english;

public:
    Grade() {
        kr = 0;
        math = 0;
        english = 0;
    }

    // 이름과 과목 점수를 설정하는 함수
    void setInfo(const char n[], int k, int m, int e) {
        strcpy_s(name, sizeof(name), n);
        kr = k;
        math = m;
        english = e;
    }

    // 이름을 반환하는 함수
    const char* getName() const {
        return name;
    }

    // 국어 점수를 반환하는 함수
    int getKoreanScore() const {
        return kr;
    }

    // 수학 점수를 반환하는 함수
    int getMathScore() const {
        return math;
    }

    // 영어 점수를 반환하는 함수
    int getEnglishScore() const {
        return english;
    }

    // 총점을 계산하는 함수
    int getTotalScore() const {
        return kr + math + english;
    }

    // 평균을 계산하는 함수
    double getAverageScore() const {
        return static_cast<double>(getTotalScore()) / 3.0;
    }
};

int main() {
    const int NUM_STUDENTS = 5;
    Grade students[NUM_STUDENTS];

    // 사용자로부터 5명의 학생 이름과 세 과목의 점수를 입력받음
    cout << "5명의 학생의 이름과 세 과목의 점수를 입력하세요:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        char name[5];
        int kr, math, english;
        cout << "학생 " << i + 1 << " 이름: ";
        cin >> name;
        cout << name << " 학생의 국어, 수학, 영어 점수를 입력하세요: ";
        cin >> kr >> math >> english;
        students[i].setInfo(name, kr, math, english);
    }

    // 각 학생의 이름과 점수를 출력
    cout << "\n각 학생의 점수:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "이름: " << students[i].getName()
            << ", 국어: " << students[i].getKoreanScore()
            << ", 수학: " << students[i].getMathScore()
            << ", 영어: " << students[i].getEnglishScore()
            << ", 총점: " << students[i].getTotalScore()
            << ", 평균: " << students[i].getAverageScore() << endl;
    }

    return 0;
}
