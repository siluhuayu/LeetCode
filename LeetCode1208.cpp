#include<iostream>
#include<vector>
#include<string>
using namespace std;
int equalSubstring(string s, string t, int maxCost){
	vector<int> minus;
	int len = s.length();
	for(int i = 0; i < len; ++i)
		minus.push_back(abs(s[i]-t[i]));
	int cost = 0,maxcount = 0;
	int end = 0, start = 0;
	while(end < len)
	{
		cost += minus[end];
		while(cost > maxCost){
			cost -= minus[start];
			start++;
		}
		maxcount = max(end-start+1,maxcount);
		end++;
	}
	return maxcount;
}
int main(){
	string s,t;
	cin >> s >> t;
	int maxCost;
	cin >> maxCost;
	int maxcount = equalSubstring(s,t,maxCost);
	cout << maxcount << endl;
	system("pause");
	return 0;
}