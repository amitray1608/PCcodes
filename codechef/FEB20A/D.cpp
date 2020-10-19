//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<int> factors(int x){
	vector<int>ans;
	int i = 1;
	while(i*i < x){
		if(x%i == 0){
		ans.push_back(i);
		if(i != x/i)
		ans.push_back(x/i);
		}
		i++;
	}
	return ans;
}
int calc(int x[], unordered_map<int, bool>check, unordered_map<int, bool>check1, int n, map<int, vector<int>>fac){
    ll count = 0;
    for(int i = 0; i < n; i++){
		if(x[i] == 0) continue;
        ll tmp = x[i] * x[i];
        vector<int>f = fac[tmp];
        for(int ii : f){
			cout << ii << " ";
			if(check[ii] && check1[tmp/ii])
				count++;
			if(ii == tmp/ii) continue;
			if(check1[ii] && check[tmp/ii])
				count++;
        }
        cout << endl;
    }
    cout << endl;
    return count;
}

void solve(){
	int n, m;
	cin >> n >> m;
	int x[n], y[m];
	for(int &i : x) cin >> i;
	for(int &i : y) cin >> i;
	
    unordered_map <int, bool> left, right, up, down;
		map<int , vector<int>>fac;
        for(int i = 0; i < m; i++){
            if(y[i] < 0)
                down[-y[i]] = true, y[i] = -y[i];
            else
                up[y[i]] = true;
            fac[y[i]*y[i]] = factors(y[i]*y[i]);
        }
        for(int i = 0; i < n; i++){
            if(x[i] < 0)
                left[-x[i]] = true, x[i] = -x[i];
            else
                right[x[i]] = true;
            fac[x[i]*x[i]] = factors(x[i]*x[i]);
        }
        

        ll count;
        count = calc(x, up, down, n, fac);
			count += calc(y, left, right, m, fac);
        if(right[0] == 1 && up[0] == 1)
            count += (n-1) * (m-1);
        else if(up[0] == 1)
            count += n * (m-1);
        else if(right[0] == 1)
            count += (n-1) * m;
        cout << count << endl;

}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}

/*
2
2 2
-4 2
2 -8
8 4
1 2 3 6 -1 -2 -3 -6
6 -6 1 -1
* */
