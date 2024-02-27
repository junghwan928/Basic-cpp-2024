#include <iostream>
using namespace std;

// Simple Ŭ���� ����
class Simple {
public:
    // ������: ��ü�� ������ �� ȣ���
    Simple() {
        cout << "I am Computer!" << endl;
    }

    // �Ҹ���: ��ü�� �Ҹ�� �� ȣ���
    ~Simple() {
        cout << "Destructor called!" << endl;
    }
};

int main(void) {
    cout << "Case 1: ";
    // �������� Simple ��ü ����
    Simple* sp1 = new Simple;

    cout << "Case 2: ";
    // malloc �Լ��� �޸� �Ҵ�
    Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);

    cout << endl << "End of main!" << endl;

    // �������� �Ҵ�� ��ü ����
    delete sp1;
    // malloc���� �Ҵ�� �޸� ����
    free(sp2);

    return 0;
}

/*
1. Simple Ŭ����:

- Simple Ŭ������ �ܼ��� �����ڿ� �Ҹ��ڸ� ������ �ִ� Ŭ����.
- �����ڴ� ��ü�� ������ �� ȣ��Ǿ� "I am Computer!"�� ���.
- �Ҹ��ڴ� ��ü�� �Ҹ�� �� ȣ��Ǿ� "Destructor called!"�� ���.


main �Լ�:

- "Case 1:" ��� ��, new �����ڸ� ����Ͽ� �������� Simple ��ü�� ����. �����ڰ� ȣ��Ǿ� "I am Computer!"�� ���.

- "Case 2:" ��� ��, malloc �Լ��� ����Ͽ� �޸𸮸� �Ҵ��ϰ�, �̸� Simple ��ü�� �����Ϳ� �Ҵ�. 
 -> ������ �����ڰ� ȣ����� �����Ƿ� "I am Computer!"�� ��µ��� �ʽ��ϴ�.

 - "End of main!" ��� ��, ���α׷��� ����.
- ����������, delete �����ڸ� ����Ͽ� �������� �Ҵ�� ��ü�� �����ϰ�, free �Լ��� ����Ͽ� malloc �Լ��� �Ҵ�� �޸𸮸� ����. 
==> �� ��� ��� �Ҹ��ڰ� ȣ��Ǿ� "Destructor called!"�� ���.
===> �̷��� �������� ������ ��ü�� �ʿ� ������ �� �����ϰ� �����Ǿ� �޸� ������ ����
*/