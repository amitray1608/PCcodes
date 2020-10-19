#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	int cnt=0;
	
	for(int i=25;i>=0;--i){
		char c='a'+i;
		
		for(int j=0;j<s.length();++j){
			cout<<c<<" "<<c-1<<" "<<s[j]<<" "<<s<<'\n';
			if(s[j]==c && (j>0&&s[j-1]==c-1)||(j<s.length()-1&&s[j+1]==c-1)){
				//cout<<j<<" "<<s<<' ';
				s.erase(s.begin()+j);
				//cout<<s<<'\n';
				cnt++;
				i=26;
				break;
			}
		}
		
	}
	
	cout<<cnt;
	
}
