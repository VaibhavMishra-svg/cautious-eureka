#include<iostream>
using namespace std;
class number
{
int x;
public:
void get()
{
cin>>x;
}
void disp()
{
cout<<x;
}
friend number operator+(number &n,number &num)
{
number res;
res.x=n.x+num.x;
return res;
}
};
int main()
{
number n1,n2,n3;
n1.get();
n2.get();
n3=n1+n2;
n3.disp();
}
