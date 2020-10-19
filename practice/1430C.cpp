//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  deque<int> q;
  for (int i = n; i > 0; i--) {
    q.push_back(i);
  }
  vector<pair<int, int>> ans;
  while(q.size() > 1) {
    int x = q.front(); q.pop_front();
    int y = q.front(); q.pop_front();
    ans.push_back({x, y});
    q.push_front((x+y+1)/2);
  }
  cout << q.front() << endl;
  for(auto i : ans) 
    cout << i.first << ' ' << i.second << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
