#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <math.h>
#include "doalg.c"

using namespace std;

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
