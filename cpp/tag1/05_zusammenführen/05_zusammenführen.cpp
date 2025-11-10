#include<iostream>
#include<string.h>

class mystring
{
    private:
        char *string = NULL;
    public:
        mystring();
        mystring(char *s);
        ~mystring();
        void setString(char *s);
        void print();
};

mystring::mystring()
{
    this->string = NULL;
}
mystring::mystring(char *s)
{
    this->setString(s);
}
mystring::~mystring()
{
    if (this->string != NULL)
    {
        delete[] this->string;
    }
}
void mystring::setString(char *s)
{
    if (this->string != NULL)
    {
        delete[] this->string;
    }
    this->string = new char[strlen(s)+1];
    strcpy(this->string, s);
}
void mystring::print()
{
    if (this->string != NULL)
    {
        std::cout << this->string << std::endl;
    }
    else
    {
        std::cout << "String ist leer" << std::endl;
    }
}

int main() {
    mystring s1;
    mystring s2("Test");

    s1.setString("Test2");
    s1.print();
    s2.print();

    mystring *s3 = new mystring("Test3");
    s3->print();
    delete s3;
}