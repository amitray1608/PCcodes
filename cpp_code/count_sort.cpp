#include<bits/stdc++.h>
using namespace std;

int main() { 

  //#ifndef ONLINE_JUDGE 
   //freopen("intput.txt", "r", stdin);
  //#endif
  int n;
  cin >> n;
  int a[n];
  for(int &i : a) cin >> i;
  int maxi = *max_element(a, a+n);
  int freq[maxi+1];
  memset(freq, 0, sizeof freq);
  for(int &i : a)
    freq[i]++;
  for(int i = 1; i <= maxi; i++)
    freq[i] += freq[i-1];
  int i = n-1;
  int sorted[n];
  for(int &i : freq)
    cout << i << ' ';
  cout << endl;
  while(i >= 0) {
    sorted[freq[a[i]]-1] = a[i];
    freq[a[i]]--;
    i--;
  }
  for(int &i : sorted)
    cout << i << ' ';
  cout << endl;
}
