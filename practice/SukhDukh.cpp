
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  int n1, n2;
  cin >> n1 >> n2;
  int count = 0;
  for (int i = 0; count < n1; i++) {
    int curr = (n1 * i + 2);
    if (curr % n2 != 0) {
      cout << curr << '\n';
      count++;
    }
  }
  return 0;
} //Hajimemashite

