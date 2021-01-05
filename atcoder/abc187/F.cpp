
    #include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define allR(x) (x).rbegin(),(x).rend()
#define mp make_pair
#define pb push_back
#define F first
#include<bits/stdc++.h>

using namespace std;

int main() {
  int n ;
  cin >> n;
  double X[n], Y[n];
  for(int i = 0; i<n ; i++){
    cin >> X[i] >> Y[i];
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = i + 1 ; j < n ; j++){
      double s = (Y[j] - Y[i]) / (X[j] - X[i]);
      if(s >= -1 && s <= 1) ans++;
    }
  }
  cout << ans;
  return 0;
}
