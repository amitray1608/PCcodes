#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
ll mod = 1e9+7;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	int ac = 0, bb = 0, count = 0, turn = 1, last = 0, curr = 0;
	int i = 0, j = n-1;
	while(i <= j){
		curr = 0;
		if(turn){
			while(i <= j and curr <= last)
				curr += a[i++];
			ac += curr;
		}else{
			while(i <= j and curr <= last)
				curr += a[j--];
			
			bb += curr;
		}
		count++;
		turn = 1 - turn;
		last = curr;
	}
	cout << count << " " << ac << " " << bb << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
	
