#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    vector<int> res;
    int i = 0, j = 0;
    int len1 = nums1.size(),len2 = nums2.size();
    while(i < len1 && j < len2){
        if(nums1[i] == nums2[j])
        {   
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return res;
}
int main(){
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
	vector<int> res = intersection(nums1,nums2);
	for(int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}