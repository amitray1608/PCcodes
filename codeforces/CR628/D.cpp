//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int n, m;
    cin>>n>>m;
    if(n > m || (n-m)%2)
    {
        puts("-1");
        return;
    }
    if(n == m)
    {   
        if(n == 0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl<<n<<endl;
        }
        return;
    }
    int a = (m-n)/2;
    if((n&a) == 0)
    {
        cout<<2<<endl;
        cout<<a<<' '<<a+n<<endl;
    }
    else
    {
        cout<<3<<endl;
        cout<<a<<' '<<a<<' '<<n<<endl;
    }
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
