//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int check(int beg, int end, int x, string s)
{
	int sum = 0;
	for(int i=beg; i<end; i++){
		sum += s[i] == '(' ? 1 : -1;
		if(sum == x) return i;
	}
	return -1;
}

void solve(){
    int n;      
    cin >> n;
    string S;   
    cin >> S;
 
    int Sum = 0;
    int ans = 0;
 
    for(char c : S) {
        if (c == '(')   Sum++;
        if (c == ')')   Sum--;
 
        if (Sum < 0)
            ans++;
        if (Sum == -1 && c == ')')
            ans++;
    }
    if (Sum)    {
        cout << -1;
        return ;
    }
    cout << ans << endl;
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
	return 0;
}
	
