#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll>BIT;
ll n;

ll sum(ll index) {
	ll s = 0;
	while(index >= 0) {
		s += BIT[index];
		index -= index&(-index);
	}
	return s;
}

void update(ll index, ll val) {
	while(index < n) {
		BIT[index] += val;
		index += index&(-index);
	}
}


int main() {
  cin >> n;
  vector<int> a(2 * n + 1);
  BIT.resize(n + 1, 0);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    a[n + i] = x;
  }
  //for (int i = 0; i <  2 * n + 1; i++) cout << a[i] << ' ';
  //cout << endl;
  vector<ll> ans;
  ll count = 0;
  for(int i = 0; i < n; i++) {
    update(a[i], 1);
    count += sum(n) - sum(a[i]);
  }
  for (int i = 0; i < n; i++) {
    count += sum(n) - sum(a[i]);
    count -= sum(a[i] - 1);
    ans.push_back(count);
  }
  
  for (int i = 0; i < n; i++) {
    cout <<  ans[i] << '\n';
  }

  return 0;
} //Hajimemashite
