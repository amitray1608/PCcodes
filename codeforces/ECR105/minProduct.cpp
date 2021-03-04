
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int prod = 1, mini = 1;
  
  for (int i = 0; i < k; i++) 
    prod *= a[i];

  mini = prod;
  for (int i = k; i < n; i++) {
    prod /= a[i - k];
    prod *= a[i];
    mini = min(prod, mini);
  }
  cout << mini << '\n';

  return 0;
} //Hajimemashite
