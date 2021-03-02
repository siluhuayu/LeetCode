#include<iostream>
using namespace std;
int hammingDistance(int x, int y){
	int dist = 0;
	while(x != 0 || y != 0)
	{
		if(x % 2 != y % 2)
			dist++;
		x /= 2;
		y /= 2;
	}
	return dist;
}
int main(){
	int x,y;
	cin >> x >> y;
	int count = hammingDistance(x,y);
	cout << count << endl;
	system("pause");
	return 0;
}