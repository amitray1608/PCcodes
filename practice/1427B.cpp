//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int lcount = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'L') lcount++;
  }
  if(lcount <= k) {
    cout << 2*(n - 1) + 1 << endl;
    return;
  }
  vector<int> fre(n);
  for(int i = 0; i < n; i++){
    if(s[i] == 'W') fre[i]=1;
    else fre[i] = 0;
  }

  int prev = -1;
  vector<int> deviate;
  for(int i = 0; i < n ; i++){
    if(fre[i] == 1){
      if(prev != -1 && (i-prev-1) != 0)
        deviate.push_back(i-prev-1);
      prev = i;
    }
  }

  sort(deviate.begin(),deviate.end());
  int ans = 0, all = 1;
  for(int i = 0; i < n; i++){
   if(fre[i] == 1){
      if(i > 0 && fre[i-1] == 1) ans += 2;
      else ans++;
      all = 0;
    }
  }
  if(all == 1){
    cout << max(0, min(2 * n - 1, 2 * k-1)) << endl;
    return;
  }
  for(int i = 0; i < deviate.size(); i++){
    if(deviate[i] <= k){
      ans += (2*deviate[i]+1);
        k -= deviate[i];
    }
  }
  if(k > 0) 
      ans += 2*k;
  cout << max(0, min(ans, 2*n-1)) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
