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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         map<char, int> charMap;
        int start = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        
        return maxLen;
            
       
    }
};
