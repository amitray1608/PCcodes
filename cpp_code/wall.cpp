#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);

const int mod=1e9+7;

int n,k;
int dp[101][101][101];
vector<int> a(1001);

int f(int i,int j,int cnt){
    // Base Case
    if(i==n){
        if(cnt<=k){
            return 0;
        }
        else{
            return (int)1e12;
        }
    }
    int &res=dp[i][j][cnt];
    if(res!=-1){
        return res;
    }
    res=1e12;
    if(i==0){
        res=f(i+1,i,cnt);
        if(1){
            res=min(res,(a[i]!=a[i+1])+f(i+1,i+1,cnt));
        }
    }
    else{
       // int t=0;
        res=f(i+1,i,cnt+(a[i]!=a[j]));
        if(a[j]!=a[i]){
            if(1)
                res=min(res,1+f(i+1,j,cnt));
        }
        if(i<n-1)
            res=min(res,f(i+1,i+1,cnt+(a[i+1]!=a[j]))+(a[i]!=a[i+1]));
    }
    if(res>=(int)1e12)res=1e12;
    return res;
}


signed main()
{
    
    fast;
    
    int t;
    scanf("%lld",&t);
    int z=1;
    while(t--){
        int cnt=0;
        scanf("%lld%lld",&n,&k);
        a.clear();
        printf("Case #%lld: ",z++);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            if(i){
                cnt+=(a[i]!=a[i-1]);
            }
        }
        if(cnt<=k){
            printf("0\n");
            continue;
        }
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,0);
        memset(dp,-1,sizeof(dp));
        reverse(a.begin(),a.begin()+n);
        ans=min(ans,f(0,0,0));
        printf("%lld\n",ans);
    }
    
    
    return 0;
}
