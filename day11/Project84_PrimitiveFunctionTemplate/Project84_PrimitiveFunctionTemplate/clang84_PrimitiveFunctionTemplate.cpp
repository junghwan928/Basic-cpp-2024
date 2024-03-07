#include <iostream>
using namespace std;

// ���ø� �Լ� ����
template <class T1, class T2>
void ShowData(double num)
{
    // ���ڷ� ���޵� num�� T1�� T2 Ÿ������ ��ȯ�Ͽ� ���
    cout << (T1)num << ", " << (T2)num << endl;
}

int main(void)
{
    // ShowData �Լ� ȣ�� �� ���� ����
    ShowData<char, int>(65);        // ���� 'A'(ASCII 65), ���� 65 ���
    ShowData<char, int>(67);        // ���� 'C'(ASCII 67), ���� 67 ���
    ShowData<char, double>(68.9);   // ���� 'D'(ASCII 68), �Ǽ� 68.9 ���
    ShowData<short, double>(69.2);  // ���� 69, �Ǽ� 69.2 ���
    ShowData<short, double>(70.4);  // ���� 70, �Ǽ� 70.4 ���
    return 0;
}

/*
1. template <class T1, class T2> void ShowData(double num): 
    -> ���ø� �Լ� ShowData�� ���ǵ�. T1�� T2 �� ���� Ÿ���� �޾Ƽ�, 
        -> ���ڷ� ���޵� num�� �ش� Ÿ������ ����ȯ�Ͽ� ��µ�.

2. ShowData<char, int>(65);: 
    -> ���ø� �Լ��� ȣ���ϰ�, ù ��° ���ø� ���ڷ� char��, �� ��° ���ø� ���ڷ� int�� �����Ͽ� �Լ��� ȣ���. 
        -> 65�� double Ÿ������ ���޵Ǿ� ���� 'A'(ASCII 65)�� ���� 65�� ��µ�.

3. ShowData<char, int>(67);: 
    -> ���� ������ ������� �Լ��� ȣ���ϰ�, 
        -> 67�� double Ÿ������ ���޵Ǿ� ���� 'C'(ASCII 67)�� ���� 67�� ��µ�.

4. ShowData<char, double>(68.9);: 
    -> 68.9�� double Ÿ������ ���޵Ǿ� ���� 'D'(ASCII 68)�� �Ǽ� 68.9�� ��µ�.

5. ShowData<short, double>(69.2);: 
    -> 69.2�� double Ÿ������ ���޵Ǿ� ���� 69�� �Ǽ� 69.2�� ��µ�.

6. ShowData<short, double>(70.4);: 
    -> 70.4�� double Ÿ������ ���޵Ǿ� ���� 70�� �Ǽ� 70.4�� ��µ�
*/