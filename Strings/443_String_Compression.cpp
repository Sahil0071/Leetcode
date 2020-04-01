class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i=0,j,l=0;
        int n=chars.size();
        string str;
        int w=0;
        while(i<n)
        {
            j=i+1;str+=chars[i];chars[w++]=chars[i];
            while(j<n&&chars[i]==chars[j])
            {
                j++;
            }
            int c=j-i;
            
            if(c>1)
            {
                string s=to_string(c);
                int k=0;
                l=s.length();
                while(l--)
                {
                    chars[w++]=s[k++];
                }
                str+=s;
                
            }
            i=j;
            
        }
        return w;
    }
};
