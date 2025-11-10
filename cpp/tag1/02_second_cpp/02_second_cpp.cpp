#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    cout << "Zeile mit COUT" << endl;
    printf("Zeile mit printf \n");

    for (int l = 1, o = l*l; l < 10; l++,o=l*l)
    {
        cout << "l ist " << l << ", o ist " << o << endl;
    }
}