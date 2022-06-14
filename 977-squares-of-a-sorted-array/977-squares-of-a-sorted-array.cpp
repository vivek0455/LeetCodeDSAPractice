class Solution {
public:
    int findPositiveIndex(vector<int> nums, int n){
        // int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] >= 0 ) return i;
        }
        return n;
    }
    
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        int posIndex = findPositiveIndex(nums, n);
        vector<int> minarray;
        int i=posIndex-1;
        int j = posIndex;
        vector<int> ans;
        while(i>=0 && j<n){
            if(nums[i]*nums[i] > nums[j]*nums[j]){
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
            else{
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
        }
        // left side element
        while(i>=0){
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        // right side elements
        while(j<n){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        return ans;
    }
};