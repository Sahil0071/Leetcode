class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char>q;
        unordered_map<char,int>mp;
        int n=s.length();
        int m=0;
        for(auto i=0;i<n;i++)
        {
            if(mp.count(s[i])==0)
            {
                q.push(s[i]);
                int c=q.size();
                m=max(c,m);
                mp[s[i]]=1;
            }
            else
            {
                while(!q.empty())
                {
                    auto x=q.front();
                    mp.erase(x);
                    if(x!=s[i])
                    {
                        q.pop();
                    }
                    else
                        break;
                }
                q.pop();
                q.push(s[i]);
                mp[s[i]]=1;
                int c=q.size();
                m=max(c,m);
            }
            
        }
        return m;
        
    }
};
