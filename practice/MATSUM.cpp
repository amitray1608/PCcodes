
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    a.resize(n, vector<int>(n, 0));
       
  }	
  return 0;
} //Hajimemashite

/*
1 2 3 5 4

//All possible k + 1 subsequence.
1 2 3
1 2 4
1 2 5
1 3 5
1 3 4
2 3 4
2 3 5
*/
