
#include <bits/stdc++.h>

using namespace std;


void solve() {
  int row = 7, col = 5;
  vector<vector<int>> seats;
  seats.resize(row, vector<int>(col, 1));

  auto options = []() {
    cout << "Choose options:" << endl;
    cout << "1. Seat allocation " << endl;
    cout << "2. Exit. " << endl;
    int x;
    cin >> x;
    return x;
  };

auto viewSeats = [&]() {
  for (int i = 0; i < row; i++) {
    cout << i + 1 << ' ';
    for (int j = 0; j < col; j++) {
      if (seats[i][j]) {
          cout << (char) (j + 'A') << ' ';
        } else {
          cout << "X ";
        }
      }
      cout << endl;
    }
  };

  auto seatAllocator = [&]() {
    viewSeats();
    cout << "Choose the Seat by pressing row number and column character" << endl;
    string s;
    cin >> s;
    int r = s[0] - '0';
    int c = s[1] - 'A';
    seats[r - 1][c] = 0;
    cout << "Congratulations seat booked." << endl;
  };

  while (true) {
    int op = options();
    if (op == 1) {
      seatAllocator();
    } else {
      cout << "Thank you for choosing our service." << endl;
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


