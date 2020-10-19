#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
void solve(){
	
		int a, b, c;
		cin >> a >> b >> c;
		a-=b;
		if(a>=c)
			{cout << 0 << endl;}
		else
		{cout << c-a << endl;}
	
}

int main()
{
	
	    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		int t =1;
			//cin >> t;
		while(t--)
		{
			solve();
		}
		return 0;
}
