//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 5000005; 
ll MOD = 1000000007;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll fac[siz];
ll twos[siz];
ll MODEXPO(ll x, ll y, ll m) ;
void factorial(){
	fac[0] = 1LL;
	twos[0] = 1LL;
	for(ll i = 1; i < siz; i++){
		fac[i] = (fac[i-1]*i)%MOD;
		twos[i] = (twos[i-1]*2)%MOD;
	}
}

ll MODEXPOS(ll x, ll n){
    ll ans = 1LL;
    while(n > 0){
        if(n % 2 == 1)
            ans = (ans * x)%MOD;
        x = (x*x)%MOD;
        n = n/2;
    }
    return ans;
}
ll MODINV(ll A){
    return MODEXPO(A, MOD-2, MOD);
}


ll MODEXPO(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = MODEXPO(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
} 

void solve(){
	ll n, N;
	cin >> n;
	N = n*2;
	ll all[N], total = 0;
	for(ll &i : all) cin >> i, total += i;
	//ll total = accumulate(all, all+N, 0);
	if(n == 1){
	if(all[0] != all[1]){
		cout << 0 << endl;
            return;
    }else{
		cout << 1 << endl;
			return;
          }
     }
	//deb(total);
	if(total % (n+1)){
		cout << 0 << endl;
		return;
	}
	vector<ll> half;
	ll cnt = 0;
	total /= (n+1);
	//deb(total);
	for(ll i = 0; i < N; i++){
		if(total == all[i] && cnt < 2)
			cnt++;
		else if(total == all[i])
			cnt++, half.push_back(all[i]);
		else 
			half.push_back(all[i]);
	}
	//base condition
	//for(ll i : half) cout << i << " ";
	//cout << endl;
	//deb(cnt);
	if(cnt < 2){
		cout << 0 << endl;
		return;
	}
	sort(half.begin(), half.end());
	//bool flag = false;
	//for(ll i : half) cout << i << " ";
	//cout << endl;
	ll ncnt = 0, h = half.size()/2, f = half.size();
	for(ll i = 0; i < h; i++){
		if(half[i] + half[f-i-1] != total){
			cout << 0 << endl;
			return;
		}
		if(half[i] == half[f-i-1])
			ncnt++;
	}
	cnt = 1;
	vector <ll> same;
	for(ll i = 1; i < h; i++){
		if(half[i] != half[i-1])
			same.push_back(cnt), cnt  =  1 ;
		else
			cnt++;
	}
	same.push_back(cnt);
	//deb(ncnt);
	//for(ll i : same) cout << i << " ";
	//cout << endl;
	ll ans = (twos[n-ncnt-1] * fac[n-1]) % MOD;
	//deb(ans);
	ll anss = 1, len = same.size();
	for(ll i = 0; i < len; i++)
		anss = (anss * fac[same[i]]) % MOD;
	
	//deb(ans);
	cnt = ((ans) * (MODINV(anss)))%MOD;
	cout << cnt << endl;
	
	
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		factorial();
		while(t--){
			solve();
		}
	return 0;
}
	
