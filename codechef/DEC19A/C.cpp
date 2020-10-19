	#include<bits/stdc++.h>
using namespace std;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
typedef unsigned long long ll;
#define deb(x) cout << #x << " = " << x << endl;
	
//~ string And(string a, string b){
	//~ int siz = max((int)a.size(), (int)b.size());
	//~ string s;
	//~ int j = min((int)a.size(), (int)b.size());
	//~ for(int i = siz-1; i>=0;; i++){
		//~ if(a[i] == b[])
	//~ }
//~ }


void fun(ll a, ll b){
	int count = 0;
	ll u, v;
	while(b > 0){
		u = a^b;
		v = a&b;
		a = u;
		b = 2*v;
		count++;
		//cout << "A = " << to_string(u) << endl;
		//cout << "B = " << to_string(b) << endl;
		deb(a);
		deb(b);	
	}
	cout << count << endl;
	cout << endl;
}

int main(){
		int t;
		cin >> t;
		while(t--){
        string a, b;
        cin >> a >> b;	
        if (b.length() == 1 && b[0] == '0') {
            cout << 0 << endl;
        } else {
            int cur = 0, longest = 0;
            for(int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
                char aa = i >= 0 ? a[i] : '0', bb = j >= 0 ? b[j] : '0';
                if (aa == bb) {
                    if (cur > longest) longest = cur;
                    cur = aa == '1';
                } else if (cur) {
                    cur++;
                }
            }
            cout << max(cur, longest) + 1 << endl;
        }
		}
	return 0;
}
