
#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s[n];
        map<string, vector<char>> mp;
        for(int i=0;i<n;i++){
            cin>>s[i];
            string temp;
            temp = s[i].substr(1);
            mp[temp].push_back(s[i][0]);
        }
        int ans=0;
        auto it=mp.begin();
        while(it!=mp.end()){
            auto itr=it;
            itr++;
            while(itr!=mp.end()){
                set<char> st;
                for(auto it1 : it->second){
                    st.insert(it1);
                }
                
                for(auto it1 : itr->second){
                    int n=st.size();
                    st.insert(it1);
                    // cout<<it1<<" "<<st.size()<<endl;
                    if(st.size()>n){
                        ans+=(2*n);
                        st.erase(it1);
                    }
                    else{
                        st.erase(it1);
                    }
                    // cout<<it1<<" "<<st.size()<<endl;
                }
                itr++;
            }
            it++;
        }       
        cout<<ans<<endl;
    }
}


