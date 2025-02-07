#include <iostream>
#include "Oto.h"
#include "Arac.h"
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* sonraki;
    Node(T data) : data(data), sonraki(nullptr) {}
};

template <typename T>
class BagliList {
private:
    Node<T>* head;

public:
    BagliList() : head(nullptr) {}

    void basEkle(T value) {
        Node<T>* yeni = new Node<T>(value);
        yeni->sonraki = head;
        head = yeni;
    }

    void sonEkle(T value) {
        Node<T>* yeni = new Node<T>(value);
        if (!head) {
            head = yeni;
            return;
        }
        Node<T>* temp = head;
        while (temp->sonraki) {
            temp = temp->sonraki;
        }
        temp->sonraki = yeni;
    }

    void arayaEkle(T value, int index) {
        if (index == 0) {
            basEkle(value);
            return;
        }
        Node<T>* yeni = new Node<T>(value);
        Node<T>* temp = head;
        for (int i = 0; temp && i < index - 1; i++) {
            temp = temp->sonraki;
        }
        if (!temp) {
            cout << "Gecersiz Index Sona Eklendi" << endl;
            sonEkle(value);
            return;
        }
        yeni->sonraki = temp->sonraki;
        temp->sonraki = yeni;
    }

    void sondanSil() {
        if (!head) {
            cout << "Liste Bos!!!" << endl;
            return;
        }
        if (!head->sonraki) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* temp = head;
        while (temp->sonraki->sonraki) {
            temp = temp->sonraki;
        }
        delete temp->sonraki;
        temp->sonraki = nullptr;
    }

    void bastanSil() {
        if (!head) {
            cout << "Liste Bos!!!" << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->sonraki;
        delete temp;
    }

    void display() {
        if (!head) {
            cout << "Liste Bos!!!" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data->bilgileriYazdir() << " -> ";
            temp = temp->sonraki;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
	BagliList<Oto*> b;
	b.basEkle(new Oto(160, "5 Ileri Otomatik", "Dizel", "FIAT", "EGEA"));
	b.basEkle(new Oto(175, "6 Ileri Manuel", "Benzin", "BMW", "E30"));
	b.sonEkle(new Oto(190, "6 Ileri Otomatik", "Elektrik", "TOGG", "T10X"));
	b.sonEkle(new Oto(200, "6 Ileri Otomatik", "Elektrik", "TESLA", "MODEL Y"));
	b.arayaEkle(new Oto(180, "5 Ileri Manuel", "HYBRID", "TOYOTA", "COROLLA"), 1);
	b.arayaEkle(new Oto(170, "6 Ileri Manuel", "Dizel", "PEUGEOT", "RIFTER"), 2);
	b.display();

}
