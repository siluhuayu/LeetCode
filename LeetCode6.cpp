#include<iostream>
#include<string>
#define N 1000
using namespace std;
string convert(string s, int numRows){
	string zs = "";
	int len = s.length();
	char z[N][N]={};
	int m = 0, n = 0;
	if(numRows == 1)
		zs = s;
	else{
		for(int i = 0; i < len; i++)
		{
			if(m < numRows && ( n == 0 || (n % (numRows - 1)) == 0 )){	
				z[m][n] = s[i];
				m++;
			}
			else{
				if(m == numRows){
					m--;
					n++;
				}
				m--;		
				z[m][n] = s[i];
				n++;
				if(numRows == 2)
					n--;					
				if((n % (numRows - 1)) == 0)
					m = 0;
				if(numRows == 2)
					m++;
			}
		}	
		for(int i = 0; i < numRows; i++)
			for(int j = 0; j <= n; j++)
				if(isalpha(z[i][j]) || z[i][j] == ',' || z[i][j] == '.')
					zs += z[i][j] ;
	}	
	return zs;
}
int main(){
	string s,rs;
	cin >> s;
	int numRows;
	cin >> numRows;
	rs = convert(s,numRows);
	cout << rs << endl;
	system("pause");
	return 0;
}
