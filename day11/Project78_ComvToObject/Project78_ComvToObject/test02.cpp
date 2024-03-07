#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �л� ������ �����ϴ� Ŭ����
class Student {
private:
    string name;
    int kor, eng, math;
    int total;
    double average;

public:
    Student() : name(""), kor(0), eng(0), math(0), total(0), average(0.0) {}

    void readData() {
        cout << "�̸�, ����, ����, ���� ������ �Է��ϼ���: ";
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
        cout << "���� ����: " << totalKor << ", ���: " << (totalKor / (double)size) << endl;
        cout << "���� ����: " << totalEng << ", ���: " << (totalEng / (double)size) << endl;
        cout << "���� ����: " << totalMath << ", ���: " << (totalMath / (double)size) << endl;
    }

    void printData() const {
        cout << "�̸�: " << name << ", ����: " << total << ", ���: " << average << endl;
    }
};

int main() {
    const int SIZE = 5;
    // ������ �迭�� ����Ͽ� �л� ��ü���� �������� ����
    Student* students[SIZE];

    // �� �л� ������ �������� �����ϰ� ������ �Է�
    for (int i = 0; i < SIZE; ++i) {
        students[i] = new Student(); // ���� �Ҵ�
        students[i]->readData();
    }

    cout << "�� �л��� ������ ���:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        students[i]->printData();
    }

    cout << "���� ������ ���:" << endl;
    // �����͸� ����Ͽ� ���� ��� �Լ� ȣ��
    Student::calculateAndPrintTotalsAndAverages(students, SIZE);

    // �Ҵ�� �޸� ����
    for (int i = 0; i < SIZE; ++i) {
        delete students[i];
    }

    return 0;
}
