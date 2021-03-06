#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <cctype>
#include <math.h>

using namespace std;


// WL's function header
void LCS(int, char*, char*);
set<string> getLCS(string, string, int, int);

// YK's function header
int LCS_YK(int, int**, char*, char*);
void findAllLCS(int, int, int**, const int&, char*, char*, set <string> &, string&);

// Opt's function header
int LCS_OPT(int , int** , char* , char* , set<string>**);

string decToBin(int num, int n) {
	char numBin[n];

	int i = n-1;
	while (i>=0) {
		if (num % 2 == 1)
			numBin[i] = '1';
		else
			numBin[i] = '0';
		num = num/2;
		i--;
	}

	string numBinStr(numBin, n);
	return numBinStr;
}

bool valueCheck(string str, bool isN, int n) {
    if(str.length()==0){
        return false;
    }

	int i;
	string numStr = "1234567890";
	for (i=0; i<str.size(); i++) {
		if (numStr.find(str[i]) == string::npos) 
			return false;
	}

	int maxStrLen;
	if(isN){
		maxStrLen = 2;
	} else{
		maxStrLen = to_string((1 << n)-1).length();
	}
	if(str.length() > maxStrLen){
		return false;
	}

	int val = stoi(str);
	if (isN && (val < 3 || val > 20)) 
		return false;
	else if (!isN && (val < 0 || val >= (1<<n)))
		return false;
	else
		return true;
}

inline string trim(const string &s)
{
	auto wsfront=find_if_not(s.begin(),s.end(),[](int c) {return isspace(c);});
	auto wsback=find_if_not(s.rbegin(),s.rend(),[](int c) {return isspace(c);}).base();
	return (wsback<=wsfront ? string() : string(wsfront,wsback));
}

int main(){
	string n, x, y;

	while(1){
		cout << "Please give an input. Use Ctrl+C to terminate the program."<<endl;
		while(1){
			cout << "Please input n, the length of binstring, which is in the range [3:20]: " << endl;
			getline(cin, n);
			n = trim(n);
			if (!valueCheck(n, true, 0)) {
				cout << "The integer n you input is not available. Please retype input in correct format." << endl;
			} else{
				break;
			}
		}
		
		int nInt = stoi(n);
		
		while(1){
			cout << "Please input an integer x, which is in the range [0:2^n-1]: " << endl;
			getline(cin, x);
			x = trim(x);
			if (!valueCheck(x, false, nInt)) {
				cout << "The integer x you input is not available. Please retype input in correct format." << endl;
			} else{
				break;
			}
		}

		while(1){
			cout << "Please input another integer y, which is in the range [0:2^n-1]: " << endl;
			getline(cin, y);
			y = trim(y);
			if (!valueCheck(y, false, nInt)) {
				cout << "The integer y you input is not available. Please retype input in correct format." << endl;
			} else{
				break;
			}
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

		/* Comment out WL's algo
		LCS(nInt, xChar, yChar);	

		set<string> res;
		res = getLCS(xBinStr, yBinStr, nInt, nInt);
		*/

		int** dp = new int*[nInt+1];
		set<string>** setStr = new set<string>*[nInt+1];
		for(int i=0; i<nInt+1; i++){
			dp[i] = new int[nInt+1];
		    setStr[i] = new set<string>[nInt+1];
		}
		//int lcsLen = LCS_YK(nInt, dp, xChar, yChar);
		//set<string> res;
		//string stack;
		//findAllLCS(nInt, nInt, dp, lcsLen, xChar, yChar, res, stack);

		int lcsLenOpt = LCS_OPT(nInt, dp, xChar, yChar, setStr);
		set<string> res = setStr[nInt][nInt];


		// display
        cout << endl;
		cout << "The input parameters (n, x, y): " << "(" << nInt << ", " << xInt << ", " << yInt << ")" << endl;
		cout << "binstring(n, x): " << xBinStr << endl;
		cout << "binstring(n, y): " << yBinStr << endl;
        cout << "The length of LCS: "<< dp[nInt][nInt] << endl;
		cout << "The determined number of distinct LCS's: " << res.size() << endl;
		cout << "The list of those LCS's: " << endl;
		for (set<string>::iterator it=res.begin(); it!=res.end(); ++it) {
			cout << *it << endl;
		}
        cout<<"----------------------------------------------------";
        cout<<endl<<endl;

		for(int i=0; i<nInt+1; i++){
			delete [] dp[i];
		}
		delete [] dp;

	}
}

