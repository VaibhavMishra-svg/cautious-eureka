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
char id[10];
float salary;
public:
void get()
{
cin>>name>>age>>id>>salary;
}
void disp()
{
cout<<name<<"\n"<<age<<"\n"<<id<<"\n"<<salary<<"\n";
}
};

class student:public person
{
char regno[10];
float marks;
public:
void get()
{
cin>>name>>age>>regno>>marks;
}
void disp()
{
cout<<name<<"\n"<<age<<"\n"<<regno<<"\n"<<marks<<"\n";
}
};

int main()
{
employee e;
e.get();
e.disp();
student s;
s.get();
s.disp();
}
