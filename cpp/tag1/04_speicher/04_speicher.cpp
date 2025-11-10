#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char *s = NULL;
    int *lp = NULL;

    s = new char[50];
    lp = new int;
    
    strcpy(s, "Mustermann");
    *lp = 42;

    cout << "s: " << s << " lp: " << lp << endl;

    delete[] s;
    delete lp;
}