
#include <iostream>
using namespace std;
int main() 
{
	int code = 97;
	cout << code << endl;
	cout <<  (char)code << endl;
	cout << "============================================================" << endl;
	char ary[6] = { 'a','b','c','d','e'}; // ���ڿ� Ÿ���� �迭 ����
	cout << ary << endl;
	printf("============================================================\n");
	char ary1[6] = { 'a','b','c','\0','e'}; // �� ���� - ���ڿ��� ���� �˸�.
	cout << ary1 << endl;
	cout << sizeof(ary1) << endl; // ��ü ���� ũ��
	cout << strlen(ary1) << endl; // �ι��� ���� ũ��
	printf("============================================================\n");
	char str[] = "string";	// �ڵ����� �ι��ڰ� ����.
	cout << str << endl;
	cout << sizeof(str) << endl; // �ι��ڰ� ���Ե� ũ�Ⱑ ���� -> �迭�� ũ�⸦ ����Ʈ ������ ��� -> `str` �迭�� �� ���� ���ڸ� �����Ͽ� �� 7����Ʈ�� ������ ����
	cout << strlen(str) << endl; // ���ڿ��� ���̸� ��� ->   �� ���� ���ڸ� ������ ���ڿ��� ���̸� ��ȯ
	str[0] = 'S';
	cout << str << endl;
	printf("============================================================\n");
	const char* pstr = "STRING";
	cout << pstr << endl;
	cout << sizeof(pstr) << endl; // �ι��ڰ� ���Ե� ũ�Ⱑ ����
	cout << strlen(pstr) << endl; 
	int a = 100;
	int* pa = &a;
	cout << sizeof(pa) << endl;
	cout << strlen(pstr) << endl;
	// pstr[0] = 's'; => ���ڿ��� �����ͷ� ����ϴ� ���� ���� �Ұ�
	cout << endl;
	printf("============================================================\n");


/*
	C++ Style : heap ������ ���� 
*/
	string s = "string";
	cout << s << endl;
	cout << sizeof(s) << endl; // string ��ü�� ũ�⸦ ���(��ü�� ũ�Ⱑ �ƴ� ������ ���� �پ��� ũ�⸦ ���� �� ����)
	// cout << strlen(s) << endl;
	cout << s.size() << endl; // ���ڿ��� ���̸� ����ϴ� string Ŭ������ ��� �Լ��� size()�� ����Ͽ� ���ڿ� ���� ���
	cout << "============================================================" << endl;

	string s1 = "Hong Gill Dong";
	cout << s1 << endl;
	cout << sizeof(s1) << endl; // string ��ü�� ũ�⸦ ���
	cout << s1.size() << endl; // ���ڿ��� ���̸� ����ϴ� string Ŭ������ ��� �Լ��� size()�� ����Ͽ� ���ڿ� ���� ���

	
	string s2 = "Hi";
	string s3 = "U";
	string s4 = s2 +' ' + s3;

	cout << s4 << endl;
	return 0;

}


