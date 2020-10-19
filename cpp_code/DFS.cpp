//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define deb(x) cout << #x << " = " << x << endl;
//--------------------------------------------------------------------//
#define loop(i, a, n) for(ll i = a; i < n; i++)
#define rloop(i, a, n) for(ll i = n-1; i >= 0; i--)
#define vi vector<int> 
#define vl vector<ll>
#define vd vector<dd>
#define prii pair<int, int>
#define prll pair<ll, ll>
#define vpi vector<prii>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define all(x)  x.begin(), x.end()
//--------------------------------------------------------------------//
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T lcm(T a, T b ){return (a*b)/gcd(a,b);}

ll power(ll a, ll n) 
{
	ll p = 1;
	while (n > 0){
		if(n%2){
			p = p * a;
		}
		 n >>= 1;
		  a *= a;
	} 
return p;
}
//--------------------------------------------------------------------//
vi G[siz];
bool vis[siz];
void dfs(int s){
	vis[s] = true;
	cout << s << endl;
	for(int i : G[s]){
		if(!vis[i])
			dfs(i);
	}
}

void dfs_itr(int s){
	stack <int> st;
	st.push(s);
	while(!st.empty()){
		s = st.top();
		st.pop();
			cout << s << " ";
		for(auto i = G[s].begin(); i != G[s].end(); i++){
				if(!vis[*i])
					st.push(*i), vis[*i] = true;
		}
		
	}
}

void BFS(int s) 
{ 
  
    list<int> queue; 
  
    vis[s] = true; 
    queue.push_back(s); 
  
    while(!queue.empty()) 
    { 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 

        for (auto i = G[s].begin(); i != G[s].end(); ++i) 
        { 
            if (!vis[*i]) 
            { 
                vis[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 




void solve(){
	memset(vis, false, sizeof vis);
	int n, m;
	cin >> n >> m;
	while(m--){
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1);
	
	//if(vis[6]) cout << "road hai" << endl;
	//else cout << "Road nai hai" << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}

}
	
