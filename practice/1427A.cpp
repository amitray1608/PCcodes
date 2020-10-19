//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0, pos = 0, neg = 0;
  for(int &i : a) {
    cin >> i, sum += i;
    if(i < 0) neg += i;
    else pos += i;
  }
  if(sum == 0) cout << "NO" << endl;
  else {
    sort(a.begin(), a.end());
    cout << "YES" << endl;
    if(abs(neg) > pos) {
      for(int &i : a) cout << i << ' '; 
    } else {
      reverse(a.begin(), a.end());
      for(int &i : a) cout << i << ' ';
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
