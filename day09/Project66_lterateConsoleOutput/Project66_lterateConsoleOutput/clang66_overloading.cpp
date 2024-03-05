#include <iostream>
using namespace std;

class Myclass {
private:
    int num; // Myclass�� ��� ������ ������ num ����

public:
    // ������: ���ڷ� ���� ���� ���� ��� ���� num�� �ʱ�ȭ
    Myclass(int v) : num(v) {}

    // ���� ������: �ٸ� Myclass ��ü�� �޾ƿͼ� �� ��ü�� num�� �����Ͽ� �ʱ�ȭ
    Myclass(const Myclass& other) : num(other.num) {}

    // print �Լ�: ��ü�� value�� ���
    void print() {
        cout << "Value: " << num << endl;
    }

    // ���� ������ �����ε�: �� Myclass ��ü�� num�� ���� ����� ������ ���ο� Myclass ��ü�� ��ȯ
    Myclass operator+(const Myclass& other) const {
        return Myclass(num + other.num);
    }
};

int main() {
    Myclass a(10); // Myclass ��ü a�� �����ϰ� num�� 10���� �ʱ�ȭ
    a.print(); // a�� num ��� (Value: 10)

    Myclass b(a); // Myclass ��ü b�� �����ϰ� a�� num�� �ʱ�ȭ
    b.print(); // b�� num ��� (Value: 10)

    Myclass c = b; // Myclass ��ü c�� �����ϰ� b�� num�� �ʱ�ȭ
    c.print(); // c�� num ��� (Value: 10)

    Myclass d = a + b + c; // a, b, c�� value�� ���� ����� Myclass ��ü d�� ����
    d.print(); // d�� num ��� (Value: 30)

    return 0;
}