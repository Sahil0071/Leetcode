class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
        int x=0;
        for(auto i=0;i<nums.size();i++)
        {
            int j=abs(nums[i])-1;
            nums[j]=abs(nums[j])*-1;
        }
        vector<int>ans;
        for(auto i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
        */
        vector<int>ans;
        for(auto i=0;i<nums.size();i++)
        {
            if(nums[i]==-1)
                continue;
            int idx=nums[i]-1;
            while(nums[idx]!=-1)
            {
                int temp=nums[idx]-1;
                nums[idx]=-1;
                idx=temp;
            }
        }
        for(auto i=0;i<nums.size();i++)
        {
            if(nums[i]!=-1)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
