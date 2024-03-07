#include <iostream>
#include <string>
using namespace std;

// 학생 정보를 관리하는 클래스
class Student {
private:
    // 학생의 이름과 국어, 영어, 수학 점수, 총점, 평균을 저장하는 멤버 변수
    string name;
    int kor, eng, math;
    int total;
    double average;

public:
    // 생성자: 멤버 변수들을 초기화
    Student() : name(""), kor(0), eng(0), math(0), total(0), average(0.0) {}

    // 사용자로부터 학생 정보 입력 받는 멤버 함수
    void readData() {
        cout << "이름, 국어, 영어, 수학 점수를 입력하세요: ";
        cin >> name >> kor >> eng >> math;
        calculateTotalAndAverage(); // 입력 받은 후 총점과 평균 계산
    }

    // 총점과 평균을 계산하는 멤버 함수
    void calculateTotalAndAverage() {
        total = kor + eng + math;
        average = total / 3.0;
    }

    // 과목별 총점과 평균을 계산하고 출력하는 정적 멤버 함수
    // 이 함수는 Student 객체 배열을 인자로 받아 각 과목별 총점과 평균을 계산
    static void calculateAndPrintTotalsAndAverages(Student* students, int size) {
        int totalKor = 0, totalEng = 0, totalMath = 0;
        for (int i = 0; i < size; ++i) {
            totalKor += students[i].kor;
            totalEng += students[i].eng;
            totalMath += students[i].math;
        }
        cout << "국어 총점: " << totalKor << ", 평균: " << (totalKor / (double)size) << endl;
        cout << "영어 총점: " << totalEng << ", 평균: " << (totalEng / (double)size) << endl;
        cout << "수학 총점: " << totalMath << ", 평균: " << (totalMath / (double)size) << endl;
    }

    // 학생의 정보를 출력하는 멤버 함수
    void printData() const {
        cout << "이름: " << name << ", 총점: " << total << ", 평균: " << average << endl;
    }
};

int main() {
    const int SIZE = 5; // 학생 수
    Student students[SIZE]; // 학생 객체 배열

    // 각 학생의 정보를 입력 받음
    for (int i = 0; i < SIZE; ++i) {
        students[i].readData();
    }

    cout << "각 학생별 총점과 평균:" << endl;
    // 입력받은 학생 정보(총점과 평균) 출력
    for (int i = 0; i < SIZE; ++i) {
        students[i].printData();
    }

    cout << "과목별 총점과 평균:" << endl;
    // 과목별 총점과 평균 계산 및 출력
    Student::calculateAndPrintTotalsAndAverages(students, SIZE);

    return 0;
}
