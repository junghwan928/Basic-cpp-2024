
#include <iostream>
using namespace std;
int main() 
{
	int code = 97;
	cout << code << endl;
	cout <<  (char)code << endl;
	cout << "============================================================" << endl;
	char ary[6] = { 'a','b','c','d','e'}; // 문자열 타입의 배열 선언
	cout << ary << endl;
	printf("============================================================\n");
	char ary1[6] = { 'a','b','c','\0','e'}; // 널 문자 - 문자열의 끝을 알림.
	cout << ary1 << endl;
	cout << sizeof(ary1) << endl; // 전체 문자 크기
	cout << strlen(ary1) << endl; // 널문자 앞의 크기
	printf("============================================================\n");
	char str[] = "string";	// 자동으로 널문자가 붙음.
	cout << str << endl;
	cout << sizeof(str) << endl; // 널문자가 포함된 크기가 리턴 -> 배열의 크기를 바이트 단위로 출력 -> `str` 배열은 널 종단 문자를 포함하여 총 7바이트의 공간을 차지
	cout << strlen(str) << endl; // 문자열의 길이를 출력 ->   널 종단 문자를 제외한 문자열의 길이를 반환
	str[0] = 'S';
	cout << str << endl;
	printf("============================================================\n");
	const char* pstr = "STRING";
	cout << pstr << endl;
	cout << sizeof(pstr) << endl; // 널문자가 포함된 크기가 리턴
	cout << strlen(pstr) << endl; 
	int a = 100;
	int* pa = &a;
	cout << sizeof(pa) << endl;
	cout << strlen(pstr) << endl;
	// pstr[0] = 's'; => 문자열을 포인터로 사용하는 경우는 변경 불가
	cout << endl;
	printf("============================================================\n");


/*
	C++ Style : heap 영역에 저장 
*/
	string s = "string";
	cout << s << endl;
	cout << sizeof(s) << endl; // string 객체의 크기를 출력(객체의 크기가 아닌 구현에 따라 다양한 크기를 가질 수 있음)
	// cout << strlen(s) << endl;
	cout << s.size() << endl; // 문자열의 길이를 출력하는 string 클래스의 멤버 함수인 size()를 사용하여 문자열 길이 출력
	cout << "============================================================" << endl;

	string s1 = "Hong Gill Dong";
	cout << s1 << endl;
	cout << sizeof(s1) << endl; // string 객체의 크기를 출력
	cout << s1.size() << endl; // 문자열의 길이를 출력하는 string 클래스의 멤버 함수인 size()를 사용하여 문자열 길이 출력

	
	string s2 = "Hi";
	string s3 = "U";
	string s4 = s2 +' ' + s3;

	cout << s4 << endl;
	return 0;

}


