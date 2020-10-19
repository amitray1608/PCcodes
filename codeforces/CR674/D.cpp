//Ryuzaki
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
//geeksforgeeks comparator
bool comp(pair<int,int> &p1, pair<int,int> &p2){
  if(p1.first != p2.first)
     return p1.first < p2.first;
  return p1.second < p2.second;
}

void sine() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  unordered_map<int, int> m;
  vector<pair<int, int>> p;
  m[0] = -1;
  int sum = 0, ans = 1;
  for(int i = 0; i < n; i++){
    sum += a[i];
    if(m.find(sum) != m.end()){
      p.push_back({m[sum] + 1, i});
    }
    m[sum] = i;
  }  
  if(p.size() == 0){
   cout << 0 << '\n';
   return ;
  }
  sort(p.begin(), p.end(), comp);
  for(int i = 1; i < p.size(); i++){
    if(p[i].first >= p[i - 1].second)
      ans++;
  }
  cout << ans << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  while(t--) sine();
  return 0;
}
