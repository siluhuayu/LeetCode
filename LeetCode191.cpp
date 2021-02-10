#include<iostream>
#include<stdint.h>
#include<string>
using namespace std;
int hammingWeight(uint32_t n){
	int count = 0;
	while(n){
		if(n & 1)
			count++;
		n >>= 1;
	}
	return count;
}
//main is wrong,but the hammingWeight function can pass on LeetCode,and even I copy the test code on LeetCode,the code can't run well
int main(){
	//string line;
 //   while(getline(cin, line)) {
 //       int n = stoi(line);   
 //       int ret = hammingWeight(n);
 //       string out = to_string(ret);
 //       cout << out << endl;
 //   }
	uint32_t n;
	cin >> n;
	int count = hammingWeight(n);
	cout << count << endl;
	system("pause");
	return 0;
}