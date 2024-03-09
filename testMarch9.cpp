#include <iostream>
#include <string>
using namespace std;

// 부모 클래스
class Product {
private:
    string id;
    double price;
    string producer;

public:
    // 생성자
    Product(string _id, double _price, string _producer) : id(_id), price(_price), producer(_producer) {}

    // getter 함수들
    string getId() const { return id; }
    double getPrice() const { return price; }
    string getProducer() const { return producer; }

    // 제품 정보 출력
    virtual void display() {
        cout << "ID: " << id << ", 가격: " << price << "원, 제조사: " << producer << endl;
    }
};

// 자식 클래스: 책
class Book : public Product {
private:
    string ISBN;
    string author;
    string title;

public:
    // 생성자
    Book(string _id, double _price, string _producer, string _ISBN, string _author, string _title)
        : Product(_id, _price, _producer), ISBN(_ISBN), author(_author), title(_title) {}

    // 책 정보 출력
    void display() override {
        cout << "ID: " << getId() << ", 가격: " << getPrice() << "원, 제조사: " << getProducer() << ", ISBN: " << ISBN << ", 저자: " << author << ", 제목: " << title << endl;
    }
};

// 자식 클래스: 핸드폰
class Handphone : public Product {
private:
    string model;
    int ram;

public:
    // 생성자
    Handphone(string _id, double _price, string _producer, string _model, int _ram)
        : Product(_id, _price, _producer), model(_model), ram(_ram) {}

    // 핸드폰 정보 출력
    void display() override {
        cout << "ID: " << getId() << ", 가격: " << getPrice() << "원, 제조사: " << getProducer() << ", 모델: " << model << ", RAM: " << ram << "GB" << endl;
    }
};

// 자식 클래스: 컴퓨터
class Computer : public Product {
private:
    string model;
    string cpu;
    int ram;

public:
    // 생성자
    Computer(string _id, double _price, string _producer, string _model, string _cpu, int _ram)
        : Product(_id, _price, _producer), model(_model), cpu(_cpu), ram(_ram) {}

    // 컴퓨터 정보 출력
    void display() override {
        cout << "ID: " << getId() << ", 가격: " << getPrice() << "원, 제조사: " << getProducer() << ", 모델: " << model << ", CPU: " << cpu << ", RAM: " << ram << "GB" << endl;
    }
};

// 제품 검색 함수
void searchProduct(Product* products[], string targetId) {
    bool found = false;
    for (int i = 0; products[i] != nullptr; ++i) {
        if (products[i]->getId() == targetId) {
            products[i]->display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "해당 ID의 상품을 찾을 수 없습니다." << endl;
    }
}

int main() {
    Product* products[100]; // 객체 포인터 배열
    int choice;
    int productCount = 0; // 추가된 상품 개수를 추적하기 위한 변수

    do {
        cout << "상품 관리 프로그램" << endl;
        cout << "1. 상품 추가  2. 상품 출력  3. 상품 검색  0. 종료" << endl;
        cout << "원하는 작업을 선택하세요: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int subChoice;
                cout << "1. 책  2. 핸드폰  3. 컴퓨터" << endl;
                cout << "추가할 상품 종류를 선택하세요: ";
                cin >> subChoice;

                string id, producer;
                double price;
                string model, ISBN, author, title, cpu;
                int ram;

                cout << "ID를 입력하세요: ";
                cin >> id;
                cout << "가격을 입력하세요: ";
                cin >> price;
                cout << "제조사를 입력하세요: ";
                cin >> producer;

                switch (subChoice) {
                    case 1: {
                        cout << "ISBN을 입력하세요: ";
                        cin >> ISBN;
                        cout << "저자를 입력하세요: ";
                        cin >> author;
                        cout << "제목을 입력하세요: ";
                        cin >> title;

                        products[productCount] = new Book(id, price, producer, ISBN, author, title);
                        productCount++;
                        break;
                    }
                    case 2: {
                        cout << "모델을 입력하세요: ";
                        cin >> model;
                        cout << "RAM 용량을 입력하세요 (GB 단위): ";
                        cin >> ram;

                        products[productCount] = new Handphone(id, price, producer, model, ram);
                        productCount++;
                        break;
                    }
                    case 3: {
                        cout << "모델을 입력하세요: ";
                        cin >> model;
                        cout << "CPU를 입력하세요: ";
                        cin >> cpu;
                        cout << "RAM 용량을 입력하세요 (GB 단위): ";
                        cin >> ram;

                        products[productCount] = new Computer(id, price, producer, model, cpu, ram);
                        productCount++;
                        break;
                    }
                    default:
                        cout << "유효하지 않은 선택입니다!" << endl;
                }
                break;
            }
            case 2: {
                cout << "상품 목록 출력:" << endl;
                for (int i = 0; i < productCount; ++i) {
                    products[i]->display();
                }
                break;
            }
            case 3: {
                string targetId;
                cout << "검색할 상품의 ID를 입력하세요: ";
                cin >> targetId;
                searchProduct(products, targetId);
                break;
            }
            case 0:
                cout << "종료합니다..." << endl;
                break;
            default:
                cout << "유효하지 않은 선택입니다!" << endl;
        }
    } while (choice != 0);

    // 동적 메모리 정리
    for (int i = 0; i < productCount; ++i) {
        delete products[i];
    }

    return 0;
}
