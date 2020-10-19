#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;
vector <int> A(100000);
vector <int> tree(2000000); 

void build(int node, int start, int end)
{
		if(start == end)
			tree[node] = A[start];
		
}

void solve()
{
	int n;
	cin >> n;
	int q;
	cin >> q;
	for(int i = 1; i<=n; i++ )
		cin >> A[i];
		
	build(1, 1, n);

	while(q--)
	{
		char typo;
		cin >> typo;
		int l, r;
		cin >> l >> r;
		if(typo == 'q')
			cout << query(1, 1, n, l, r) << endl;
		else
			update(1, 1, n, l, r);
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
	
