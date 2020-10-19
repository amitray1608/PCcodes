//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	int N;
    cin >> N;
    set<pair<int, int>> angles;
    for (int i = 0; i < N; i++)
    {
        int K, B;
        cin >> K >> B;
        if (K != 0)
        {
            int g = __gcd(K, B);
            K /= g;
            B /= g;
            if (K < 0)
            {
                K = -K;
                B = -B;
            }
            angles.insert(make_pair(K, B));
        }
    }
    cout << angles.size() << '\n';
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
	
