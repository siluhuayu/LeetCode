#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int maxScore(vector<int>& cardPoints, int k){
	int i = 0,len = cardPoints.size();
	int sum = 0,minsum;
	for(i; i < len - k; ++i)
		sum += cardPoints[i];
	minsum = sum;
	for(; i < len;++i)
	{
		sum = sum - cardPoints[i - len + k] + cardPoints[i];
		if(sum < minsum)
			minsum = sum;
	}
	sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
	return sum - minsum;
}
int main(){
	vector<int> cardPoints;
	int v;
	while(cin >> v){
		cardPoints.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int k;
	cin >> k;
	int res = maxScore(cardPoints,k);
	cout << res << endl;
	system("pause");
	return 0;
}