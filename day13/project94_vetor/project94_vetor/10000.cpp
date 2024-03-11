#include <iostream>
#include <string>
using namespace std;
class Product {
    int id;
    string price, description, producer;
public:
    Product() {}
    Product(int id, string price, string des, string pro) {
        this->id = id; this->price = price;
        description = des; producer = pro;
    }
    virtual void show() = 0; // �θ� Ŭ�������� �ڽ� Ŭ������ �Լ��� �����ϱ�����
    // ���� ���� �Լ� ���
    int getId() { return id; }
    string getPrice() { return price; }
    string getDes() { return description; }
    string getPro() { return producer; }
};
class Book : public Product {
    string isbn, author, bookName;
public:
    Book(int id, string des, string pro, string price, string bookName, string author, string isbn) :Product(id, price, des, pro) {
        this->isbn = isbn; this->author = author; this->bookName = bookName;
    }
    void show();
    string getName() { return bookName; }
    string getAut() { return author; }
    string getISBN() { return isbn; }
};
void Book::show() {
    cout << "--- ��ǰID : " << getId() << endl;
    cout << "��ǰ���� : " << getDes() << endl;
    cout << "������ : " << getPro() << endl;
    cout << "���� : " << getPrice() << endl;
    cout << "å���� : " << bookName << endl;
    cout << "���� : " << author << endl;
    cout << "ISBN : " << isbn << endl;
}
class CompactDisc : public Product {
    string title, singer;
public:
    CompactDisc(int id, string des, string pro, string price, string title, string singer) : Product(id, price, des, pro) {
        this->title = title; this->singer = singer;
    }
    void show();
};
void CompactDisc::show() {
    cout << "--- ��ǰID : " << getId() << endl;
    cout << "��ǰ���� : " << getDes() << endl;
    cout << "������ : " << getPro() << endl;
    cout << "���� : " << getPrice() << endl;
    cout << "�ٹ����� : " << title << endl;
    cout << "���� : " << singer << endl;
}
class ConversationBook : public Book {
    string language;
public:
    ConversationBook(int id, string des, string pro, string price, string bookName, string author, string lan, string isbn)
        :Book(id, des, pro, price, bookName, author, isbn) {
        this->language = lan;
    }
    void show();
};
void ConversationBook::show() {
    cout << "--- ��ǰID : " << getId() << endl;
    cout << "��ǰ���� : " << getDes() << endl;
    cout << "������ : " << getPro() << endl;
    cout << "���� : " << getPrice() << endl;
    cout << "å���� : " << getName() << endl;
    cout << "���� : " << getAut() << endl;
    cout << "��� : " << language << endl;
    cout << "ISBN : " << getISBN() << endl;
}
int main() {
    Product* p[100];
    int id = 0;
    string des, pro, price, isbn, aut, name, title, singer, lan;
    //����,������,����,isbn��ȣ,�۰�,å�̸�,�ٹ�����,����,���
    cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << endl;
    for (;;) {
        cout << "��ǰ �߰�(1), ��� ��ǰ ��ȸ(2), ������(3) ? ";
        int n;
        cin >> n;
        if (n == 1) {
            if (id >= 100) break;
            cout << "��ǰ ���� å(1), ����CD(2), ȸȭå(3) ? ";
            cin >> n;
            cin.ignore(); // ������ ������ ���� ���������� �Է¿���
            if (n == 1) {
                cout << "��ǰ����>>"; getline(cin, des);
                cout << "������>>"; getline(cin, pro);
                cout << "����>>"; getline(cin, price);
                cout << "å����>>"; getline(cin, name);
                cout << "����>>"; getline(cin, aut);
                cout << "ISBN>>"; getline(cin, isbn);
                Book* b = new Book(id, des, pro, price, name, aut, isbn);
                p[id] = b;
                ++id;
            }
            else if (n == 2) {
                cout << "��ǰ����>>"; getline(cin, des);
                cout << "������>>"; getline(cin, pro);
                cout << "����>>"; getline(cin, price);
                cout << "�ٹ�����>>"; getline(cin, title);
                cout << "����>>"; getline(cin, singer);
                CompactDisc* c = new CompactDisc(id, des, pro, price, title, singer);
                p[id] = c;
                ++id;
            }
            else if (n == 3) {
                cout << "��ǰ����>>"; getline(cin, des);
                cout << "������>>"; getline(cin, pro);
                cout << "����>>"; getline(cin, price);
                cout << "å����>>"; getline(cin, name);
                cout << "����>>"; getline(cin, aut);
                cout << "���>>"; getline(cin, lan);
                cout << "ISBN>>"; getline(cin, isbn);
                ConversationBook* cb = new ConversationBook(id, des, pro, price, name, aut, lan, isbn);
                p[id] = cb;
                ++id;
            }
            else
                cout << "���� �Է� ����" << endl;
        }
        else if (n == 2) {
            for (int i = 0; i < id; ++i)
                p[i]->show();
        }
        else if (n == 3) {
            break;
        }
        else
            cout << "���� �Է� ����" << endl;
        cout << endl;
    }
}