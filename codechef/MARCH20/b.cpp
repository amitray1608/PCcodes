#define maxm 100005
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t,n,q,p,cnt,val,even,odd,flag;
	int bits[maxm];
	for(int i=0;i<maxm;i++){
		cnt=0;
		val= i;
		while(val){
			if(val&1) cnt++;
			val=val>>1;
		}
		bits[i] = cnt;
	}
	cin >> t;
	while(t--){
		cin >> n >> q;
		cnt=0;
		even = 0; odd = 0;
		for(int i=0;i<n;i++){
			cin >> val;
			if(val<maxm){
				if(bits[val]&1) odd++;
				else even++;
			}
			else{
				cnt=0;
				while(val){
					if(val&1) cnt++;
					val=val>>1;
				}
				if(cnt&1) odd++;
				else even++;
			}
		}
		while(q--){
			cin >> p;
		//	cout<<"error "<<p<<endl;
			if(bits[p]&1)
				printf("%d %d\n",odd,even);
			else
				printf("%d %d\n",even,odd);
		}
	}
	return 0;
}
