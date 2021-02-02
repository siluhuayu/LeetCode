#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//法一：合并后排序
//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
//	for(int i = 0; i < n; ++i)
//		nums1[m+i] = nums2[i];
//	sort(nums1.begin(),nums1.end());
//}
//法二：按大小插入
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
	int i = 0, j = 0;
    int sorted[200];
    int cur;
    while (i < m || j < n){
        if (i == m)
			cur = nums2[j++];
        else if (j == n)
			cur = nums1[i++];
        else if (nums1[i] < nums2[j])
			cur = nums1[i++];
        else
            cur = nums2[j++];
        sorted[i + j - 1] = cur;
   }
   for(int i = 0; i != m + n; ++i)
        nums1[i] = sorted[i];
}
int main(){
	int m,n;
	cin >> m >> n;
	vector<int> nums1,nums2;
	int v;
	while(cin >> v){
		nums1.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	while(cin >> v){
		nums2.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	merge(nums1,m,nums2,n);
	for(int i = 0; i < m + n; ++i)
		cout << nums1[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
