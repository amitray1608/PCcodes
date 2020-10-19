//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll countd(ll a)
{
   ll ret=0;
    while(a!=0)
    {
        ret++;
        a=a/10;
    }
 
    return ret;
}
void solve(){
		//string a,b;
		//cin >> a >> b;
		//int x, y;
		//x = a.size();
		//y = b.size();
		//if(x >= y){
			//cout << (x-1)*stoi(b) << endl;
		//}
 
		//else
			//cout << (y-1)*stoi(a) << endl;
		  ll a,b;
		cin >> a >> b;
        long long ans = 0;
		//if(a > b) swap(a, b);
        ans = a*(countd(b+1)-1);
 
        cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
