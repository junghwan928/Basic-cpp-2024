#include <iostream>
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
    const int NUM_STUDENTS = 1;
    Grade grade[NUM_STUDENTS];    // 학생 객체 배열


    int korTotal = 0, mathTotal = 0, engTotal = 0; // 각 과목의 총점을 저장할 변수 초기화

    // 5명의 학생 정보 입력
    for (int i = 0; i < NUM_STUDENTS; ++i) {
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
        grade[i] = Grade(name, inko, inmath, inEng);

        // 각 과목의 총점 누적
        korTotal += inko;
        mathTotal += inmath;
        engTotal += inEng;
    }

    // 각 과목의 평균 계산
    double korAverage = static_cast<double>(korTotal) / NUM_STUDENTS;
    double mathAverage = static_cast<double>(mathTotal) / NUM_STUDENTS;
    double engAverage = static_cast<double>(engTotal) / NUM_STUDENTS;

    // 학생 정보와 각 과목의 총점 및 평균 출력
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "이름: " << grade[i].getName() << endl;
        cout << "국어: " << grade[i].getKor() << ", 수학: " << grade[i].getMath() << ", 영어: " << grade[i].getEng() << endl;
        cout << "총점: " << grade[i].getTotal() << ", 평균: " << grade[i].getAverage() << endl;
        cout << endl;
    }

    // 각 과목의 총점과 평균 출력
    cout << "국어 과목의 총점 : " << korTotal << ", 평균 : " << korAverage << endl;
    cout << "수학 과목의 총점: " << mathTotal << ", 평균: " << mathAverage << endl;
    cout << "영어 과목의 총점: " << engTotal << ", 평균: " << engAverage << endl;

    return 0;
}
