//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
//--------------------------------------------------------------------//
#define loop(i, a, n) for(ll i = a; i < n; i++)
#define rloop(i, a, n) for(ll i = n-1; i >= a; i--)
#define vi vector<int> 
#define vl vector<ll>
#define vd vector<dd>
#define prii pair<int, int>
#define prll pair<ll, ll>
#define mp make_pair
#define ff first
#define ss second
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define all(x)  x.begin(), x.end()
#define endl '\n'
//--------------------------------------------------------------------//


void solve(){
	int n, m;
	cin >> n >> m;
	int count[101] = {0};
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		for(int j = a; j<=b; j++)
			++count[j];
	}
		for(int i = 1; i<=n; i++){
			if(count[i] != 1)
				{ cout << i << " " << count[i] << endl; return;}
			
		}
		cout << "OK\n";
}

int main(){
	#ifndef RAY
		freopen("input.txt", "r", stdin);
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
