class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int>lps(n,0);
        string str="";
        int i=1,j=0;
        while(i<n&&j<n)
        {
            if(s[i]==s[j])
            {
                lps[i]=j+1;
                i++,j++;
            }
            else
            {
                
                if((j-1)<0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                    j=lps[j-1];
                
            }
        }
        
        for(auto i=0;i<lps[n-1];i++)
        {
            str+=s[i];
        }
        return str;
    }
};
