#include <cstring>
#include <set>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define N 20

int dp[N+1][N+1];

void LCS(int n, char* x, char* y) {
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
				dp[i][j] = (dp[i-1][j] > dp[i][j-1])? dp[i-1][j] : dp[i][j-1];
		}
	}

	//cout << dp[n][n] << endl;
}


set<string> getLCS(string x, string y, int m, int n) {
	set<string> s;
					
	if (m == 0 || n == 0) {
		s.insert("");
		return s;
	}
													
	if (x[m-1] == y[n-1]) {
		set<string> tmp = getLCS(x, y, m-1, n-1);
																			
		for (set<string>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
			s.insert(*it+x[m-1]);
	} else {
		if (dp[m-1][n] >= dp[m][n-1]) 
			s = getLCS(x, y, m-1, n);
					
		if (dp[m][n-1] >= dp[m-1][n]) {
			set<string> tmp = getLCS(x, y, m, n-1);
			s.insert(tmp.begin(), tmp.end());
		}
	}
																										
	return s;
}

