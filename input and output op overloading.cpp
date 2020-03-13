#include<iostream>
using namespace std;
class number
{
int x,y;
public:
friend void operator>>(istream &in,number &num)
{
in>>num.x;
in>>num.y;
}
friend void operator<<(ostream &out,number &num)
{
out<<num.x;
out<<num.y;
}
};
int main()
{
number n1,n2;
cin>>n1;
cin>>n2;
cout<<n1;
cout<<n2;
}
