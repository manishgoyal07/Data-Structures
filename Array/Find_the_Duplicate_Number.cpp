//Problem:  287. Find the Duplicate Number
//-------------------------------------------------------------------------------------
//Code :  Floyd's Algorithm

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int n=nums.size();
		int fast=nums[0];
		int slow=nums[0];
		do{
			fast=nums[nums[fast]];
			slow=nums[slow];
		}while(slow!=fast);
		fast=nums[0];
		while(slow!=fast){
			slow=nums[slow];
			fast=nums[fast];
		}
		return slow;
	}
};

//Time Complexity:  O(N)
//Auxilary Space Complexity:  O(1)
//-------------------------------------------------------------------------------------
