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
    int a[n];
    for(int &i : a) cin >> i;
    vector<int>ans;
    map<int, int>check;
    int count = 0;
    bool flag = true;
    for(int i = 0; i < n; i++){
		if(a[i] > 0 && check[a[i]] > a[i]){
			flag = false;
			break;
		}else if(a[i] < 0 && check[-a[i]] == 0){
			flag = false;
			break;
		}else{
			if(a[i] > 0)
				check[a[i]] += a[i];
			else
				check[-a[i]] -= a[i];
		}
		count += a[i];
		if(count == 0 && i&1){
			if(ans.size() > 1 && i == n-1) break;
			ans.push_back(i+1);
			check.clear();
		}
	}
	if(ans.size() == 0 || !flag)
		cout << -1 << endl;
	else{
		cout << ans.size() << endl;
		for(int i : ans)
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
