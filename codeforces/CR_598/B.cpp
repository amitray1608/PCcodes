//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void lexi(vector<int>a){
	int p = 0;
	while(1){
		if(p >= (int)a.size()-1) {break;}
		int m = min_element(a.begin()+p, a.end()) - a.begin();
		bool flag = false;
		for(int i = m-1; i>=p; i--){
			flag = true;
			swap(a[i], a[i+1]);
		}
		if(!flag) p = m+1;
		else p = m;
	}
	
	for(int i  : a) cout << i << " ";
	
	cout << endl;
}


void solve(){
       // aaj v lode lage hai aur upar se net ki maaki bsda
        int n;
		cin >> n;
		vector<int>a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		
		if(is_sorted(a.begin(), a.end())){
			for(int i : a) cout << i << " ";
			
			cout << endl;
		}
		else{
			lexi(a);
		}
		
}

int main(){
	#ifndef RAY
		//~ freopen("input.txt", "r", stdin);
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
