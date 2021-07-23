

#include<bits/stdc++.h>

using namespace std;
int lcm(int a , int b) {
	return a * b * 1LL / __gcd(a , b);
}
 
void precalc() {
	int mod=1000000007;
	int gg = 0;
	int mx = 0;
	for (int i = 2; i <=  500; i++) {
		gg = lcm(gg , i);
		gg=gg%mod;
		mx = max(mx ,gg);
		mx=mx%mod;
	}
	cout <<mx << endl;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  precalc();
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    
  }
  return 0;
} //Hajimemashite



