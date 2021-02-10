#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//³¬Ê±
//int maxProfit(vector<int>& prices){
//	int len = prices.size();
//	int max = 0,temp = 0;
//	for(int i = 0; i < len - 1; ++i)
//		for(int j = i + 1; j < len; ++j){
//			temp = prices[j] - prices[i];
//			if(temp > max)
//				max = temp;
//		}
//	return max;
//}
int maxProfit(vector<int>& prices){
	int len = prices.size();
	int res = 0,st = prices[0];
	for(int i = 0; i < len;++i){
		res = max(res, prices[i] - st);
		st = min(st,prices[i]);
	}
	return res;
}
int main(){
	vector<int> prices;
	int v;
	while(cin >> v){
		prices.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int max = maxProfit(prices);
	cout << max << endl;
	system("pause");
	return 0;
}