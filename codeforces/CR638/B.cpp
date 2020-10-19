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
	int n, k;
	cin >> n >> k;
	set<int> s;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	if((int)s.size() > k){
		cout << -1 << endl;
		return;
	}
    cout << k*n << endl;
	for(int j = 0; j < n; j++){
        for(auto i : s){
            cout<< i << " ";
        }
			if(s.size() != k){
				for(int jj = 0; jj < k-s.size(); jj++)
					cout << 1 << " ";
			}
    }
           cout << endl;
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
