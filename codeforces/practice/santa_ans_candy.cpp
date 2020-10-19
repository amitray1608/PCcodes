#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>arr, ans;
void partitions(int target, int curr, int idx)
{
    if (curr + arr[idx] == target && arr.size() > ans.size())
    {      
		ans.resize(arr.size());
        ans = arr;
    }
    else if (curr + arr[idx] > target)
    {
        return;
    }
    else
    {
        for(int i = arr[idx]+1; i < target; i++)
        {
            arr[idx+1] = i;
            partitions(target, curr + arr[idx], idx+1);
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	arr.resize(n);
	ans.resize(n);
	for(int i = 1; i<n; i++)
	{
		arr[0] = i;
		partitions(n, 0, 0);
	}
	
	cout << ans.size() << endl;
	
	for(int i : ans)
		cout <<  i << " ";
return 0;
}
