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
		int  n, k, d;
		cin >> n >> k >> d;
		vector<int> a(n+1);
		map<int, int> check;
		int mini = 0, count;
		for (int i=1; i<=n; i++)
		{
			cin >> a[i];
			if (i <= d)
			{
				if (check[a[i]] == 0)
				    check[a[i]] = 1, mini += 1;
				else
				    check[a[i]] += 1;
			}
		}
		count = mini;
		for (int i=d+1; i<=n; i++)
		{
			check[a[i-d]] -= 1;
			
            if (check[a[i-d]] == 0)
			count -= 1;
			
            if (check[a[i]] == 0)
			    check[a[i]] = 1, count += 1;
			else
				check[a[i]]++;
			
            mini = min(mini, count);
		}
		cout<<mini<<endl;
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
