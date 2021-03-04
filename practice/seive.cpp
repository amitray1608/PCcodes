
vector<int>is_prime;
void seive(int n) {
  is_prime.assign(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
      if (is_prime[i]) {
          for (int j = i * i; j <= n; j += i)
              is_prime[j] = false;
      }
  }
}

vector<int> pre(n, 0);
for (int i = 2; i < n; i++) {
  if (is_prime[i]) {
    pre[i] += pre[i - 1] + 1;
  } else 
    pre[i] = pre[i - 1]; 
}

vector<array<int, 3>> v(n);
for (int i = 0; i < n; i++) {
  cin >> a[i][0] >> a[i][1] >> a[i][2];
}



