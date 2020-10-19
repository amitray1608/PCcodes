#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	cout << fixed << setprecision(6);
        int n;
        cin >> n;
        vector<double> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        double ans=(a[0]+a[1])/2;
        for(int i=2; i<n; i++){
            ans=(ans+a[i])/2;
        }
        cout << ans << endl;;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
