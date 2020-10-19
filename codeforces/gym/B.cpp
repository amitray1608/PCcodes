#include<bits/stdc++.h>
using namespace std;

int main(){
	string a, b, cc;
		cin >> a >> b >> cc;
		bool flag = false, x = false;
		for(char c : a)
		{
					if(c == '=')
					{x = true; continue;}
					if(x && c != '.')
					{
						flag = true;
						cout << c ;
					break;
				}
		}
		if(!x)
		{
				for(char c : b)
		{
					if(c == '=')
					{x = true; continue;}
					if(x && c != '.')
					{
						flag = true;
					cout << c ;
					break;
				}
		}
		
	}
	if(!x)
	{
				for(char c : cc)
		{
					if(c == '=')
					{x = true ;continue;}
					if(x && c != '.')
					{flag = true;
						cout << c ;
					break;
				}
		}
	}
	
	if(!flag && x )
		cout << "You shall pass!!!";
	}
