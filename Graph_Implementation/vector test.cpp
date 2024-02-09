#include<bits/stdc++.h>
using namespace std;



int main()
{
    int m=2;
    int a[m][m]{{10,20},{30,40}};

    cout<<&a<<endl;
    cout<<a<<endl;
    cout<<*a<<endl;
    cout<<**a<<endl;

    cout<<a[0][0]<<endl;
    cout<<a[0][1]<<endl;
    cout<<a[1][0]<<endl;
    cout<<a[1][1]<<endl;

    int (*p)[m][m] = &a;

    cout<<&a<<endl;

    cout<<&p<<endl;
    cout<<p<<endl;


    cout<<a[0][0]<<endl;
    cout<<a[0][1]<<endl;
    cout<<a[1][0]<<endl;
    cout<<a[1][1]<<endl;
}
