#include <iostream>
/*
* c++ Ÿ���� ����ü: ����ü
*/
typedef struct human { //human ����ü => ���� ���� ����� ���� �ڷ���
	char name[20]; // �Ӽ� �������(name, age, job)
	int age;
	char job[20];

	void showHuman() {
		printf("name: %s, age: %d, job: %s\n", name, age, job);
	}

} Human; // ������ human ����ü�� Human���� ���

int main() {
	int a = 10;
	human h1 = { "Hong", 50, "����" }; //HumanŸ���� ������ �����ϰ� �ʱ�ȭ�� ��Ų��
	h1.showHuman();
	return 0;

}