#include <iostream>
#include <string>
using namespace std;

// �л� ������ �����ϴ� Ŭ����
class Student {
private:
    // �л��� �̸��� ����, ����, ���� ����, ����, ����� �����ϴ� ��� ����
    string name;
    int kor, eng, math;
    int total;
    double average;

public:
    // ������: ��� �������� �ʱ�ȭ
    Student() : name(""), kor(0), eng(0), math(0), total(0), average(0.0) {}

    // ����ڷκ��� �л� ���� �Է� �޴� ��� �Լ�
    void readData() {
        cout << "�̸�, ����, ����, ���� ������ �Է��ϼ���: ";
        cin >> name >> kor >> eng >> math;
        calculateTotalAndAverage(); // �Է� ���� �� ������ ��� ���
    }

    // ������ ����� ����ϴ� ��� �Լ�
    void calculateTotalAndAverage() {
        total = kor + eng + math;
        average = total / 3.0;
    }

    // ���� ������ ����� ����ϰ� ����ϴ� ���� ��� �Լ�
    // �� �Լ��� Student ��ü �迭�� ���ڷ� �޾� �� ���� ������ ����� ���
    static void calculateAndPrintTotalsAndAverages(Student* students, int size) {
        int totalKor = 0, totalEng = 0, totalMath = 0;
        for (int i = 0; i < size; ++i) {
            totalKor += students[i].kor;
            totalEng += students[i].eng;
            totalMath += students[i].math;
        }
        cout << "���� ����: " << totalKor << ", ���: " << (totalKor / (double)size) << endl;
        cout << "���� ����: " << totalEng << ", ���: " << (totalEng / (double)size) << endl;
        cout << "���� ����: " << totalMath << ", ���: " << (totalMath / (double)size) << endl;
    }

    // �л��� ������ ����ϴ� ��� �Լ�
    void printData() const {
        cout << "�̸�: " << name << ", ����: " << total << ", ���: " << average << endl;
    }
};

int main() {
    const int SIZE = 5; // �л� ��
    Student students[SIZE]; // �л� ��ü �迭

    // �� �л��� ������ �Է� ����
    for (int i = 0; i < SIZE; ++i) {
        students[i].readData();
    }

    cout << "�� �л��� ������ ���:" << endl;
    // �Է¹��� �л� ����(������ ���) ���
    for (int i = 0; i < SIZE; ++i) {
        students[i].printData();
    }

    cout << "���� ������ ���:" << endl;
    // ���� ������ ��� ��� �� ���
    Student::calculateAndPrintTotalsAndAverages(students, SIZE);

    return 0;
}
