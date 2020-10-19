#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
    unordered_map<char, ll> check;
	    string s,ss;
        cin >> s >> ss;
        if(s.size() != ss.size()){
            cout<<"NO\n";
            return;
        }
        for(auto itr : s){
            if(!check[itr])
                check[itr] = 1;
        }

        for(auto itr : ss){
            if(check[itr] == 1)
                check[itr] = 2;
        }

        bool flag = false;
        for(auto itr : check){
            if(itr.second == 2){
                cout<<"YES\n";
                flag = true;
                break;
            }
        }
        if(flag)
            return;
        else
            cout<<"NO\n";
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
