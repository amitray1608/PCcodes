#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll  n;
	cin >> n;
	ll i, count=0, a[n], x[n];
	for(i=0; i<n; i++)
		cin >> a[i], x[i]=a[i];
		
	sort(a,a+n);
	
	for(i=0; i<n; i++)
	{
		if(a[i] != x[i])
		count++;
		if(count > 2)
		break;
	}
	(count==2 || count==0) ? cout << "YES" : cout << "NO";

}

int main(){
	solve();
}
