#include <iostream>
using namespace std;

// ���ø� �Լ� ����
template <typename T>
T Max(T a, T b)
{
    // a�� b�� ���Ͽ� �� ū ���� ��ȯ
    return a > b ? a : b;
}

int main(void)
{
    // ������ �� ���� ���Ͽ� �� ū ���� ���
    cout << Max(11, 15) << endl;    // 15 ���

    // ������ �� ���ڸ� ���Ͽ� ASCII ���� ū ���ڸ� ���
    cout << Max('T', 'Q') << endl;  // 'T' ���

    // �Ǽ��� �� ���� ���Ͽ� �� ū ���� ���
    cout << Max(3.5, 7.5) << endl;  // 7.5 ���

    // ���ڿ� �� ���� ���Ͽ� ���������� �� �ڿ� �ִ� ���ڿ��� ���
    cout << Max("Simple", "Best") << endl;  // "Simple" ���
    // ����: ���ڿ��� �񱳴� �ּҰ����� �񱳵Ǿ� ���������� �� �ڿ� �ִ� ���ڿ��� ��µ�

    return 0;
}

/*
1. template <typename T> T Max(T a, T b): 
    -> ���ø� �Լ� Max�� ���Ǻ�. �� ���� �� a�� b�� ���Ͽ� �� ū ���� ��ȯ��.

2. cout << Max(11, 15) << endl;: 
    -> ������ �� ���� ���Ͽ� �� ū ���� �����. => 15�� ��µ�.

3. cout << Max('T', 'Q') << endl;: 
    -> ������ �� ���ڸ� ���Ͽ� ASCII ���� ū ���ڸ� �����. => 'T'�� ��µ�.

4. cout << Max(3.5, 7.5) << endl;: 
    -> �Ǽ��� �� ���� ���Ͽ� �� ū ���� �����. => 7.5�� ��µ�.

5. cout << Max("Simple", "Best") << endl;: 
    - ���ڿ� �� ���� ���Ͽ� ���������� �� �ڿ� �ִ� ���ڿ��� �����. 
        -> �����ؾ� �� ���� ���ڿ��� �񱳴� �ּҰ����� �񱳵Ǿ� ���������� �� �ڿ� �ִ� ���ڿ��� ��µ�
            => ���⼭�� "Simple"�� ��µ˴ϴ�.
*/