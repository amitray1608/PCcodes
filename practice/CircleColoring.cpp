//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for(int &i : a) cin >> i;
  for(int &i : b) cin >> i;
  for(int &i : c) cin >> i;
  vector<int> ans;
  ans.push_back(a[0]);
  for(int i = 1; i < n-1; i++) {
    if(a[i] != ans[i-1])
      ans.push_back(a[i]);
    else if(b[i] != ans[i-1])
      ans.push_back(b[i]);
    else if(c[i] != ans[i-1])
      ans.push_back(c[i]);
  } 
  if(a[n-1] != ans[0] and ans[n-2] != a[n-1])
    ans.push_back(a[n-1]);
  else if(b[n-1] != ans[0] and ans[n-2] != b[n-1])
    ans.push_back(b[n-1]);
  else if(c[n-1] != ans[0] and ans[n-2] != c[n-1])
    ans.push_back(c[n-1]);

  for(int &i : ans) cout << i << ' ';
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
