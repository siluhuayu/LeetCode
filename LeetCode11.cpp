#include<iostream>
#include<vector>
using namespace std;
//int maxArea(vector<int>& height){
//	int maxcontain = 0,contain = 0;
//	int len = height.size();
//	for(int i = 0; i < len; i++)
//		for(int j = i + 1; j < len; j++){
//			contain = (j-i) * min(height[i],height[j]);
//			if(contain >= maxcontain)
//				maxcontain = contain;
//		}
//	return maxcontain;
//}//暴力解法，超时
int maxArea(vector<int>& height){
	int maxcontain = 0,contain = 0;
	int i = 0, j = height.size() - 1;
	while(i < j){
		contain = (j - i) * min(height[i],height[j]);
		if(height[i] <= height[j])
			i++;
		else
			j--;
		maxcontain = max(maxcontain,contain);
	}
	return maxcontain;
}
int main(){
	vector<int> height;
	int v;
	while(cin >> v)
	{
		height.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int maxcontain = maxArea(height);
	cout << maxcontain << endl;
	system("pause");
	return 0;
}