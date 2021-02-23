#include<iostream>
#include<vector>
using namespace std;
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X){
	int n = customers.size();
	int sum = 0;
	for(int i = 0; i < n; ++i)
		if(grumpy[i] == 0)
			sum += customers[i];
	int add = 0;
	for(int i = 0; i < X; ++i)
		add += customers[i] * grumpy[i];
	int maxadd = add;
	for(int i = X; i < n; ++i)
	{
		add = add - customers[i-X] * grumpy[i-X] + customers[i] * grumpy[i];
		maxadd = max(add,maxadd);
	}
	return sum + maxadd;
}
int main(){
	vector<int> customers,grumpy;
	int v;
	while(cin >> v){
		customers.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	while(cin >> v){
		grumpy.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int X;
	cin >> X;
	int sum = maxSatisfied(customers,grumpy,X);
	cout << sum << endl;
	system("pause");
	return 0;
}