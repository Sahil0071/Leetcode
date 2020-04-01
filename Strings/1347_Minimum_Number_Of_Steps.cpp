class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp,mp1;int ans=0;
        for(auto i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto i=0;i<t.length();i++)
        {
            mp1[t[i]]++;
        }
        for(auto i:mp)
        {
            if(mp1.count(i.first)==0)
            {
                ans+=i.second;
            }
            else if(mp1[i.first]<i.second)
                ans+=i.second-mp1[i.first];
        }
        return ans;
        
    }
};
