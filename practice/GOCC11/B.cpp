#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> ans(n, 1);
  for(int &i : a) cin >> i;
  for(int i = 0; i < n; i++) {
    int mini = a[i];
    for(int j = i+1; j < n; j++) {
      if(mini < a[j]) 
        ans[i]++;
      else
        ans[j]++;
    }
  }
  for(int &i : ans)
    cout << i << ' ';
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--)
    solve();
  return 0;
}  

/*
3
2
88 78
2
95 84
4
1 2 3 4
*/