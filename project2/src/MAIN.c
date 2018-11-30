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

bool valueCheck(string str, bool isN, int n) {
	int i;
	string numStr = "1234567890";
	for (i=0; i<str.size(); i++) {
		if (numStr.find(str[i]) == string::npos) 
			return false;
	}

	int val = stoi(str);
	if (isN && (val < 3 || val > 20)) 
		return false;
	else if (!isN && (val < 0 || val >= pow(2, n)))
		return false;
	else
		return true;
}

int main(){
	string n, x, y;
	cout << "Please input n, the length of binstring, which is in the range [3:20]: " << endl;
	cin >> n;
	cout << "Please input an integer x, which is in the range [0:2^n-1]: " << endl;
	cin >> x;
	cout << "Please input another integer y, which is in the range [0:2^n-1]: " << endl;
	cin >> y;
	
	if (!valueCheck(n, true, 0)) {
		cout << "The integer n you input is not available." << endl;
		return -1;
	}

	int nInt = stoi(n);
	if (!valueCheck(x, false, nInt)) {
		cout << "The integer x you input is not available." << endl;
		return -1;
	}
	if (!valueCheck(y, false, nInt)) {
		cout << "The integer y you input is not available." << endl;
		return -1;
	}

	int xInt = stoi(x);
	int yInt = stoi(y);
	string xBinStr, yBinStr;
	xBinStr = decToBin(xInt, nInt);
	yBinStr = decToBin(yInt, nInt);

	char xChar[nInt+1];
	char yChar[nInt+1];
	strcpy(xChar, xBinStr.c_str());  
	strcpy(yChar, yBinStr.c_str());

	LCS(nInt, xChar, yChar);	

	set<string> res;
	res = getLCS(xBinStr, yBinStr, nInt, nInt);

	// display
	cout << "The input parameters (n, x, y): " << "(" << nInt << ", " << xInt << ", " << yInt << ")" << endl;
	cout << "binstring(n, x): " << xBinStr << endl;
	cout << "binstring(n, y): " << yBinStr << endl;
	cout << "The determined number of distinct LCS's: " << res.size() << endl;
	cout << "The list of those LCS's: " << endl;
	for (set<string>::iterator it=res.begin(); it!=res.end(); ++it) {
		cout << *it << endl;
	}
}

