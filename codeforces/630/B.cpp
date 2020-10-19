//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
//credit - https://www.geeksforgeeks.org/sieve-of-eratosthenes/
int prime[1005];
 void sieve() {
	int count=0;
	memset(prime, 0, sizeof prime);
	for(int i=2; i*i < 1005; i++){
		if(prime[i] == 0)count++;
		for(int j = i*2; j < 1005; j++)
			if(j % i == 0 && prime[j] == 0)
				prime[j] = count;
	}
	for(int i = 1;i < 1003; i++)
		cout <<i << " = " << prime[i] << endl;
} 
  
void solve(){ 
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int x = 2; x * x <= a[i]; x++) {
        if (a[i] % x == 0) {
          a[i] = x;
          break;
        }
      }
    }
    map <int, int> mp;
    int sz = 0;
    for (int i = 0; i < n; i++) {
      if (!mp.count(a[i])) mp[a[i]] = sz++;
      a[i] = mp[a[i]];
    }
    cout << sz << '\n';
    for (int x : a) cout << x + 1 << ' ';
    cout << '\n';
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
	
