#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz size()
#define bg begin()
#define en end()
#define m9 1000000007
#define vii vector <int>
#define vli vector <long long int>
#define pii pair <int,int>
#define pli pair <long long int, long long int>

bool sortcol( const vector<li>& v1, 
               const vector<li>& v2 ) { 
 return v1[0] > v2[0]; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    li t;
    cin >> t;
    while(t--){
        li A,B,n;
        cin >> A >> B >> n;
        li a[n],c[n];
        vector<vli> b;
        li fl=0,a0,a1;
        for(li i=0;i<n;i++){
            cin >> a[i];
        }
        for(li i=0;i<n;i++){
            vli v;
            cin >> a0;
            a1=i;
            v.pb(a0);   v.pb(a1);
            b.pb(v);
        }
        sort(b.bg,b.en,sortcol);
        li sum=0;
        for(li i=0;i<n;i++){
          cout << b[i][0] << ' ';
            c[i]=b[i][0]/A;
            if(b[i][0]%A)  c[i]++;
            sum+=(c[i]-1)*a[b[i][1]];
            if(sum>=B)  fl=1;
            sum+=a[b[i][1]];
        }
        cout << endl;
        if(!fl){
            cout << "YES\n";
        }
        else    cout << "NO\n";
    }
}
