#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isMonotonic(vector<int>& A){
	//解法一：
	//int n = A.size();
	//if(n == 1)
	//	return true;
	//bool flag1 = true, flag2 = true;//flag1 递增，flag2 递减
	//for(int i = 0; i < n - 1; ++i){
	//	if(A[i] < A[i+1])
	//		flag2 = false;
	//	if(A[i] > A[i+1])
	//		flag1 = false;
	//}
	//return flag1 || flag2;
	//解法二：
	return is_sorted(A.begin(),A.end()) || is_sorted(A.rbegin(),A.rend());
}
int main(){
	vector<int> A;
	int v;
	while(cin >> v){
		A.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	bool res = isMonotonic(A);
	cout << res << endl;
	system("pause");
	return 0;
}