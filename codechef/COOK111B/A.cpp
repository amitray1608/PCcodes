//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
		int n;
		cin >> n;
		int arr[n], copy[n];
		for(int i=0; i<n;i++){
			cin >> arr[i];
			copy[i] = arr[i];
		}
		sort(copy, copy+n);
		int x = copy[0], y = copy[n-1];
		int X, Y;
		for(int i=0; i<n; i++){
			if(arr[i] == x)
			X = i;
			if(arr[i] == y)
			Y = i;
		}
		if(X > Y)
		    cout << y << " " << x << endl;
		else
		    cout << x << " " << y << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
