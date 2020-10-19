//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const int inf = 1e9;
vector<int>prime;
vector<vector<pair<int, int>>>adj;
const int n = 10000;
bool one(int x, int y){
	int count = 0;
	while(x > 0){
		if(x%10 != y%10) count++;
		x /= 10;
		y /= 10;
	}
	if(count == 1)
		return true;
	else
		return false;
}

void listt(){
	adj.resize(10000);
	int x = prime.size();
	for(int i = 0; i < x-1; i++){
		for(int j = i+1; j < x; j++){
			if(one(prime[i], prime[j])){
				adj[prime[i]].push_back({1, prime[j]});
				adj[prime[j]].push_back({1, prime[i]});
				//cout << prime[i] << " " << prime[j] << endl;
			}
		}
	}
}

void seive(){
	for(int i = 1000; i < 10000; i++){
		int x = i, flag = 1;
		for(int j = 2; j*j <= i; j++){
			if(x % j == 0){
				flag = 0;
				break;
			}
		}
		if(flag)
			prime.push_back(i);
	}
}
void solve(){
	int nn, m;
	cin >> nn >> m;
	vector<int>dis(n, inf);
	vector<bool>vis(n, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	dis[nn] = 0;
	pq.push(make_pair(0, nn));
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		vis[u] = true;
		for(auto &i : adj[u]){
			int v = i.second, x = i.first;
			if(!vis[v] && dis[v] > dis[u] + x){
				dis[v] = dis[u]+x;
				pq.push(make_pair(dis[v], v));
			}
		}
	}
	//for(int i = 0; i  < n; i++)
	if(dis[m] >= inf)
		cout << "Impossible" << endl;
	else
		cout << dis[m] << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		seive();
		listt();
		while(t--){
			solve();
			//cout << t << endl;
		}
	return 0;
}	
