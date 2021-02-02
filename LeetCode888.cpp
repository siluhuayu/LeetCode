#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
//³¬Ê±
//vector<int> fairCandySwap(vector<int>& A, vector<int>& B){
//	int lena = A.size(),lenb = B.size();
//	vector<int> ans;
//	int i,j;
//	int suma = accumulate(A.begin(),A.end(),0);
//	int sumb = accumulate(B.begin(),B.end(),0);
//	for(i = 0; i < lena; ++i){
//		for(j = 0; j < lenb; ++j)
//		{
//			if(suma-A[i]+B[j] == sumb-B[j]+A[i]){
//				ans.push_back(A[i]);
//				ans.push_back(B[j]);
//				break;
//			}
//		}
//		if(ans.size())
//			break;
//	}
//	return ans;
//}
vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int lena = A.size(),lenb = B.size();
    vector<int> ans;    
    int suma = accumulate(A.begin(),A.end(),0);
	int sumb = accumulate(B.begin(),B.end(),0);
    int minus = (suma - sumb) >> 1;
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int la = 0,lb = 0;
	while(la < lena && lb < lenb){
		int temp = A[la] - B[lb];
		if(temp == minus)
		{
			ans.push_back(A[la]);
			ans.push_back(B[lb]);
			break;
		}
		else if(temp < minus)
			la++;
		else
			lb++;
	}
	return ans;
}
int main(){
	vector<int> A,B;
	int v;
	while(cin >> v)
	{
		A.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	while(cin >> v)
	{
		B.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	vector<int> ans = fairCandySwap(A,B);
	for(int i = 0; i < 2; ++i)
		cout << ans[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}