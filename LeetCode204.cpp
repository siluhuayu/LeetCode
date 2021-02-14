#include<iostream>
using namespace std;
bool isPrime(int x){
	for(int i = 2; i*i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}
int countPrimes(int n){
	int count = 0;
	for(int i = 2; i < n; ++i)
	{
		if(isPrime(i))
			count++;
	}
	return count;
}
int main(){
	int n;
	cin >> n;
	int count = countPrimes(n);
	cout << count << endl;
	system("pause");
	return 0;
}