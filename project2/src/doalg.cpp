#include <iostream>
#include <set>

using namespace std;

int max(int a, int b) {
	return (a > b)? a : b;
}

int LCS(int n, int** dp, char* x, char* y) {
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

	for (i=0; i<=n; i++) {
		for (j=0; j<=n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	cout << dp[n][n] << endl;
	return dp[n][n];
}

void findAllLCS(int posX, int posY, int** dp, const int& maxLCSLen , char* x, char* y, set <string> & res, string& stack) {
	if(posX == 0 || posY == 0){
		if(stack.length() == maxLCSLen){
			res.insert(stack);
		}
		return;
	}

	if(min(posX, posY) + dp[posX][posY] + stack.length() < maxLCSLen){
		return;
	}

	if (x[posX-1] == y[posY-1]){
		stack.insert(0, 1, x[posX-1]);
		findAllLCS(posX-1, posY-1, dp, maxLCSLen, x, y, res, stack);
		stack.erase(0, 1);
	}
	else {
		int maxMatch = max(dp[posX-1][posY], dp[posX][posY-1]);
		if(dp[posX-1][posY] == maxMatch){
			findAllLCS(posX-1, posY, dp, maxLCSLen, x, y, res, stack);
		}
		if(dp[posX][posY-1] == maxMatch){
			findAllLCS(posX, posY-1, dp, maxLCSLen, x, y, res, stack);
		}
	}
	return;
}
