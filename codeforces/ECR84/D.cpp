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
    int n;
    cin >> n;
    int a[n], c[n], p[n];
    memset(p, -1, sizeof p);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
        p[i] = a[i];
    }
    for(int i=0; i<n; i++){
        cin >> c[i];
        c[i]--;
    }
    int count = INT_MAX;
    for(int i=0; i<n; i++){
        int k = 1, curr = i;
        while(p[curr] != i && c[p[curr]] != c[i]){
            curr = p[curr];
            k++;
        }
        count = min(count, k);
    }
    cout << count << endl;
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
