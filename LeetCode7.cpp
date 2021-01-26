#include<iostream>
using namespace std;
int reverse(int x){
	int res = 0,len = 0,y;
	int base = 1,sh;
	bool flag = true;
		if(x < 0){
			sh = (int)0x80000000;
			y = x;
			while(y <= -10)
			{
				base *= 10;
				y /= 10;
			}
			while(x <= -10){
				if((x % 10) < sh/base){//-2147483648,-2143847412,-1563847412,-2147483412
					flag = true;
					return 0;
				}
				flag = true;
				if((x % 10) == sh/base)
					flag = false;
				sh = flag ? sh:(sh - sh/base * base);
				res -= base * (x % 10);
				x /= 10;
				base /= 10;	
			}
			if(flag || x >= -2)
				res -= x;
			else
				return 0;
		}
		else{
			sh = 0x7fffffff;
			y = x;
			while(y >= 10)
			{
				base *= 10;
				y /= 10;
			}
			while(x >= 10){
				if((x % 10) > sh/base){//1534236469,1563847412,1463847412
					flag = true;
					return 0;
				}
				if((x % 10) == sh/base)
					flag = false;
				sh = flag ? sh:(sh - sh/base * base);
				res += base * (x % 10);
				x /= 10;
				base /= 10;	
			}
			if(flag || x <= 7)
				res += x;
			else
				return 0;
		}
	return x>=0 ? res:-res;
}
int main(){
	int x;
	cin >> x;
	int res = reverse(x);
	cout << res << endl;
	system("pause");
	return 0;
}