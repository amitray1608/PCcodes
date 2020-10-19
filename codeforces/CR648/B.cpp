//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve2() {
	int n; cin >> n;
	vector<int> ar(n);
	vector<int> a(2, 0);
	for(int &i: ar) {
		cin >> i;
	}
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		a[x]++;
	}
	if(a[0] && a[1]) {
		cout << "Yes\n";
		return;
	}
	for(int i = 1; i < n; ++i) {
		if(ar[i - 1] > ar[i]) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

/*
void solve(){
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for(int i = 0; i < n; i++)
		cin >> a[i], c[i] = a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	sort(c, c+n);
	bool flag = true;
	for(int i = 0; i < n; ++i) {
		if(c[i] != a[i]) {
			flag = false;
			break;
		}
	}
	
		if(can == false)
			cout << "No";
		else
			cout << "Yes";
	}
	cout << endl;
}
*/

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve2();
//			cout << t << endl;
		}
		
	return 0;
}
