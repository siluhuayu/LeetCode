#include<iostream>
#include<string>
using namespace std;
int strStr(string haystack, string needle){
	int lenh = haystack.size();
	int lenn = needle.size();
	if(lenn == 0)
		return 0;
	int res;
	for(int i = 0,j = 0; i <= lenh - lenn; i++)
	{
		if(haystack[i] == needle[j]){
			res = i;
			while(haystack[res] == needle[j]){
				res++;
				j++;
				if(j == lenn)
					break;
			}
			if(j == lenn)
				return i;
			else
				j = 0;
		}
	}
	return -1;
}
//整数越界
//#define Rehash(a,b,h) ((((h) - (a)*d) << 1) + (b))
//int strStr(string haystack,string needle){
//	char *x,*y;
//	y = &haystack[0];
//	x = &needle[0];
//	int m = strlen(x);
//	int n = strlen(y);
//	if(n == 0)
//		return 0;
//	int d, hx, hy, i, j;
//	for(d = i = 1; i < m; i++)
//		d = d << 1;
//	for(hy = hx = i =0; i<m;i++){
//		hx = (hx << 1) + x[i];
//		hy = (hy << 1) + y[i];
//	}
//	for(j = 0;j <= n - m; j++){
//		if(hx == hy && memcmp(x,y + j,m) == 0 ){
//			return j;
//		}
//		hy = Rehash(y[j],y[j + m],hy);
//	}
//	return -1;
//}
int main(){
	string haystack,needle;
	cin >> haystack >> needle;
	int res = strStr(haystack,needle);
	cout << res << endl;
	system("pause");
	return 0;
}