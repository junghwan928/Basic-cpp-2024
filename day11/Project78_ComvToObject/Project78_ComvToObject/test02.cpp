#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 학생 정보를 관리하는 클래스
class Student {
private:
    string name;
    int kor, eng, math;
    int total;
    double average;

public:
    Student() : name(""), kor(0), eng(0), math(0), total(0), average(0.0) {}

    void readData() {
        cout << "이름, 국어, 영어, 수학 점수를 입력하세요: ";
        cin >> name >> kor >> eng >> math;
        calculateTotalAndAverage();
    }

    void calculateTotalAndAverage() {
        total = kor + eng + math;
        average = total / 3.0;
    }

    static void calculateAndPrintTotalsAndAverages(Student** students, int size) {
        int totalKor = 0, totalEng = 0, totalMath = 0;
        for (int i = 0; i < size; ++i) {
            totalKor += students[i]->kor;
            totalEng += students[i]->eng;
            totalMath += students[i]->math;
        }
        cout << "국어 총점: " << totalKor << ", 평균: " << (totalKor / (double)size) << endl;
        cout << "영어 총점: " << totalEng << ", 평균: " << (totalEng / (double)size) << endl;
        cout << "수학 총점: " << totalMath << ", 평균: " << (totalMath / (double)size) << endl;
    }

    void printData() const {
        cout << "이름: " << name << ", 총점: " << total << ", 평균: " << average << endl;
    }
};

int main() {
    const int SIZE = 5;
    // 포인터 배열을 사용하여 학생 객체들을 동적으로 관리
    Student* students[SIZE];

    // 각 학생 정보를 동적으로 생성하고 데이터 입력
    for (int i = 0; i < SIZE; ++i) {
        students[i] = new Student(); // 동적 할당
        students[i]->readData();
    }

    cout << "각 학생별 총점과 평균:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        students[i]->printData();
    }

    cout << "과목별 총점과 평균:" << endl;
    // 포인터를 사용하여 정적 멤버 함수 호출
    Student::calculateAndPrintTotalsAndAverages(students, SIZE);

    // 할당된 메모리 해제
    for (int i = 0; i < SIZE; ++i) {
        delete students[i];
    }

    return 0;
}
