class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int>v(n);
        for(auto i=0;i<n;i++)
        {
            int pos=0;
            for(auto j=0;j<index[i];j++)
            {
                pos++;
            }
            for(auto j=n-1;j>pos;j--)
            {
                v[j]=v[j-1];
            }
            v[pos]=nums[i];
            
        }
        return v;
        
    }
};
