#include<bits/stdc++.h>
using namespace std;
const int m=2;
void fun(array <array<int,m>,m> &ar)
{
    cout<<&ar<<endl;
    cout<<ar[0][0]<<endl;
    cout<<ar[0][1]<<endl;
    cout<<ar[1][0]<<endl;
    cout<<ar[1][1]<<endl;
    cout<<endl;

    ar[1][1] = 50;

}

int main()
{
    array <array<int,m>,m> ar;

    ar[0][0] = 12;
    ar[0][1] = 22;
    ar[1][0] = 32;
    ar[1][1] = 42;

    cout<<&ar<<endl;
    cout<<ar[0][0]<<endl;
    cout<<ar[0][1]<<endl;
    cout<<ar[1][0]<<endl;
    cout<<ar[1][1]<<endl;
    cout<<endl;

    fun(ar);

    cout<<ar[0][0]<<endl;
    cout<<ar[0][1]<<endl;
    cout<<ar[1][0]<<endl;
    cout<<ar[1][1]<<endl;
    cout<<endl;
}
