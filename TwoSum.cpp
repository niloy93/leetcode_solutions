class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> res;
        int len = nums.size();
        
        for(int i=0; i<len; i++)
            hash[nums[i]]=i;
        
        for(int i=0; i<len; i++)
        {
            int temp = target - nums[i];
            if(hash.find(temp) != hash.end() && hash[temp] != i){
                res.push_back(hash[temp]);
                res.push_back(i);
                return res;
            }
        }
        
        return res;
    }
};