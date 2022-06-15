class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n;
        int cnt=0;
        for(int start=0;cnt<n;start++){
            int cur = start;
            int prev = nums[start];
            do{
                int next = (cur+k)%n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                cnt++;
                cur = next;
            }while(cur != start);
        }
    }
};