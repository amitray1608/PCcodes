
#include <bits/stdc++.h>

using namespace std;

const int maxn = 6;
map<pair<int, int>, int> dist;


void dijkstra(int s, int d) {
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int curr = 0;
  map<pair<int, int>, int> convert;
  map<int, pair<int, int>> invert;
  for (int i = 0; i < maxn; i++) {
  	for (int j = 0; j < maxn; j++) {
  		mp[{i, j}] = curr++;
  		invert[curr] = {i, j};
  	}
  }
	vector<vector<int>> mz(6, vector<int>(6, INT_MAX));  
  for (int i = 0; i < maxn; i++) {
  	for (int j = 0; j < maxn; j++) {
  		for (int k = 0; k < maxn; k++) {
  			for (int l = 0; l < maxn; l++) {
  				if (i != k and j != l) {
  					dijkstra(mp[{i, j}], mp[{k, l}]);
  				}
  			}
  		}
  	}
  }
  return 0;
} 
