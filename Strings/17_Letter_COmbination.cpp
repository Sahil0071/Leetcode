class Solution {
public:
    void findComb(vector<string>&ans,unordered_map<int,vector<char>>mp,string d,int i,int n,string s)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        vector<char>v=mp[int(d[i])-48];
        for(auto k=0;k<v.size();k++)
        {
            s[i]=v[k];
            findComb(ans,mp,d,i+1,n,s);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)
        {
            return ans;
        }
        unordered_map<int,vector<char>>mp;
        int k=97;
        for(auto i=2;i<7;i++)
        {
            int cnt=1;
            while(cnt<=3)
            {
                mp[i].push_back(char(k++));
                cnt++;
            }
        }
        mp[7]={'p','q','r','s'};
        mp[9]={'w','x','y','z'};
        mp[8]={'t','u','v'};
        
        findComb(ans,mp,digits,0,digits.length(),digits);
        return ans;
    }
};
