
#include <bits/stdc++.h>

using namespace std;


map<int, int> mp;c
onst int MAXN = 1e6 + 10;
vector<int> spf(MAXN);

void sieve(){
	iota(spf.begin(), spf.end() , 0);
//	for (int i = 4 ; i < MAXN ;  i += 2)
//		spf[i] = 2;
	for (int i = 2 ; i * i < MAXN ; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < MAXN ;  j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

bool getF(int x){
	set<int> factors;
	while (x != 1) {
		factors.insert(spf[x]);
		x = x / spf[x];
	}
  for (int i : factors) {
    if (mp.find(i) != mp.end()) return false;
    mp[i]++;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  sieve();
  int n;
  cin >> n;
  vector<int> a(n);
  int gc = 0;
  bool setwise = false, pairwise = true;
  for (int &i : a) cin >> i, gc = __gcd(gc, i);
  if (gc == 1) setwise = true;
	for (int i : a) {
    pairwise &= getF(i);
	}
	if (pairwise) {
		cout << "pairwise coprime" << '\n';
	} else if (setwise) {
		cout << "setwise coprime" << '\n';
	} else {
		cout << "not coprime" << '\n';
	}
  return 0;
} //Hajimemashite
