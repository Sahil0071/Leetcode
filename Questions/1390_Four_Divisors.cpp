class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();int anssum=0;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp;
        for(auto i=0;i<n;i++)
        {
            int ans=0;long long int sum=0;
            if(mp.count(nums[i])==0)
            {
                int j;
                for( j=1;j*j<nums[i];j++)
                {
                    if(nums[i]%j==0)
                    {
                        ans+=2;
                        sum+=(nums[i]/j)+j;
                    }
                    if(ans>4)
                    {
                        break;
                    }
                }
                if(nums[i]==(j*j))
                {
                    ans++;
                    sum+=(j);
                }
                mp1[nums[i]]=ans;
                mp[nums[i]]=sum;
            }
            
            if(mp1[nums[i]]==4)
            {
                anssum+=mp[nums[i]];
                //break;
            }
        }
        return anssum;
        
    }
};
