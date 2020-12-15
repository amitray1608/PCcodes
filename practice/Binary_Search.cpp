#include<bits/stdc++.h>

using namespace std;

int n, x;
vector<int> a;

int BinarySearch(int l, int r) {
  if(l > r) return -1;
  int mid = (l + r) / 2;
  if(x == a[mid])
    return mid;
  if(x < a[mid])
    return BinarySearch(l, mid - 1);
  return BinarySearch(mid + 1, r);
}

int main() {
  cin >> n;
  a.resize(n);
  for(int &i : a) cin >> i;
  sort(a.begin(), a.end());
  cin >> x;
  int pos = BinarySearch(0, n - 1);
  if(pos == -1) 
    cout << "Not Present" << endl;
  else
    cout << "Present at " << pos << endl;
  return 0;
}






