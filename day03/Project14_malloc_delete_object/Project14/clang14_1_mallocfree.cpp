#include <iostream>
#include <string.h>
#include <cstdlib> // <stdlib.h> ��� <cstdlib> ����� ��


#define _CRT_SECURE_NO_WARNINGS


using namespace std;

char* MakeStrAdr(int len)
{
    char* str = (char*)malloc(sizeof(char) * len); // C: HEAP������ �޸� �Ҵ� => 20byte ũ��
    printf("char size : %llu\n", sizeof(char));
    return str;
}
/* 
1. MakeStrAdr �Լ� => ���� len�� �Ű������� �޾Ƽ� ���̰� len�� ���ڿ��� �������� �Ҵ�.
2. malloc �Լ� => ����Ͽ� len��ŭ�� �޸𸮸� �������� �Ҵ��ϰ�, 
               => �� �޸��� ���� �ּҸ� ����Ű�� ������ str�� ��ȯ.
*/


int main(void) {
    char* str = MakeStrAdr(20);
    strcpy(str, "I am So Happy~");
    cout << str << endl;
    free(str);

    return 0;
}


	/* 
    1. main �Լ� => ���� MakeStrAdr �Լ��� ȣ���Ͽ� ���̰� 20�� ���ڿ��� �Ҵ��ϰ� �̿� ���� �����͸� str�� ����.
	2. strcpy �Լ��� ����Ͽ� "I am So Happy~"��� ���ڿ��� str�� ����Ű�� �޸𸮿� ����.
	3. cout�� ����Ͽ� str�� ����Ű�� ���ڿ��� ���.
    4. ���������� free �Լ��� ����Ͽ� str�� ����Ű�� �޸𸮸� ����.*/
