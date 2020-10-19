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
        int a[n+1];
        int ans[n+1]={0};
        bool vis[n+1]={false};
        for(int i=1;i<=n;i++) cin >> a[i];
        
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            int val=0;
            int pos=i;
            vector<int>tmp;
            while(true){
                vis[pos]=true;
                tmp.push_back(pos);
               pos=a[pos];
                val++;
                if(pos == i)
                    break;
            }
            for(int itr=0; itr < (int)tmp.size();itr++){
                ans[tmp[itr]]=val;
            }
        }
        for(int i=1; i<=n; i++){
            cout<<ans[i]<<" ";
        }
        cout << endl;

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
	
