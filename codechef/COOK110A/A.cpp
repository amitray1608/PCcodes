#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;


void solve()
{
	stack<int>s;
	queue<int>q;
		for(int i = 1; i<6; i++)
		{
			s.push(i);
		}
		
		cout << "stack info \n";
		stack<int>ss = {s};
	while(!ss.empty())
	{
		cout << ss.top() << " ";
		ss.pop();
	}
	
		while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	
		
	while(!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	
	cout << "\nstack info ater using  Q\n";
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
			
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
