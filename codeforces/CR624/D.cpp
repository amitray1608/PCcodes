//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
//#define deb(x) cout << #x << " = " << x << endl;
//int binarys(int l, int r, int flag){
	//int count = 0, curr = r;
	//while(l < r){
		//int mid = (r+l)/2;
		//if(r%mid == 0){
			//if(r-mid < count)
			//return mid;
		//}else if(){
		
		//}
	//}
	//return count;
//}
int solve2(int a, int b, int c){
	int count = 0;
	count += b%a;
	b -= (b%a);
	count += c%b;
	return count;
}
void solve(){
	int a,b,c,ans,ansa,ansb,ansc,tmp;
       cin >> a >> b >> c;
        ans = 0x3f3f3f3f;
        for(int i=1;i<=10000;i++)
            for(int j=i;j<=10000+i;j+=i)
                for(int k=j;k<=10000+j;k+=j)
                {
                    tmp=abs(a-i)+abs(b-j)+abs(c-k);
                    if(tmp<ans)
                    {
                        ans=tmp;
                        ansa=i;
                        ansb=j;
                        ansc=k;
                    }
                }
        cout << ans << endl;
        cout << ansa << " " << ansb << " " << ansc << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
