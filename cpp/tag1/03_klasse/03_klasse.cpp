#include<iostream>

using namespace std;

struct datum {
    int tag = 0;
    int monat = 0;
    int jahr = 0;
};

class cppdatum 
{
    private:
        int tag = 0;
        int monat = 0;
        int jahr = 0;
    public:
        cppdatum() {cout << "Konstruktor aufgerufen" << endl;}
        ~cppdatum() {cout << "Dekonstruktor aufgerufen" << endl;}
        int version = 1;
        int getTag() {return this-> tag;}
        int getMonat() {return this-> monat;}
        int getJahr() {return this-> jahr;}
        void setTag(int tag) {this->tag = tag;}
        void setMonat(int monat) {this->monat = monat;}
        void setJahr(int jahr) {this->jahr = jahr;}

        void print()
        {
            cout << this->getTag() << "." << this->getMonat() << "." << this->getJahr() << endl;
        }
    protected:
};

int main()
{
    datum d1;
    d1.tag = 10;
    d1.monat = 10;
    d1.jahr = 10;
    cout << d1.tag << "." << d1.monat << "." << d1.jahr << endl;

    cppdatum d2;
    d2.version = 2;

    d2.setTag(10);
    d2.setMonat(10);
    d2.setJahr(2025);
    d2.print();

    cppdatum *d3 = NULL;
    d3 = new cppdatum();
    d3->setTag(11);
    d3->setMonat(11);
    d3->setJahr(2026);
    d3->print();
    delete d3;

    return 0;
}