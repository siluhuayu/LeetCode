#include<iostream>
#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
	vector<int> nums;
	double mid_num;
	int len1 = nums1.size(),len2 = nums2.size();
	for(int i = 0,j = 0; i < len1 || j < len2;){
		if( i < len1 && j < len2){
			if(nums1[i] < nums2[j])
				nums.push_back(nums1[i++]);
			else if(nums1[i] > nums2[j])
				nums.push_back(nums2[j++]);
			else{
				nums.push_back(nums1[i++]);
				nums.push_back(nums2[j++]);
			}
		}
		else if(i < len1)
			nums.push_back(nums1[i++]);
		else
			nums.push_back(nums2[j++]);
		int len = nums.size();
		if( len > (len1 + len2)/2 ){
			if(len == (len1 + len2)/2 + 1){
				if( (len1 + len2) % 2 == 0 )
					mid_num = (double) (nums[len-1] + nums[len-2])/2;
				else
					mid_num =  (double) nums[len-1];
				break;
			}
			else{
				if( (len1 + len2) % 2 == 0 )
					mid_num = (double) (nums[len-2] + nums[len-3])/2;
				else
					mid_num =  (double) nums[len-2];
				break;
			}	 
		}	
	}
	return mid_num;
}
int main(){
	vector<int> nums1,nums2;
	int v;
	while(cin >> v){
		nums1.push_back(v);
		if(cin.get()=='\n')
			break;
	}
	while(cin >> v){
		nums2.push_back(v);
		if(cin.get()=='\n')
			break;
	}
	double mid_num = findMedianSortedArrays(nums1,nums2);
	cout << mid_num << endl;
	system("pause");
	return 0;
}