 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
void solve()
{
  int a,b;
	cin >>a >> b;
  int count =1;
  int t = a;
  while(t<=b){
    ++count;
    --t;
    t += a;
  }
  cout << count;
  
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
	//	cin >> t
		while(t--)
		{
			solve();
		}
	return 0;
}
