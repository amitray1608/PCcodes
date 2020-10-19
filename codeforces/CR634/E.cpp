//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int maxi = 0, pos = 0, ans = 0;
	for(int i = 0; i < n/2; i++){
		int lfre[27] = {0}, rfre[27] = {0};
		for(int j = 0; j <= i; j++){
			lfre[a[j]]++, rfre[a[n-j-1]]++;
		}
		//for(int i = 1; i < 27; i++)
			//cout << lfre[i] << " ";
		//cout << endl;
		for(int ii = 1; ii <= 26; ii++){
			if(lfre[ii] > maxi && rfre[ii] > maxi)
				maxi = min(lfre[ii], rfre[ii]), pos = i, ans = maxi*2; 
		}
	}
	int fre[27] = {0};
	deb(pos);
	int ab = n-pos;
	deb(ab);
	for(int i = pos+1; i < n-pos; i++){
			fre[a[i]]++;
	}
	if(n == 1)
		ans = 1;
	//deb(pos);
	ans += *max_element(fre, fre+27);
	cout << ans << endl;

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
