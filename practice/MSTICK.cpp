//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<int>logtable;
vector<vector<int>>table, table2;

void logcalc(int n) {
  logtable.resize(n + 1);
  logtable[1] = 0;
  for(int i = 2; i <= n; i++)
    logtable[i] = logtable[i/2] + 1;
}

void SparseTable(int n, vector<int>&a) {
  int k = logtable[n];
  table.resize(n, vector<int>(k+1));
  table2.resize(n, vector<int>(k+1));
  for(int i = 0; i < n; i++) 
    table[i][0] = a[i], table2[i][0] = a[i];
  for(int j = 1; j <= k; j++) {
    for(int i = 0; i + (1 << j) <= n; i++) {
      table[i][j] = min(table[i][j-1], table[i+(1 << (j-1))][j-1]); 
      table2[i][j] = max(table2[i][j-1], table2[i+(1 << (j-1))][j-1]);
    }
  }
}

int query(int l, int r) {
  int j = logtable[r-l];
  return min(table[l][j], table[r - (1 << j) + 1][j]);
}

int query2(int l, int r) {
  int j = logtable[r-l];
  return max(table2[l][j], table2[r - (1 << j) + 1][j]);
}

void solve(){
  int n;	
  cin >> n;
  logcalc(n);
  vector<int>a(n);
  for(int &i : a) cin >> i;
  SparseTable(n, a);
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    double ans = 0.0;
    double mini = (double)query(l, r);
    double maxi = (double)query2(l, r);
    ans = mini + (double)((maxi-mini) / 2.0);
    double left = 0, right = 0;
    if(l > 0)
      left = (double)query2(0, l-1);
    if(r < n-1)
      right = (double)query2(r+1, n-1);
    left += mini;
    right += mini;
    cout << fixed << setprecision(2);
    cout << max({left, right, ans}) << endl;
  }
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
//		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
