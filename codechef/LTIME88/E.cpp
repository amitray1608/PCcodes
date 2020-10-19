//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto check = [&](vector<int>x, int N) {
    int count = 0;
    for(int i = 0; i < N; i++)
      for(int j = i+1; j < N; j++)
        if(x[i] > x[j]) count++;
    return count;
  };
  
  bool ans = false;
  for(int i = 0; i < (1 << n); i++) {
    vector<int> inc, exc;
    for(int j = 0; j < n; j++) {
      if((i & (1 << j)) > 0)
        inc.push_back(a[j]);
      else
        exc.push_back(a[j]);
    }
    int N = (int)inc.size(), M = (int)exc.size();
    int counta = check(inc, N);
    int countb = check(exc, M);
    if(counta == countb) {
      ans = true;
      break;
    }
  }
  cout << (ans ? "YES" : "NO") << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
