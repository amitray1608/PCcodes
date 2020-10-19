//“Make it work, make it right, make it fast.” – Kent Beck
#include<bitpres/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll n, qq;
vector<ll>a, h;
vector<ll>pre;
vector<ll>Pignoredsum, Pignoredpref, Pignoredby;

vector<ll> bitpre, bitpresum;

void build(){
    for (int i = 0; i < n; i++)
        add(i, a[i]);
}

int sumpre(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bitpre[r];
    return ret;
}

int sumpre(int l, int r) {
    return sumpre(r) - sumpre(l - 1);
}

void addpre(int idx, int delta) {
    for (; idx < n and h[i]; idx = idx | (idx + 1))
        bitpre[idx] += delta;
}

void calculatePref() {
  pre.resize(n, 0);
  pre[0] = a[0];
  for(ll i = 1; i < n; i++) pre[i] = pre[i-1] + a[i];
  deque<pair<ll, ll>>q;
  q.push_back({h[0], 0});
  Pignoredby.resize(n, -1);
  Pignoredsum.resize(n, 0);
  Pignoredpref.resize(n, 0);
  ll i = 1;
  Pignoredpref[0] = a[0];
  while(!q.empty() and i < n) {
   auto x = q.back();
    if(x.first <= h[i]){
      ll sum = 0;
      while(!q.empty() and q.back().first <= h[i]){
        auto xx = q.back();
        q.pop_back();
        Pignoredby[xx.second] = i;
        sum += a[xx.second];
      }
      Pignoredpref[i] = Pignoredpref[i-1] - sum + a[i];
      Pignoredsum[i] = sum;
      q.push_back({h[i], i});
    } else {
      Pignoredsum[i] = 0;
      q.push_back({h[i], i});
      Pignoredpref[i] = Pignoredpref[i-1] + a[i];
    }
    i++;
  }
  // for(ll &ii : Pignoredsum) cout << ii << ' ';
  //   cout << endl;
  // for(ll &ii : Pignoredpref) cout << ii << ' ';
  //   cout << endl;
  // for(ll &ii : Pignoredby) cout << ii << ' ';
  //   cout << endl;
}

vector<ll>arev, hrev, suf;
vector<ll>Signoredsum, Signoredpref, Signoredby;

void calculatesuff() {
  suf.resize(n, 0);
  suf[n-1] = arev[n-1];
  for(ll i = n-2; i >= 0; i--) suf[i] = suf[i+1] + arev[i];
  deque<pair<ll, ll>>q;
  q.push_back({hrev[n-1], 0});
  Signoredby.resize(n, -1);
  Signoredsum.resize(n, 0);
  Signoredpref.resize(n, 0);
  ll i = n-2;
  Signoredpref[n-1] = arev[n-1];
  while(!q.empty() and i >= 0) {
   auto x = q.back();
    if(x.first <= hrev[i]){
      ll sum = 0;
      while(!q.empty() and q.back().first <= hrev[i]){
        auto xx = q.back();
        q.pop_back();
        Signoredby[xx.second] = i;
        sum += arev[xx.second];
      }
      Signoredpref[i] = Signoredpref[i+1] - sum + arev[i];
      Signoredsum[i] = sum;
      q.push_back({hrev[i], i});
    } else {
      Signoredsum[i] = 0;
      q.push_back({hrev[i], i});
      Signoredpref[i] = Signoredpref[i+1] + arev[i];
    }
    i--;
  }
  // for(ll &ii : Signoredsum) cout << ii << ' ';
  //   cout << endl;
  // for(ll &ii : Signoredpref) cout << ii << ' ';
  //   cout << endl;
  // for(ll &ii : Signoredby) cout << ii << ' ';
  //   cout << endl;
}

void solve(){
  cin >> n >> qq;

  if(n <= 1000 and qq <= 1000) {
    brute();
    return;
  }

  h.resize(n);
  hrev.resize(n);
  for(ll &i : h) cin >> i;
  hrev = h;
  // reverse(hrev.begin(), hrev.end());
  a.resize(n);
  arev.resize(n);
  for(ll &i : a) cin >> i;
  arev = a;
  // reverse(arev.begin(), arev.end());
  calculatePref();
  // cout << endl;
  calculatesuff();
  bitpre.resize(n, 0);
  build();
  // cout << endl;
  // for(ll &i : arev) cout << i << ' ';
  //   cout << endl;
  // for(ll &i : hrev) cout << i << ' ';
  //   cout << endl;
  while(qq--){
    int t;
    cin >> t;
    if(t == 1) {
      int l, x;
      cin >> l >> x;
      l--;
      update
      continue;
    } else {
      ll l, r;
      cin >> l >> r;
      l--, r--;
      if(l == r){
        cout << a[l] << endl;
      } else if(l < r) {
        // cout << "inc" << endl;
        // deb(l);
        // deb(r);
        if(Pignoredby[l] > l and Pignoredby[l] <= r){
          cout << -1 << endl;  
        } else {
          cout << Pignoredpref[r] - (l-1 >= 0 ? Pignoredpref[l-1] : 0) + Pignoredsum[l] << endl;      
        }
      } else {
        // cout << "dec" << endl;
        // l = n-l-1;
        // r = n-r-1;
        // deb(l);
        // deb(r);        
        // swap(l, r);
        if(Signoredby[l] >= r and Signoredby[l] < l){
          cout << -1 << endl;
        } else {
          cout << Signoredpref[r] - ((l+1 <= n-1) ? Signoredpref[l+1] : 0) + Signoredsum[l] << endl;
        }        
      }
    }
  }

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
7 4
5 7 3 4 4 1 8
1 2 3 4 5 6 7
2 5 2
2 5 3
2 3 4
2 1 4

5 4
3 1 4 1 5
1 2 4 8 16
2 5 2
2 5 3
2 3 4
2 4 4
*/


void brute() {
  h.resize(n, 0);
  a.resize(n, 0);
  for(ll &i : h) cin >> i;
  for(ll &i : a) cin >> i;
  while(qq--) {
    ll t, l, r;
    cin >> t >> l >> r;
    l--;
    if(t == 1) {
      a[l] = r;
    } else {
      r--;
      if(l > r) {
        ll maxi = INT_MIN, mini = INT_MAX;
        for(ll i = l-1; i >= r; i--) {
          mini = min(mini, h[i]);
          maxi = max(maxi, h[i]);
        }
        if((maxi >= h[l])){
            cout << -1 << endl;
            continue;
        } else {
          ll sum = a[l];
          bool flag = true;
          ll prev = INT_MIN;
          for(ll i = r; i < l; i++){
            if(h[i] < h[l] and h[i] > prev)
              sum += a[i], prev = h[i];
            // else {
            //   flag = false;
            //   break;
            // }
          }
          if(flag)
            cout << sum << endl;
          else
            cout << -1 << endl;
        }
      } else {
        ll maxi = INT_MIN, mini = INT_MAX;
        for(ll i = l+1; i <= r; i++) {
          mini = min(mini, h[i]);
          maxi = max(maxi, h[i]);
        }
        if((maxi >= h[l])){
          cout << -1 << endl;
          continue;
        } else {
          bool flag = true;
          ll sum = a[l];
          ll prev = INT_MIN;
          for(ll i = r; i > l; i--){
            if(h[i] < h[l] and prev < h[i])
              sum += a[i], prev = h[i];
            // else {
            //   flag = false;
            //   break;
            // }
          }
          if(flag)
            cout << sum << endl;
          else
            cout << -1 << endl;
        }
      }
    }
  }
}


r
16627951
DOB -
25/2/2002
sync_with_stdio
39316
center
3714

AS953914  