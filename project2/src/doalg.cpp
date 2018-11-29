#include <iostream>

using namespace std;

int max(int a, int b) {
	return (a > b)? a : b;
}

string LCS(int n, char* x, char* y) {
	int dp[n+1][n+1];
	int i, j;
	string res = "";

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

	for (i=0; i<=n; i++) {
		for (j=0; j<=n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	cout << dp[n][n] << endl;
	return res;
}


