#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
void solve(){
	
	int n; 
	cin>>n;
	int i, count = 0;
 
	for( i = 1; i<=n; i++){
		string x = to_string(i);
		if(x.size()&1) 
			count++;
 
	}
 
	cout << count << endl;
}
 
int main()
{
	
	    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		int t =1;
			//cin >> t;
		while(t--)
		{
			solve();
		}
		return 0;
}
