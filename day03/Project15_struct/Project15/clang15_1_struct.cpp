#include <iostream>
#include <string>

using namespace std;

// human ����ü ����
// human ����ü => ���� ���� ����� ���� �ڷ���
// �Ӽ� �������(name, age, job)
struct Human {
    string name;
    int age;
    string job;
};

// Human ����ü�� �Ű������� �޴� �Լ� ����, ����Լ� ���
void showHuman(Human h1) { 
    cout << "name: " << h1.name << ", age: " << h1.age << ", job: " << h1.job << endl;
}

int main() {
    // human ����ü ���� ���� �� �ʱ�ȭ
    Human h1 = { "Hong", 50, "����" };

    // showHuman �Լ� ȣ���Ͽ� ����ü ���� ���
    showHuman(h1);

    return 0;
}
