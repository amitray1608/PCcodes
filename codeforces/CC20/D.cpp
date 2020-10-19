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
        string y;
        cin >> y;
        map<string , int > arr;
        int k = 0 , r = 0;
        string A = "z";
        int ansy = 0;
        string x = y;
        for(int i = 1 ; i<= n;i++)
        {
            k = i;
            x = y;
            for(int j = 0 ;j < n ;j++)
            {
                r = j + k - 1;
                if(r >= n)break;
                reverse(x.begin()+j, x.begin() + r + 1);
            }
            //cout<<x<<endl;
            if(x < A)
            {
                A = x;
            ansy  = i;
            }
        }
 
        cout<<A<<endl;
        cout<<ansy<<endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int cp = 1;
		cin >> cp;
		while(cp--){
			solve();
		}
	return 0;
}
