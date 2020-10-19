//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	int n, tmp, cnt=0;
	cin >> n;
	//map <int,int> check;
	//map <int,int> check2;
	vector <int> a(n);
	//vector <pair<int, int>> b(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    reverse(a.begin(), a.end());
    
    for(int i=0; i<n; i++) {
        	cin >> tmp;
    	if(tmp != a.back()) {
    		cnt++;
    		auto pos = binary_search(a.begin(),a.end(),tmp);
    		a.erase(a.begin()+pos , a.begin()+pos + 1);
    	}
    	else
             a.pop_back();
    }
    cout << cnt;
		
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
