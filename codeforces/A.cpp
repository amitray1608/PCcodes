#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
ll mod = 1e9+7;
void solve()
{
	ll n, k;
	cin >> n >> k;
	ll odd = n-(k-1), even = n - 2*(k-1);
	if(odd && odd&1){
		cout << "YES" << endl;
		for(int i = 0; i < k-1; i++)
			cout << 1 << " ";
		cout << odd << endl;
		return;
	}else if(even && ~even&1){
		cout << "YES" << endl;
		for(int i = 0; i < k-1; i++)
			cout << 2 << " ";
		cout << even << endl;
		return;
	}else{
		cout << "NO" << endl;
	}
	
	//ll l = 1, h = 2*k;
	//while(l < h){
		//ll mid = (l+h)/2;
		//ll count = mid - (mid/n);
		//if(count >= k)
			//h = mid;
		//else
			//l = mid+1;
	//}
	//cout << l << endl;
	//string s;
	//cin >> s;
	//s = "#"+s;
	//int n = s.size();
	//vector<int>pos;

	//for(int i = 1; i < n; i++){
		//if(s[i] != '0'){
			//pos.push_back(i);
		//}
	//}
	//cout << pos.size() << endl;
	//for(int i : pos){
		//cout << s[i];
		//int x = 0;
		//while(x < n-i-1){
			//cout << 0;
			//x++;
		//}
		//cout << " ";
	//}
	//cout << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
	
