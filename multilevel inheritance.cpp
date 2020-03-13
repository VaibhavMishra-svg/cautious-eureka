#include<iostream>
using namespace std;
class person
{
protected:
char name[30];
int age;
};

class employee:public person
{
protected:
int id;
};

class parttimeemployee:public employee
{
int salary;
public:
void get()
{
cin>>name>>age>>id>>salary;
}
void disp()
{
cout<<"\n"<<name<<"\n"<<age<<"\n"<<id<<"\n"<<salary<<"\n";
}
};

int main()
{
parttimeemployee pte;
pte.get();
pte.disp();
}
