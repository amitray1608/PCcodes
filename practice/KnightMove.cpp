#include<bits/stdc++.h>
using namespace std;
const int N = 8;

int dx[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[N] = {1, 2, 2, 1, -1, -2, -2, -1};

//int dx[N] = {-2, -2, -1, 1, 2, 2, 1, -1};
//int dy[N] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool isSafe(int x, int y, int sol[N][N]) {
  return (x >= 0 and x < N and y >= 0 and y < N and sol[x][y] == -1);
}

int recc(int x, int y, int movei, int sol[N][N]) {
  if(movei == N*N) {
    return 1;
  }
  int nextX, nextY;
  for(int i = 0; i < N; i++) {
    nextX = x + dx[i];
    nextY = y + dy[i];
    if(isSafe(nextX, nextY, sol)) {
      sol[nextX][nextY] = movei;
      if(recc(nextX, nextY, movei+1, sol)) 
        return 1;
      else
        sol[nextX][nextY] = -1;
    }
  }
  return 0;
}

void solve() {
  int sol[N][N];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++)
      sol[i][j] = -1;
  }
  sol[5][0] = 0;
  if(!recc(5, 0, 1, sol)) {
    cout << "No solution exist." << endl;
  } else {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++)
        cout << setw(2) <<  sol[i][j] << ' ';
      cout << endl;
    }
  }
}

int main() {
  solve();
  return 0;
}
