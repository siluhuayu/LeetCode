#include<iostream>
#include<vector>
using namespace std;
int longestOnes(vector<int>& A, int K){
	int n = A.size();
	int left = 0, lsum = 0, rsum = 0;
    int length = 0;
    for (int right = 0; right < n; ++right) {
        rsum += 1 - A[right];//0的个数
		while (lsum < rsum - K) {
            lsum += 1 - A[left];
            ++left;//缩小窗口
		}
		length = max(length, right - left + 1);
    }
	return length;
}
int main(){
	vector<int> A;
	int v;
	while(cin >> v){
		A.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int K;
	cin >> K;
	int length = longestOnes(A,K);
	cout << length << endl;
	system("pause");
	return 0;
}
			


