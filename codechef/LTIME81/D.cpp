#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

bool isPalindrome(string s){
	
	ll i=0;
	ll j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j]) return false;
		i++;
		j--;
	}
	return true;
}

int main()
{
    SPEED;
    ll t;
    cin>>t;
    while(t--){
       ll n;
       cin>>n;
       string s;
       cin>>s;
       unordered_map<char,int>um;
       for(ll i=0;i<s.size();i++){
       	um[s[i]]++;
       }
       int odds=0;
       for(auto it:um){
       	if(it.second&1) odds++;
       }
       
       if(odds>1){
       	cout<<"NO\n";
       }else{
       	
       	int ans=0;
       	ll j=s.size()-1;
       	ll i=0;
       	int f=1;
       	int mid=n/2;
       	while(i<j){
       		//cout<<s[i]<<" "<<s[j]<<"\n";
       		if(s[i]==s[j]){
       			i++;
       			j--;
       		}else{
       			
    			if((i+1<j&&j-1>i)&&((s[i+1]==s[j]&&s[i]==s[j-1])||(s[i+1]==s[j]&&((i+1)==mid)))){
    				swap(s[i],s[i+1]);
    				i+=2;
    				j-=2;
    				ans++;
    			}else{
    				f=0;
    				break;
    			}
       		}
       		
       		if(f==0) break;
       		
       	}
       	
       	if(f==0) cout<<"NO\n";
       	else {
       		if(isPalindrome(s)){
       			cout<<"YES\n";
       			cout<<ans<<"\n";
       		}else cout<<"NO\n";
       		
       	}
       }
    }
    return 0;
}
