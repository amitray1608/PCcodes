
#include<bits/stdc++.h>

using namespace std;

int n, L;
int a[100002];
long long mini = 1e9 + 1;

bool check(long long x) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += ((long long)a[i] % x);
  }
  if (mini >= sum) {
    mini = sum;
    return true;
  }
  return false;
}

int main() {
  cin >> n >> L;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum < L) {
    cout << -1 << '\n';
    return 0;
  }
  sort(a, a + n);
  long long l = 0, r = 1e9 + 1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l << '\n';
  return 0;
} 

