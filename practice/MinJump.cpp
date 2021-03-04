1 3 5 8 9 2 6 8 9

min(a[i], n);

int dp[n] = inf;


dp[0] = 1;
for (int i = 0; i < n; i++) {
  int maxi = min(i + a[0], n - 1);
  for (int j = 1; j <= maxi; j++) {
    int newpos = i + j;
    dp[newpos] = min(dp[newpos], dp[i] + 1);
  }
}

int d[n] = -1;

int recc(int i) {
  if (i == n - 1) {
    return 0;
  }
  if (dp[i] != -1) return dp[i];
  for (int j = 1; j <= min(i + a[0], n - 1); j++) {
    dp[
  }
}

recc(0);
