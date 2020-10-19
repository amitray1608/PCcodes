#include <bits/stdc++.h> 
#define ll long long
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define F first
#define S second
#define mp make_pair
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define pq priority_queue
#define M map
#define UM unordered_map
#define graph unordered_map<int,vector<int>>
#define graphw unordered_map<int,vector<pair<int,int>>>
#define V vector
#define mod 1000000007
#define inf 3000000000000000007ll
#define P pair
#define Fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) signed(a.size())
#define FIXED cout << fixed << setprecision(12)
#define L list
#define D deque
#define ld long double
using namespace std;
// pair operation
/*
template<class T, class U>istream& operator>>(istream& in, pair<T,U> &rhs){in >> rhs.first;in >> rhs.second;return in;}
template<class T, class U>ostream& operator<<(ostream& out,const pair<T,U> &rhs){out << rhs.first;out << " ";out << rhs.second;return out;}
template<class T, class U>pair<T,U> operator+(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first+b.first,a.second+b.second);}
template<class T, class U>pair<T,U> operator-(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first-b.first,a.second-b.second);}
// Linear STL
// VECTOR
template<class T>istream& operator>>(istream& in, vector<T> &a){for(auto &i: a)cin >> i;return in;}
template<class T>ostream& operator<<(ostream& out, const vector<T> &a){for(auto &i: a)cout << i << " ";return out;}
// SET
template<class T>ostream& operator<<(ostream& out, const set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const unordered_set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const multiset<T> &a){for(auto &i: a)cout << i << " ";return out;}
// MAP
template<class T,class U>ostream& operator<<(ostream& out, const map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << "(\n";return out;}
template<class T,class U>ostream& operator<<(ostream& out, const unordered_map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << "(\n";return out;}
*/
int main() {
    Fast;
    int t=1;
    // cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int a[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        int dp[m][n]={};
        dp[0][0]=a[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]&a[i][0];
        }
        for(int i=1;i<n;i++){
            dp[0][i]=dp[0][i-1]&a[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=max(dp[i-1][j]&a[i][j],dp[i][j-1]&dp[i-1][j]);
            }
        }
        cout<<dp[m-1][n-1];
    }
}
