
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a;
  for (int &i : a) {
    cin >> i;
  }
  long long res = 0;

  cout << a.size() << '\n';
  for (int i : a) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
} //Hajimemashite

