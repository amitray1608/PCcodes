#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
void solve(){
	
	int n;
	cin >> n;
	int i, a[n];
	for( i=0;i<n;i++)
		cin >> a[i];
		
		bool flag = true;
	for(int i = n-2; i>=0; i--)
	{
		if(a[i]>a[i+1])
		{
			a[i]--;
			if(a[i]>a[i+1])
			{
				cout << "No";
				flag = false;
			}
		}
	}
	if(flag)
	cout<<"Yes";
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
