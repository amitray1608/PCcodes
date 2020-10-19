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
    ll n;
    cin >> n;
    ll ind = 1;
    ll sum = 1;
    ll side = 0;
	vector<pair<ll, ll>>res;
    while(n > 0){
        if(n>sum){
            if(!side)
                for(int i = 0; i < ind; i++)
					res.push_back({ind, i+1});
            else
                for(int i = 0; i < ind; i++)
					res.push_back({ind, i+1});
            n -= sum;
            side ^= 1;
        }else{
            if(!side)
					res.push_back({ind, ind});
            else
					res.push_back({ind, 1});
            n--;
        }
        ind++;
        sum = sum << 1;
    }
    cout << res.size() << endl;
   	for(auto it : res)
		cout << it.first << " " << it.second << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 1;
		cin >> t;
		while(t--){
			cout << "Case #" << tt++ << ": " << endl;
			solve();
		}
	return 0;
}	
