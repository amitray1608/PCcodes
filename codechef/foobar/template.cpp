//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

template<typename T>
class BIT {
  int n;
  vector<T> bit;
public:
  BIT(int N) {
    bit.assign(N + 1 , 0);
    n = N;
  }
  void update(int idx , T val) {
    idx++;
    while(idx <= n) {
      bit[idx] += val;
      idx += (idx & -idx);
    }
  }
  int sum(int idx) {
    idx++;
    T res = 0;
    while(idx > 0) {
      res += bit[idx];
      idx -= (idx & -idx);
    }
    return res;
  }
 
};

void solve(){
	int n, q;
	cin >> n >> q;
	BIT<int>b(n+1);
	for(int i = 1; i < n+1; i++){
		int x;
		cin >> x;
		b.update(x, 1);
	}
	while(q--){
		int x;
		cin >> x;
		if(x < 0){
			x *= -1;
			int l = 0, h = n, ans = -1;
			while(l <= h){
				int mid = (l+h)/2;
				if(b.sum(mid)-b.sum(0) >= x)
					ans = mid, h = mid-1;
				else
					l = mid+1;
			}
			b.update(ans, -1);
		}else
			b.update(x, 1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(b.sum(i) - b.sum(i-1)){
			ans = i;
			break;
		}
	}
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
