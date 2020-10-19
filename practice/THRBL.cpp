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
vector<vector<int>>table;

void logcalc(int n) {
  logtable.resize(n+1);
  logtable[1] = 0;
  for(int i = 2; i <= n; i++)
    logtable[i] = logtable[i/2] + 1;
}

void SparseTable(int n, vector<int> &a) {
  int k = log2(n);
  table.resize(n+1, vector<int>(k+1));
  for(int i = 0; i < n; i++) 
    table[i][0] = a[i];
  for(int j = 1; j <= k; j++) {
    for(int i = 0; i + (1 << j) <= n; i++)  
      table[i][j] = max(table[i][j-1], table[i + (1 << j)][j-1]);
  }
}

int query(int l, int r) {
  int k = logtable[(r-l)];
  return max(table[l][k], table[r - (1 << k) + 1][k]);
}

void solve(){
	int n, m;
  cin >> n >> m;
  vector<int>a(n);
  for(int &i : a) cin >> i;
  SparseTable(n, a);
  logcalc(n);
  int count = 0;
  while(m--) {
    int l, r;
    cin >> l >> r;
    if(l == r or l+1 == r or r+1 == l) {
      count++;
      continue;
    }
    l--, r--;
    if(l > r) {
      int x = query(r+1, l-1); 
      if(x <= a[r])
        count++;
    } else {
      int x = query(l+1, r-1);
      if(x <= a[l])
        count++;
    }
  }
  cout << count << endl;
}

int main(){
//	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	//#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		//cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
