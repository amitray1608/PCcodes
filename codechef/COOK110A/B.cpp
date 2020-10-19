#include <bits/stdc++.h>
using namespace std;
int fix(int X, int limit) {
	if (X <= limit) return X;
	if ((X - limit)%2 == 0) return limit;
	return limit - 1;
}
int main() {
	int t; cin >> t;
	while(t--) {
	    int A, B, C;
	    cin >> A >> B >> C;
	    A = fix(A,7), B = fix(B, 4), C = fix(C,4);
	    int sum = A + B + C;
	    bool ok = false;
	    for(int mask = 0; mask < (1 << sum); mask++) {
	        int total = 0;

	        for(int j = 0; j < sum; j++) {
	            int mult = 1;
	            if (mask & (1 << j)) mult = -1;

	            if (j < A) total += mult * 1;
	            else if (j < A+B) total += mult * 2;
	            else total += mult * 3;
	        }

	        if (total == 0) {
	            ok = true;
	            break;
	        }
	    }

	    if (ok) cout << "YES\n";
	    else cout << "NO\n";
	}

	return 0;
}
