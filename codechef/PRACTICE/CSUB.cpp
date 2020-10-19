#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll count = 0;
	for(int i = 0; i<n; i++)
	if(s[i] == '1')	count++;
	
	cout << ((count*(count+1))/2) << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
