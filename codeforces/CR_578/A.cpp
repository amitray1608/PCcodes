#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll a[10]={0};
	
	for(ll i = 0; i<n; i++)
	{
		if(s[i] == 'L')
		{
			for(int j = 0; j<9; j++)
			{
				if(a[j] == 0)
					{a[j] = 1;
					break;
				}
			}
		}	
		
		else if(s[i] == 'R')
		{
			for(int j = 9; j>=0; j--)
			{
				if(a[j] == 0)
					{a[j] = 1;
					break;
				}
			}
		}	
		else
		a[s[i] - '0'] = 0;
	
	}
	
	for(int i = 0; i<=9; i++)
	cout << a[i];
	
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
