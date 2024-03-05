#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos; // x�� y ��ǥ�� ��Ÿ���� private ��� ����

public:
    // ������: x�� y ��ǥ�� �ʱ�ȭ��.
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

    // ���� ��ǥ�� ����ϴ� ��� �Լ�
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    // ���� ������ ������ �����ϴ� ������ �����ε�
    Point operator*(int times)
    {
        Point pos(xpos * times, ypos * times); // ���� ��ü�� x�� y ��ǥ�� ���� ������ ���� ���ο� Point ��ü ����
        return pos; // ���ο� Point ��ü�� ��ȯ
    }
};

int main(void)
{
    Point pos(1, 2); // ��ǥ (1, 2)�� ������ Point ��ü ����
    Point cpy; // ������ Point ��ü�� ������.

    // ������ �����ε��� ���� pos�� ��ǥ�� 3�� ���� ����� cpy�� �Ҵ��ϰ�, cpy�� ��ǥ�� �����.
    cpy = pos * 3;
    cpy.ShowPosition(); // ���: [3, 6]

    // ������ �����ε��� ���� pos�� ��ǥ�� 3�� ���ϰ� �� ����� 2�� ���� ���� cpy�� �Ҵ��ϰ�, cpy�� ��ǥ�� �����.
    cpy = pos * 3 * 2;
    cpy.ShowPosition(); // ���: [6, 12]

    return 0;
}

/*
1. Point Ŭ������ ����:
    - private ���ǿ��� xpos�� ypos��� �� ���� ������ ��� ������ ����. 
        -> �� �������� ��ǥ�� ��Ÿ��.
    - public ���ǿ��� �����ڿ� ShowPosition() �Լ��� ����.
    - �����ڴ� �⺻������ x�� y�� ���� 0���� �ʱ�ȭ��.
    - ShowPosition() �Լ��� ���� ��ǥ�� �����.

2. operator* �Լ��� �����ε�:
    - operator* �Լ��� ���� ���� �Ű������� �޾Ƽ� ���� ��ü�� ��ǥ�� �ش� ���� ���� ��, 
        -> ���ο� Point ��ü�� �����Ͽ� ��ȯ.

3. main() �Լ�:
    - main() �Լ������� Point ��ü pos�� �����ϰ� �ʱ� ��ǥ�� (1, 2).
        -> �� ����, ����ִ� Point ��ü cpy�� ����.
    
    - pos * 3 ������ ���� pos ��ü�� ��ǥ�� 3�� ���� ����� cpy�� �Ҵ��ϰ�, 
        -> ShowPosition() �Լ��� ȣ���Ͽ� ��ǥ�� ����մϴ�.

    - pos * 3 * 2 ������ ���� pos ��ü�� ��ǥ�� 3�� ���� ����� �ٽ� 2�� ���� ���� cpy�� �Ҵ��ϰ�, 
        -> ShowPosition() �Լ��� ȣ���Ͽ� ��ǥ�� ���
*/