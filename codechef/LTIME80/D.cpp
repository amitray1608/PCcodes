#include <iostream>
//Autor Andrzej Słomka
//zad:NWW
using namespace std;
int NWD(int a, int b)
{
    int tmp;
	while(b!=0)
    {
		tmp = b;
		b = a%b;
		a = tmp;
	}
    return a;
}
int NWW(int a, int b)
{
    return a*b/NWD(a,b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<NWW(a,b);
    return 0;
}
