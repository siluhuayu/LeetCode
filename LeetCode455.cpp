#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s){
	sort(g.begin(),g.end());
	sort(s.begin(),s.end());
	int n = g.size(),m = s.size();
	int count = 0;
	for(int i = 0,j = 0; i < n && j < m; ){
		if(g[i] <= s[j]){
			i++;
			j++;
			count++;
		}
		else
			j++;
	}
	return count;
}
int main(){
	vector<int> g,s;
	int v;
	while(cin >> v){
		g.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	while(cin >> v){
		s.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int count = findContentChildren(g,s);
	cout << count << endl;
	system("pause");
	return 0;
}