//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    unordered_map<int, int> check; 
	for(int &i : a) cin>>i;
    set<int>s;
    k--;
    int curr = 0, ans=0;
    int beg = 0, last = 0, l = 0; 
    for (int i = 0; i < n; i++) { 

        check[a[i]]++; 

        if (check[a[i]] == 1) 
            curr++; 

        while (curr > k) { 
            check[a[l]]--; 
            if (check[a[l]] == 0) 
                curr--; 
  
            l++; 
        } 
        if (i - l + 1 >= last - beg + 1) 
            last = i, beg = l; 
    } 

    cout << (last-beg)+1 << endl;
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
