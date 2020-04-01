class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s="11";string str;
        int i=0;
        while(n>2)
        {
            str="";
            int l=s.length();int pos=0;
            for(auto i=0;i<l;i++)
            {
                int j=i+1;
                while(j<l&&s[i]==s[j])
                {
                    j++;
                }
                
                int c=j-i;
                str+=to_string(c)+s[i];
                i=j-1;
            }
            s=str;
            n--;
        }
        return s;
        
    }
};
