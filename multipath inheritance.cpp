#include<iostream>
using namespace std;

class student
{
protected:
char name[30];
int rno;
};

class intmark:virtual public student
{
protected:
int cat1,cat2;
};

class tmark:virtual public student
{
protected:
int tmark;
};

class result:public intmark,public tmark
{
public:
void get()
{
cin>>name>>rno>>cat1>>cat2>>tmark;
}
void disp()
{
cout<<name<<"\n"<<rno<<"\n"<<cat1+cat2+tmark<<"\n";
}
};

int main()
{
result r1;
r1.get();
r1.disp();
}
