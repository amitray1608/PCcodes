
//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = (ll)1e12 + 1;
const ll MOD = (ll)1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<ll>perfect;
//CREDIT - https://www.geeksforgeeks.org/perfect-power-1-4-8-9-16-25-27/
void powerNumbers(ll n) { 
//cout << "ok" << endl;
    for (ll i = 2; i * i <= n; i++) { 
        ll j = i * i; 
        perfect.push_back(j); 
        while (j * i <= n) { 
            perfect.push_back(j * i); 
            j = j * i; 
        } 
    } 
  
    sort(perfect.begin(), perfect.end()); 
    perfect.erase(unique(perfect.begin(), perfect.end()), perfect.end()); 
         //cout << perfect.size() << endl;
        //for(auto i : perfect)
            //cout << i << " ";
        //cout << endl;
	//return v.size() + (ll)sqrt(n); 
} 
void solve(){
    ll n;
    cin >> n;
    ll ans = n;
    for(ll i = 0; i < (ll)perfect.size(); i++) {
        if(perfect[i] > n)
			break;
		ll per = perfect[i];
		//ll sqr = perfect[i];
        int t = (((n / per) % MOD) * (per % MOD)) % MOD;
        ans = ((ans % MOD) + (t % MOD)) % MOD;
    }
    cout << ans << endl;
}

int main(){
    #ifndef RAY
        //freopen("input.txt", "r", stdin);
    #endif
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        powerNumbers(siz);
        int t = 1;
        cin >> t;
        while(t--){
            solve();
        }
    return 0;
}     
