#include<iostream>
using namespace std;
int k;
bool isBadVersion(int n){
	if(n >= k)
		return true;
	else
		return false;
}
int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (isBadVersion(mid)) 
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
}
int main(){
	int n;
	cin >> n >> k;
	int res = firstBadVersion(n);
	cout << res << endl;
	system("pause");
	return 0;
}