#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <math.h>

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

string decToBin(int num, int n) {
	char numBin[n];

	cout << num;
	int i = n-1;
	while (i>=0) {
		if (num % 2 == 1)
			numBin[i] = '1';
		else
			numBin[i] = '0';
		num = num/2;
		i--;
	}

	string numBinStr(numBin);
	return numBinStr;
}


int main(){
	int n, x, y;
	cout << "Please input n, the length of binstring, which is in the range [3:20]: " << endl;
	cin >> n;
	if (n < 3 || n > 20) {
		cout << "n is out of range." << endl;
		return 0;
	}

	cout << "Please input an integer x, which is in the range [0:2^n-1]: " << endl;
	cin >> x;
	if (x < 0 || x >= pow(2, n)) {
		cout << "x is out of range." << endl;
		return 0;	
	}

	cout << "Please input another integer y, which is in the range [0:2^n-1]: " << endl;
	cin >> y;
	if (y < 0 || y >= pow(2, n)) {
		cout << "y is out of range." << endl;
		return 0;
	}

	//string xStr = bitset<N> (x).to_string();
	//string yStr = bitset<N> (y).to_string();

	string xStr, yStr;
	xStr = decToBin(x, n);
	yStr = decToBin(y, n);

	char xChar[n+1];
	char yChar[n+1];
	
	strcpy(xChar, xStr.c_str());  
	strcpy(yChar, yStr.c_str());

	LCS(n, xChar, yChar);	

	set<string> res;
	res = getLCS(xStr, yStr, n, n);

	// display
	cout << "The input parameters (n, x, y): " << "(" << n << ", " << x << ", " << y << ")" << endl;
	cout << "binstring(n, x): " << xStr << endl;
	cout << "binstring(n, y): " << yStr << endl;
	cout << "The determined number of distinct LCS's: " << res.size() << endl;
	cout << "The list of those LCS's: " << endl;
	for (set<string>::iterator it=res.begin(); it!=res.end(); ++it) {
		cout << *it << endl;
	}

}
