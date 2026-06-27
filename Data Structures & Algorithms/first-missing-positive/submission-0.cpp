class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

          int n = nums.size();
    vector<int>hash(n+1,0);
    for(int i =0;i<n;i++){
        if(nums[i]<=n&&nums[i]>0){
            hash[nums[i]]++;
        }
    }
    for(int i =1;i<=n;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return hash.size();
        
    }
};
