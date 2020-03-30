class Solution {
public:
    int Maxkadane(vector<int>&v)
    {
        int max_sum=INT_MIN,cur_sum=0;
        int n=v.size();
        for(auto i=0;i<n;i++)
        {
            cur_sum=max(cur_sum+v[i],v[i]);
            max_sum=max(cur_sum,max_sum);
        }
        return max_sum;
    }
    int Minkadane(vector<int>&v)
    {
        int min_sum=INT_MAX,cur_sum=0;
        int n=v.size();
        for(auto i=0;i<n;i++)
        {
            cur_sum=min(cur_sum+v[i],v[i]);
            min_sum=min(cur_sum,min_sum);
        }
        return min_sum;
    }
    int maxSubarraySumCircular(vector<int>& v) {
       int max_sum=Maxkadane(v);
        int min_sum=Minkadane(v);
        int sum=accumulate(v.begin(),v.end(),0);
        int m_sum=sum-min_sum;
        if(m_sum==0)
        {
            return max(min_sum,max_sum);
        }
        return max(m_sum,max_sum);
    }
};
