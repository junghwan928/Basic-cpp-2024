#include <iostream>
/*
CŸ���� ����ü
*/
typedef struct human { //human ����ü => ���� ���� ����� ���� �ڷ���
	char name[20]; // �Ӽ� �������(name, age, job)
	int age;
	char job[20];

} Human; // ������ human ����ü�� Human���� ���

void showHuman(Human h1) {
	printf("name: %s, age: %d, job: %s\n", h.name, h.age, h.job);
}

int main() {
	int a;
	human h1 = { "Hong", 50, "����" }; //HumanŸ���� ������ �����ϰ� �ʱ�ȭ�� ��Ų��
	showHuman(h1);
	return 0;

}