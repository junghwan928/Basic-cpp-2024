#include <iostream> 

using namespace std; 

int main()
{
    char ary[] = { 'a','b','c','d','e','f' };
    int length = sizeof(ary) / sizeof(ary[0]);

    cout << "�迭 ������: " << length << endl;
    for (int i = 0; i < length; ++i)
        cout << ary[i] << " ";
    cout << endl; 

    int i = 0;
    while (i < length / 2) {
        char temp = ary[i]; 
        ary[i] = ary[length - 1 - i]; 
        ary[length - 1 - i] = temp; 
        i++;
    }
    cout << "�ٲ� �迭: ";
    for (int i = 0; i < length; ++i)
        cout << ary[i] << " ";
    cout << endl; 

    return 0;
}

/* �ڳ��� �� �� �ڵ�
 
int main()
{
   char ary[]  = { 'a','b','c','d','e','f' };
   int length = sizeof(ary) / sizeof(ary[0]);

   cout << "�迭 ������: " << length << endl;
   for (int i = 0; i < length; ++i)
      cout << ary[i] << " " << endl;

   int i = 0;
   while (i < length / 2) {
      char temp = ary[i];
      ary[length - 1 - i] = temp;
   }
   cout << "�ٲ� �迭";
   for (int i = 0; i < length; ++i)
      cout << ary[i] << " " << endl;

   return 0;
}

*/