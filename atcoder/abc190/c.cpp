#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  vector<int> cnt(n + 1, 0);
  for (int i = 0; i < m; i++) { 
    cin >> a[i].first >> a[i].second;
    cnt[a[i].first]++;
    cnt[a[i].second]++;
  }
  int k;
  cin >> k;
  vector<int> dish(n + 1, 0);
  vector<pair<int, int>> b(k);
  for (int i = 0; i < k; i++) {
    cin >> b[i].first >> b[i].second;
    if(cnt[b[i].first] >= cnt[b[i].second] and dish[b[i].first] == 0) {
      if(dish[b[i].first] and dish[b[i].second] == 0) 
        dish[b[i].second] = 1;
      else 
        dish[b[i].first] = 1;
    } else {
      if(dish[b[i].second] and dish[b[i].first] == 0)
        dish[b[i].first] = 1;
      else
        dish[b[i].second] = 1;
    }
  }

  int count = 0;
  for (int i = 0; i < m; i++)
    if (dish[a[i].first] and dish[a[i].second]) count++;
  cout << count << '\n';
  return 0;
} //Hajimemashite
