//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl;
void solve()
{
	ll a, b;
	cin >> a >> b;
	vector < ll > dig;
	while(b > a){
		//cout << b << " ";
		dig.push_back(b);
		if(b%10 == 1){
			b /= 10;
		}
		else if(b%10 != 1 && (b%10 & 1)){
			break;
		}
		else	
			b/=2;
	}
	
	if(b==a){
		cout << "YES\n" << dig.size()+1 << "\n" << a << " ";
		for(auto i = dig.rbegin(); i!=dig.rend(); i++)
			cout << *i << " ";
	}else
				cout << "NO\n";
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
