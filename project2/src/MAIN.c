#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>
#include <string>
#include "doalg.c"

using namespace std;

int main(){
    const int n = 12; // n in range [3:20]
    const int x = 1025;
	const int y = 4923;

	string xStr = bitset<n> (x).to_string();
	string yStr = bitset<n> (y).to_string();

	cout << "binstring (n,x): " << xStr << endl;
	cout << "binstring (n,y): " << yStr << endl;

	char xChar[n];
	char yChar[n];

	strcpy(xChar, xStr.c_str());
	strcpy(yChar, yStr.c_str());

	string res = LCS(n, xChar, yChar);	
	cout << "LCS string: " << res << endl;
}
