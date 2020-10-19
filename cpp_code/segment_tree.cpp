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
		if(start ==  end)
		{
			tree[node] = A[start];
		}
		else
		{
			int mid = (start + end)/2;
			build(2*node, start, mid);
			build(2*node+1, mid+1, end);
			
			tree[node] =  min(tree[2*node], tree[2*node+1]);
		}
}

void update(int node, int start, int end, int idx, int val)
{
		if(start == end){
			A[idx] = val;
			tree[node]=val;
		}
		else{
			int mid = (start + end) / 2;
			if(start <= idx and idx <= mid){
					update(2*node, start, mid, idx, val);
			}
			else{
				update(2*node+1, mid+1, end, idx, val);
			}
				
			tree[node] =  min(tree[2*node], tree[2*node+1]);
		}
}

int query(int node, int start, int end, int l, int r)
{
	if(r < start or end < l){
		return 100005;
	}
	
	if(l <= start and end <= r)
		return tree[node];
		
	int mid = (start + end) / 2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	
		return min(p1, p2);
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
	
