#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string str;
	 cin >> str;
	ll i, n = str.length(), count=0;
	
	for(i=0; i<n; i++)
	{
		if(str[i]=='1')
			count++;
	}
	(count&1) ?	cout << "WIN\n" : cout << "LOSE\n";
}

int main(){
	
		int t;
		cin >> t;
			while(t--)
				{
					solve();
				}
	}
