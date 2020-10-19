//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

bool compare(vector<int> a, vector<int> b)
{
    if(a[0] != b[0]) 
        return a[0]<b[0];
    if(a[1] != b[1]) 
        return a[1]<b[1];
    return a[2]<b[2];
}
 

void solve()
{
    int n; 
        cin>>n;
    vector< vector<int> > a(n,vector <int> (4));
    for(int i=0;i<n;i++)
    { 
        cin >> a[i][0] >> a[i][1] >> a[i][2]; 
            a[i][3] = i+1; 
    }

    sort(a.begin(), a.end(), compare);
    for(int i=0; i<n; i+=2)
    cout << a[i][3] << " " << a[i+1][3] << "\n";
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
	
