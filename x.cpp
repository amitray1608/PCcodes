	#include<bits/stdc++.h>
	using namespace std;
	#define endl '\n'
	#define deb(x) cout << #x << " = " << x << endl;
	typedef long long ll;
	typedef double dd;
	const int MOD = 1e9 + 7;

	void solve(){
		
	}

	int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
		return 0;
	}

#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 

	//vector debug
	template<typename T>
	string to_string(vector<T> v) {
	  string res;
	  for(auto &i : v)
	    res += char('0'+i), res += ' ';
	  return res;
	}
	 
	template<class A> void vbug(A x) {
	  cout << to_string(x) << endl;
	}


//MOD inv upto n
void MODularInverse(ll n) { 
  ll dp[n + 1]; 
  dp[0] = dp[1] = 1; 
  for (ll i = 2; i <= n; i++)  
    dp[i] = dp[MOD % i] * (MOD - MOD / i) % MOD;     
} 


//MODulo operation functions.
ll MODpow(ll base, ll exp) {
  ll res=1;
  while(exp>0) {
    if(exp%2==1) res=(res*base)%MOD;
      base=(base*base)%MOD;
      exp/=2;
  }
  return res%MOD;
}
 
	ll MODadd(ll x, ll y){return (x % MOD + y % MOD) % MOD;}
	ll MODmul(ll x, ll y){return (x % MOD * y % MOD) % MOD;}
	ll MODsub(ll x, ll y){return (x % MOD - y % MOD + MOD) % MOD;}
	ll MODdiv(ll x, ll y){return MODmul(x, mpow(y, MOD-2));}


	int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
	int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
	int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
	int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


ll gcd(ll a, ll b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

	ll extGCD(ll a, ll b, ll &x, ll &y) {
		if (b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		ll d = extGCD(b, a%b, y, x);
		y -= a / b * x;
		return d;
	}

ll M = 1000000007;

vector<ll> fac(1000001); //n!(MOD M)
vector<ll> ifac(1000001); //k!^{M-2} (MOD M)

ll mpow(ll x, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % MOD;
		x = x * x % M;
		n = n >> 1;
	}
	return ans;
}
//inverse
void inverse(){
inv[1] = 1;
for (int i=2; i<p; ++i)
	inv[i] = (p - (p/i) * inv[p%i] % p) % p;	
}
//MOD power
	ll mpow2(ll x, ll n) {
	  ll ans = 1;
	  while (n != 0) {
	    if (n & 1) ans = ans * x % MOD;
	    x = 1LL * x * x % MOD;
	    n >>= 1;
	  }
	  return ans;
	}

	ll comb(ll n, ll k){
	    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
	}

	void setcomb() {
	  fac.resize(siz);
	  ifac.resize(siz);
	  fac[0] = 1LL;
	  ifac[0] = 1LL;
	  for (ll i = 1; i < siz; i++) {
	    fac[i] = (fac[i-1] * i) % MOD; 
	  }
	  ifac[siz-1] = mpow2(fac[siz-1], MOD - 2LL);
	  for (ll i = siz-2; i >= 0; i--) {
	    ifac[i] = 1LL * ifac[i+1] * (i+1) % MOD;
	  }
	}

ll comb(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	ll tmp = ifac[a - b] * ifac[b] % M;
	return tmp * fac[a] % M;
}
ll perm(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	return fac[a] * ifac[a - b] % M;
}
long long MODinv(long long a) {
	long long b = M, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= M;
	if (u < 0) u += M;
	return u;
}
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b, int n) {
	int i, j, k, t;
	vector<vector<ll>> c(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			t = 0;
			for (k = 0; k < n; k++)
				t = (t + a[i][k] * b[k][j] % M) % M;
			c[i].push_back(t);
		}
	}
	return c;
}

template< typename Monoid >
struct SegmentTree {
	using F = function< Monoid(Monoid, Monoid) >;

	int sz;
	vector< Monoid > seg;

	const F f;
	const Monoid M1;

	SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
		sz = 1;
		while (sz < n) sz <<= 1;
		seg.assign(2 * sz, M1);
	}

	void set(int k, const Monoid &x) {
		seg[k + sz] = x;
	}

	void build() {
		for (int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	void update(int k, const Monoid &x) {
		k += sz;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	Monoid query(int a, int b) {
		Monoid L = M1, R = M1;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a++]);
			if (b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	Monoid operator[](const int &k) const {
		return seg[k + sz];
	}

	template< typename C >
	int find_subtree(int a, const C &check, Monoid &M, bool type) {
		while (a < sz) {
			Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
			if (check(nxt)) a = 2 * a + type;
			else M = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}


	template< typename C >
	int find_first(int a, const C &check) {
		Monoid L = M1;
		if (a <= 0) {
			if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
			return -1;
		}
		int b = sz;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) {
				Monoid nxt = f(L, seg[a]);
				if (check(nxt)) return find_subtree(a, check, L, false);
				L = nxt;
				++a;
			}
		}
		return -1;
	}

	template< typename C >
	int find_last(int b, const C &check) {
		Monoid R = M1;
		if (b >= sz) {
			if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
			return -1;
		}
		int a = sz;
		for (b += sz; a < b; a >>= 1, b >>= 1) {
			if (b & 1) {
				Monoid nxt = f(seg[--b], R);
				if (check(nxt)) return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}
};

template< unsigned MOD >
struct RollingHash {
	vector< unsigned > hashed, power;

	inline unsigned mul(unsigned a, unsigned b) const {
		unsigned long long x = (unsigned long long) a * b;
		unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
		asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (MOD));
		return m;
	}

	RollingHash(const string &s, unsigned base = 10007) {
		int sz = (int)s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;
		for (int i = 0; i < sz; i++) {
			power[i + 1] = mul(power[i], base);
			hashed[i + 1] = mul(hashed[i], base) + s[i];
			if (hashed[i + 1] >= MOD) hashed[i + 1] -= MOD;
		}
	}

	unsigned get(int l, int r) const {
		unsigned ret = hashed[r] + MOD - mul(hashed[l], power[r - l]);
		if (ret >= MOD) ret -= MOD;
		return ret;
	}

	unsigned connect(unsigned h1, int h2, int h2len) const {
		unsigned ret = mul(h1, power[h2len]) + h2;
		if (ret >= MOD) ret -= MOD;
		return ret;
	}

	int LCP(const RollingHash< MOD > &b, int l1, int r1, int l2, int r2) {
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
			else high = mid;
		}
		return (low);
	}
};

using RH = RollingHash< 1000000007 >;

	template<typename T>
	class BIT {
	  int n;
	  vector<T> bit;
	public:
	  BIT(int N) {
	    bit.assign(N + 1 , 0);
	    n = N;
	  }
	  void update(int idx , T val) {
	    idx++;
	    while(idx <= n) {
	      bit[idx] += val;
	      idx += (idx & -idx);
	    }
	  }
	  int sum(int idx) {
	    idx++;
	    T res = 0;
	    while(idx > 0) {
	      res += bit[idx];
	      idx -= (idx & -idx);
	    }
	    return res;
	  }
	 
	};


//TEMPLATE
//Helper functions for contests
//Binary expo
ll power(ll a, ll n) {
	ll p = 1;
	while (n > 0){
		if(n%2) p = p * a;
		
		 n >>= 1, a *= a;
	} 
return p;
}
//seive
	vector<int>is_prime;
	void seive(int n) {
		is_prime.assign(n+1, true);
		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i * i <= n; i++) {
		    if (is_prime[i]) {
		        for (int j = i * i; j <= n; j += i)
		            is_prime[j] = false;
		    }
		}
	}


//MODular class
template <int MOD>
struct MODular {
	int val;

	MODular(long long _val = 0) {
		if (_val < 0 || _val >= MOD) {
			val = _val % MOD;
			if (val < 0) {
				val += MOD;
			}
		} else {
			val = _val;
		}
	}

	MODular operator +(const MODular& ot) const {
		int res = val + ot.val;
		if (res >= MOD) {
			res -= MOD;
		}
		return {res};
	}

	MODular operator -(const MODular& ot) const {
		int res = val - ot.val;
		if (res < 0) {
			res += MOD;
		}
		return {res};
	}

	MODular operator *(const MODular& ot) const {
		return {1ll * val * ot.val};
	}

	MODular& operator ++() {
		val += 1;
		if (val == MOD) {
			val = 0;
		}
		return *this;
	}

	MODular operator ++(int) {
		MODular tmp(*this);
		operator ++();
		return tmp;
	}

	void operator +=(const MODular& ot) {
		val += ot.val;
		if (val >= MOD) {
			val -= MOD;
		}
	}

	void operator -=(const MODular& ot) {
		val -= ot.val;
		if (val < 0) {
			val += MOD;
		}
	}

	void operator *=(const MODular& ot) {
		val = 1ll * val * ot.val % MOD;
	}

	bool operator ==(const MODular& ot) const {
		return val == ot.val;
	}

	bool operator !=(const MODular& ot) const {
		return val != ot.val;
	}

	MODular inv() const {
		return ::inv(val, MOD);
	}
};

template <int MOD>
ostream& operator <<(ostream& ostr, const MODular<MOD>& x) {
	return ostr << x.val;
}

const int MOD = 1000000007;
using Mint = MODular<MOD>;


//DSU

template<typename T>
class dsu {
  public:
    vector<T>p;
    vector<T>rank;
    ll n;

    dsu(ll _n) : n(_n) {
      p.resize(n);
      rank.resize(n);
      iota(p.begin(), p.end(), 0);
      fill(rank.begin(), rank.end(), 1);
    }
    inline T root(T x) {
      return (x == p[x] ? x : (p[x] = root(p[x])));
    }
    
    inline bool same(int u, int v) {
        return(root(u) == root(v));
    }

    inline void unite(T x, T y) {
      x = root(x);
      y = root(y);
      if(x != y) {
        if(rank[y] < rank[x]) 
          swap(x, y);
        p[x] = y;
        if(rank[x] == rank[y])
          rank[y]++;
      }
    }
};

//DIJK
	const int INF = 1e9;
	typedef pair<int, int> pri;
	vector<vector<pri>>adj;
	vector<int>dis;

	void dijk(int s) {
	  priority_queue<pri, vector<pri>, greater<pri>>q;
	  dis[s] = 0;
	  q.push({0, s});
	  while(!q.empty()) {
	    auto x = q.top();
	    q.pop();
	    int u = x.second;
	    if(x.first == INF) continue;
	    for(auto i : adj[u]) {
	      int v = i.first;
	      int c = i.second;
	      if(dis[v] > dis[u]+c) {
	        dis[v] = dis[u]+c;
	        q.push({dis[v], v});
	      }
	    }
	  }
	}

//Balmon Ford
void balmon()
{
    vector<int> d (n, INF);
    d[v] = 0;
    vector<int> p (n, -1);

    for (;;)
    {
        bool any = false;
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        if (!any)  break;
    }

    if (d[t] == INF)
        cout << "No path from " << v << " to " << t << ".";
    else
    {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back (cur);
        reverse (path.begin(), path.end());

        cout << "Path from " << v << " to " << t << ": ";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
    }
}

//SegTree
pair<int, int> t[4*MAXN];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

//LAZY update
void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

//ARTICULATION POINT
int n, m;
vector<vector<int>>adj;
vector<bool>vis, ans;
vector<int>tin, low;

int timer;
int counts = 0;
void dfs(int v, int p = -1) {
  vis[v] = true;
  tin[v] = low[v] = timer++;
  int child = 0;
  for(int to : adj[v]) {
    if(to == p) continue;
    if(vis[to])
      low[v] = min(low[v], tin[to]);
    else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if(low[to] >= tin[v] and p != -1)
        ans[v] = true;
      child++;
    }
  }
  if(p == -1 and child > 1)
    ans[v] = true;
}

//Bridges
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}


//Euler Path

  int n;
  cin >> n;
  vector<vector<int> > g(n, vector<int> (n));
  vector<int> deg(n);

  //take g in put;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      deg[i] += g[i][j];
  }

  //To check whether the graph is isolated.

  int first = 0;
  while(first < n and !deg[first])
    ++first;
  if(first == n) {
    cout << -1 << endl;
    return;
  }

  //Find starting and ending node;

  int v1 = -1, v2 = -1;
  bool bad = false;
  for(int i = 0; i < n; i++) {
    if(deg[i]&1) {
      if(v1 == -1) 
        v1 = i;
      else if(v2 == -1)
        v2 = i;
      else
        bad = true;
    }
  }

  // Add an edge to the start and end vertex
  if(v1 != -1) {
    ++g[v1][v2], ++g[v2][v1];
  }

  // DFS to find out the path.
  stack<int>st;
  st.push(first);
  vector<int> res;
  while(!st.empty()) {
    int v = st.top();
    int i;
    for(i = 0; i < n; i++)
      if(g[v][i])
        break;
      if(i == n) {
        res.push_back(v);
        st.pop();
      } else {
        --g[v][i];
        --g[i][v];
        st.push(i);
      }
  }

// Put the path in correct order.

  if(v1 == -1) {
    for(int i = 0; i + 1 < res.size(); ++i) {
      if((res[i] == v[1] and res[i+1] == v2) or (res[i] == v2 and res[i+1] == v1)) {
        vector<int> res2;
        for(int j = i+1; j < res.size(); j++)
          res2.push_back(res[j]);
        for(int j = i; j <= i; j++)
          res2.push_back(res[j]);
        res = res2;
        break;
      }
    }
  }

  //Check for the left edges.
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(g[i][j])
        bad = true;
    }
  }

  if(bad)
    cout << -1 << endl;
  else
    for(auto x : res)
      cout << x << ' ';


//INV FACT COMB PER 
ll M = 1000000007;

vector<ll> fac(1000001); //n!(MOD M)
vector<ll> ifac(1000001); //k!^{M-2} (MOD M)

ll mpow(ll x, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
		n = n >> 1;
	}
	return ans;
}
void inverse(){
inv[1] = 1;
for (int i=2; i<p; ++i)
	inv[i] = (p - (p/i) * inv[p%i] % p) % p;	
}
ll mpow2(ll x, ll n, ll MOD) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		n = n >> 1;
	}
	return ans;
}
void setcomb() {
	fac[0] = 1;
	ifac[0] = 1;
	for (ll i = 0; i < 1000000; i++) {
		fac[i + 1] = fac[i] * (i + 1) % M; // n!(MOD M)
	}
	ifac[1000000] = mpow(fac[1000000], M - 2);
	for (ll i = 1000000; i > 0; i--) {
		ifac[i - 1] = ifac[i] * i%M;
	}
}
ll comb(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	ll tmp = ifac[a - b] * ifac[b] % M;
	return tmp * fac[a] % M;
}
ll perm(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	return fac[a] * ifac[a - b] % M;
}
ll MODinv(ll a) {
	ll b = M, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= M;
	if (u < 0) u += M;
	return u;
}
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b, int n) {
	int i, j, k, t;
	vector<vector<ll>> c(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			t = 0;
			for (k = 0; k < n; k++)
				t = (t + a[i][k] * b[k][j] % M) % M;
			c[i].push_back(t);
		}
	}
	return c;
}

//Toplogical sort 
int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
//Strongly connected comp
vector < vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;

void dfs1 (int v) {
  used[v] = true;
  for (size_t i=0; i<g[v].size(); ++i)
    if (!used[ g[v][i] ])
        dfs1 (g[v][i]);
  order.push_back (v);
}

void dfs2 (int v) {
  used[v] = true;
  component.push_back (v);
  for (size_t i=0; i<gr[v].size(); ++i)
    if (!used[ gr[v][i] ])
        dfs2 (gr[v][i]);
}
min(){
used.assign (n, false);
for (int i=0; i<n; ++i)
    if (!used[i])
        dfs1 (i);
used.assign (n, false);
for (int i=0; i<n; ++i) {
    int v = order[n-1-i];
    if (!used[v]) {
        dfs2 (v);
        ... printing next component ...
        component.clear();
    }
}
}


//DP 
//substring
int lcs(int i, int j, int count)  
{ 
      
    if (i == 0 || j == 0) 
        return count; 
          
    if (X[i-1] == Y[j-1]) { 
        count = lcs(i - 1, j - 1, count + 1); 
    } 
        count = max(count, max(lcs( i, j - 1, 0), lcs( i - 1, j, 0))); 
    return count; 
} 
//subequence
int lcs( char *X, char *Y, int m, int n )  
{  
    if (m == 0 || n == 0)  
        return 0;  
    if (X[m-1] == Y[n-1])  
        return 1 + lcs(X, Y, m-1, n-1);  
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));  
}  
//Matrix Chain Mult
int MatrixChainOrder(int p[], int n) 
{ 
  
    int m[n][n]; 
  
    int i, j, k, L, q; 
  
    for (i = 1; i < n; i++) 
        m[i][i] = 0; 
  
    for (L = 2; L < n; L++) 
    { 
        for (i = 1; i < n - L + 1; i++) 
        { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            { 
                q = m[i][k] + m[k + 1][j] +  
                    p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 
} 
int Knapsack(int capacity,int n,int weight[],int value[]){
	int res[20][20];
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < capacity+1; ++j)
		{
			if(i==0||j==0)
				res[i][j] = 0;
			else if(weight[i-1]<=j)
				res[i][j] = max(value[i-1]+res[i-1][j-weight[i-1]], res[i-1][j]);
			else
				res[i][j] = res[i-1][j];
		}
	}
//	Print(res, n, capacity, capacity);
//	cout<<"\n";
	return res[n][capacity];
}
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int lcs( char *X, char *Y, int m, int n )  
{  
    int L[m + 1][n + 1];  
    int i, j;  

    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
          
    return L[m][n];  
}  
int LCSubStr(char *X, char *Y, int m, int n) 
{ 
    // Create a table to store lengths of longest 
    // common suffixes of substrings.   Note that 
    // LCSuff[i][j] contains length of longest 
    // common suffix of X[0..i-1] and Y[0..j-1].  
  
    int LCSuff[m+1][n+1]; 
    int result = 0;  
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            if (i == 0 || j == 0) 
                LCSuff[i][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
            { 
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
                result = max(result, LCSuff[i][j]); 
            } 
            else LCSuff[i][j] = 0; 
        } 
    } 
    return result; 
} 
  
