//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
mt19937 prime{ static_cast<mt19937::result_type>(time(nullptr))};
void solve(){
    //auto beg = chrono::system_clock::now();
	int n, m, k;
	cin >> n >> m >> k;
    uniform_int_distribution<> randm{1, m};
	int a[n][k];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++)
			cin >> a[i][j];
	}
	vector<int>ans, anss;
	int xx = 95, prev = INT_MIN;
	while(xx--){
		for(int i = 0; i < n; i++){
			ans.push_back(randm(prime));
		}
		int x = INT_MAX;
		for(int i = 0; i < k; i++){
			int count = 0;
			for(int j = 0; j < n; j++){
				if(a[j][i] == ans[j])
					count++;
			}
			if(count < x)
				x = count;
		}
		if(prev < x)
			anss = ans, prev = x;
		ans.clear();
	}
		//cout << ans.size() << endl;
		for(int i : anss)
			cout << i << " ";
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
