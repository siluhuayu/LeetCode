#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices){
	int maxprofit = 0;
    int len = prices.size();
    for(int i = 0; i < len - 1; ++i)
        maxprofit += max(0, prices[i + 1] - prices[i]);
	return maxprofit;
}
int main(){
	vector<int> prices;
	int v;
	while(cin >> v){
		prices.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int maxprofit = maxProfit(prices);
	cout << maxprofit << endl;
	system("pause");
	return 0;
}