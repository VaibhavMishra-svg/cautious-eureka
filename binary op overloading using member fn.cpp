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
number operator+(number &n)
{
number res;
res.x=x+n.x;
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
