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
	string s;
	cin >> s;
	int n = s.length();
	vector<int> ans, ans1, order;
	for(int i = 0;i < n; i++)
		if(s[i]=='(')
			ans.push_back(i+1);
	
	for(int i = n-1; i >= 0; i--)
		if(s[i] == ')')
			ans1.push_back(i+1);
	
	int mini = std::min(ans1.size(), ans.size()), x = 0;
	for(int i=0; i < mini; i++){
		if(ans1[i] > ans[i])
			x++;
		else
			break;
	}
 
	if(!x){
		cout << 0 ;
	}
	else{
		cout << 1 << endl << x*2 << endl;
		for(int i=0; i < x; i++)
			order.push_back(ans[i]), order.push_back(ans1[i]);
		sort(order.begin(), order.end());
		for(int i : order)
			cout << i << " ";
	}
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
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
