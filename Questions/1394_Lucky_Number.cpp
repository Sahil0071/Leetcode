class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto i:arr)
        {
            mp[i]++;
        }
        int m=-1;
        for(auto i:mp)
        {
            if(i.first==i.second)
            {
                m=max(m,i.first);
            }
        }
        return m;
    }
};
