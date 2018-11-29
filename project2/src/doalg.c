#include <iostream>
#include <vector>
#include <set>

using namespace std;

int max(int a, int b) {
	return (a > b)? a : b;
}

void LCS(int n, char* x, char* y, int dp[][]) {
	int i, j;

	for (i=0; i<=n; i++)
		dp[i][0] = 0;

	for (j=0; j<=n; j++)
		dp[0][j] = 0;

	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++) {
			if (x[i-1] == y[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << dp[n][n] << endl;
}

set<string> findLCS(string x, string y, int m, int n, int dp[][]) {
	set<string> s;

	if (m == 0 || n == 0) {
		s.insert("");
		return s;
	}
	
	if (x[m-1] == y[n-1]) {
		set<string> tmp = findLCS(x, y, m-1, n-1, dp[][n]);
		
		for (string str : tmp)
			s.insert(str+x[m-1]);
	} else {
		if (dp[m-1][n] >= dp[m][n-1]) 
			s = findLCS(x, y, m-1, n);

		if (dp[m][n-1] >= dp[m-1][n]) {
			set<string> tmp = findLCS(x, y, m, n-1, dp[size][size]);
			s.insert(tmp.begin(), tmp.end());
		}
	}
	return s;
}

