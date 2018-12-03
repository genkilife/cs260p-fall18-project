#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>
#include <string>

using namespace std;

int main(){
    const int n = 12; // n in range [3:20]
    const int x = 1025;
	const int y = 4923;

	string xStr = bitset<n> (x).to_string();
	string yStr = bitset<n> (y).to_string();

	cout << "binstring (n,x): " << xStr << endl;
	cout << "binstring (n,y): " << yStr << endl;

	char* xChar = new char[n];
	char* yChar = new char[n];

	strcpy(xChar, xStr.c_str());
	strcpy(yChar, yStr.c_str());

	int** dp = new int*[n+1];
	for(int i=0; i<n+1; i++){
		dp[i] = new int[n+1];
	}

	int lcsLen = LCS_YK(n, dp, xChar, yChar);	
	cout << "LCS string length: " << lcsLen << endl;

	set<string> res;
	string stack;
	findAllLCS(n, n, dp, lcsLen, xChar, yChar, res, stack);

	for(set<string>::iterator iter = res.begin(); iter != res.end(); iter++){
		cout<<"Longest string: "<< *iter <<endl;
	}

	delete [] xChar;
	delete [] yChar;
	for(int i=0; i<n+1; i++){
		delete [] dp[i];
	}
	delete [] dp;
	return 0;
}
