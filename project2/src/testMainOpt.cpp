#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <set>

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

	//cout << num << endl;
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

	int count = 100000;
	while(count > 0){
	    const int n = (rand()%(20-3+1)) + 3; // n in range [3:20]
	    const int x = rand() %((1<<n)-1);
		const int y = rand() %((1<<n)-1);
	
		//xStr = bitset<n> (x).to_string();
		//yStr = bitset<n> (y).to_string();
		string xStr = decToBin(x, n);
		string yStr = decToBin(y, n);
	
		#ifdef PRINT
		cout << "binstring (n,x): " << xStr << endl;
		cout << "binstring (n,y): " << yStr << endl;
		#endif
		char* xChar = new char[n+1];
		char* yChar = new char[n+1];
	
		strcpy(xChar, xStr.c_str());
		strcpy(yChar, yStr.c_str());
	
		int** dp = new int*[n+1];
		set<string>** setStr = new set<string>*[n+1];
		for(int i=0; i<n+1; i++){
			dp[i] = new int[n+1];
		    setStr[i] = new set<string>[n+1];
		}

	
		int lcsLen = LCS_YK(n, dp, xChar, yChar);	
		#ifdef PRINT
		cout << "LCS string length: " << lcsLen << endl;
		#endif
	
		set<string> res_YK;
		string stack;
		findAllLCS(n, n, dp, lcsLen, xChar, yChar, res_YK, stack);
		
		#ifdef PRINT
		for(set<string>::iterator iter = res_YK.begin(); iter != res_YK.end(); iter++){
			cout<<"Longest string: "<< *iter <<endl;
		}
		#endif
		
		strcpy(xChar, xStr.c_str());  
		strcpy(yChar, yStr.c_str());

		#ifdef PRINT
		cout<<"Begin WL LCS"<<endl;
		#endif

		// LCS(n, xChar, yChar);	
		int lcsLenOpt = LCS_OPT(n, dp, xChar, yChar, setStr);	

		//set<string> res_WL;
		//res_WL = getLCS(xStr, yStr, n, n);
		
		if(setStr[n][n].size()!= res_YK.size()){
			cout<<"Answer mismatch!!!"<<" length:"<<dp[n][n]<<endl;
			return -1;
		}
		set<string>::iterator iter;
		for(iter = setStr[n][n].begin(); iter != setStr[n][n].end(); iter++){
			if(res_YK.find(*iter) == res_YK.end()){
				cout<<"Answer mismatch!!!"<<" length:"<<dp[n][n]<<endl;
				return -1;
			}
		}

		delete [] xChar;
		delete [] yChar;
		for(int i=0; i<n+1; i++){
			delete [] dp[i];
			delete [] setStr[i];
		}
		delete [] dp;
		delete [] setStr;
		
		count--;
		cout<<"Finish test "<<count<< " length: "<<n<<endl;
	}
	cout<<"Pass test!\n";
	return 0;
}
