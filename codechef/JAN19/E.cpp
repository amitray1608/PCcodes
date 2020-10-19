//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<pair<string, ll> verse;
//prefix max calc function
void PrefixCalc(vector<string>pref, ll i, ll n){
	
	ll prefSum[n] = {0};// sufSum[n] = {0};
	ll count = 0, sount = 0;
	//Prefix begin;
	for(; i < n-1; i+=2){
				
		ll A = pref[i].length(), B = pref[i+1].length();
		string p = pref[i], q = pref[i+1];
		
		//front count with previous;
		count  = 0;
		for(ll ii = 0; ii < min(A, B); ii++){
			if(p[ii] == q[ii])
				count++;
			else break;
		}

		sount = 0;
		ll k = B-1;
		for(ll j = A -1; j >= 0 && k >= 0; k--, j--){
			if(p[j] == q[k])
				sount++;
			else break;
		}

		prefSum[i] = pow(min(count, sount), 2);
		
		
	}
			
}

void SufixCalc(vector<string> suf, ll i, ll n){
	
	ll  sufSum[n] = {0};
	ll count = 0, sount = 0;
	//Prefix begin;
	for(; i < n-1; i+=2){
				
		ll A = suf[i].length(), B = suf[i+1].length();
		string p = suf[i], q = suf[i+1];
		
		//front count with previous;
		count  = 0;
		for(ll ii = 0; ii < min(A, B); ii++){
			if(p[ii] == q[ii])
				count++;
			else break;
		}
			
		//end count;
		sount = 0;
		ll k = B-1;
		for(ll j = A -1; j >= 0 && k >= 0; k--, j--){
			if(p[j] == q[k])
				sount++;
			else break;
		}

			sufSum[i] = pow(min(count, sount), 2);
			string t = q, tt = suf[i+1];
		reverse(t.begin(), t.end());
		reverse(tt.begin(), tt.end());
		
		
	}
	
}


void solve(){
	ll n;
	cin >> n;
	string s[n], rev[n];
	for(ll i = 0; i < n; i++){
		 cin >> s[i];
		 string t;
		 t = s[i];
		 reverse(t.begin(), t.end());
		 rev[i] = t;
		 //cout << s[i] << " " << rev[i] << endl;
		
	}
	vector<string>pref(s, s+n);
	vector<string>suf(rev, rev+n);
	sort(pref.begin(), pref.end());
	sort(suf.begin(), suf.end());

	for(ll i = 0; i < n; i++){
		verse.push_back(make_pair(pref[i], 0));
	}

	PrefixCalc(pref, 0, n);
	PrefixCalc(pref, 1, n);

		SufixCalc(suf, 0, n);
		SufixCalc(suf, 1, n);
	//maxiB = max(maxiB, tmp);
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		cout << flag[i] << " ";
		ans += flag[i];
	}
	cout << endl;
	cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--){
			memset(flag, 0, sizeof flag);
			solve();
		}
	return 0;
}
/*
3
6
abcdefghijkl
chef
world
code
abcxyzhijkl
word
4
problem
poem
problem
problem
3
contest
coolest
unused
* */
