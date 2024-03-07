#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Grade {
private:
    char* name;
    int kor;
    int math;
    int eng;
    int total;
    double average;

public:
    // 기본 생성자
    Grade() : name(nullptr), kor(0), math(0), eng(0), total(0), average(0.0) {}

    // 생성자: 학생의 이름과 세 과목의 점수를 받아 초기화
    Grade(const char* name, int kor, int math, int eng) {
        // 이름 복사
        size_t len = strlen(name) + 1;
        this->name = new char[len];
        strcpy_s(this->name, len, name);

        // 과목 점수 설정
        this->kor = kor;
        this->math = math;
        this->eng = eng;

        // 총점과 평균 계산
        calculateTotal();
        calculateAverage();
    }

    // 복사 생성자
    Grade(const Grade& other) {
        size_t len = strlen(other.name) + 1;
        this->name = new char[len];
        strcpy_s(this->name, len, other.name);
        this->kor = other.kor;
        this->math = other.math;
        this->eng = other.eng;
        this->total = other.total;
        this->average = other.average;
    }

    // 대입 연산자 오버로딩
    Grade& operator=(const Grade& other) {
        if (this != &other) {
            delete[] name;
            size_t len = strlen(other.name) + 1;
            this->name = new char[len];
            strcpy_s(this->name, len, other.name);
            this->kor = other.kor;
            this->math = other.math;
            this->eng = other.eng;
            this->total = other.total;
            this->average = other.average;
        }
        return *this;
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~Grade() {
        delete[] name;
    }

    // 총점 계산 함수
    void calculateTotal() {
        total = kor + math + eng;
    }

    // 평균 계산 함수
    void calculateAverage() {
        average = total / 3.0;
    }

    // 이름 반환 함수
    const char* getName() const {
        return name;
    }

    // 국어 점수 반환 함수
    int getKor() const {
        return kor;
    }

    // 수학 점수 반환 함수
    int getMath() const {
        return math;
    }

    // 영어 점수 반환 함수
    int getEng() const {
        return eng;
    }

    // 총점 반환 함수
    int getTotal() const {
        return total;
    }

    // 평균 반환 함수
    double getAverage() const {
        return average;
    }
};

int main() {
    int num = 0;

    cout << "성적처리 학생수: ";
    cin >> num;

    vector<Grade> gradeAry(num); // 학생 객체 벡터

    // 학생 정보 입력
    for (int i = 0; i < num; ++i) {
        char name[20];
        int inko, inEng, inmath;

        // 사용자로부터 학생 정보 입력 받음
        cout << "이름: ";
        cin >> name;
        cout << "국어: ";
        cin >> inko;
        cout << "수학: ";
        cin >> inmath;
        cout << "영어: ";
        cin >> inEng;
        cout << endl;

        // Grade 객체 생성 및 정보 설정
        gradeAry[i] = Grade(name, inko, inmath, inEng);
    }

    // 학생 정보 출력
    for (int i = 0; i < num; ++i) {
        cout << "이름: " << gradeAry[i].getName() << endl;
        cout << "국어: " << gradeAry[i].getKor() << ", 수학: " << gradeAry[i].getMath() << ", 영어: " << gradeAry[i].getEng() << endl;
        cout << "총점: " << gradeAry[i].getTotal() << ", 평균: " << gradeAry[i].getAverage() << endl;
        cout << endl;
    }

    return 0;
}
