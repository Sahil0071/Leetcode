class Solution {
public:
    string Palindrome(string s)
    {
        int n=s.length();
        int l,r,cur_len,max_len=0,start_ind=0;
        for(auto i=0;i<n;i++)
        {
            //Odd length
            l=i,r=i;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                cur_len=(r-l+1);
                if(cur_len>max_len)
                {
                    start_ind=l;
                    max_len=cur_len;
                }
                l--,r++;
            }
            //Even Length
            l=i,r=i+1;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                cur_len=(r-l+1);
                if(cur_len>max_len)
                {
                    start_ind=l;
                    max_len=cur_len;
                }
                l--,r++;
            }
        }
        return(s.substr(start_ind,max_len));
    }
    
    string longestPalindrome(string s) {
        string str="";
        if(s.length()==0)
        {
            return str;
        }
        str=Palindrome(s);
        return str;
    }
};





class Solution {
public:
    string oddPalindrome(string s)
    {
        int n=s.length();
        string odd="";
        int i=0;
        while(i<n)
        {
            int l=i-1,r=i+1;int c=0;
            if(l<0||r>=n)
            {
                i++;
                continue;
            }
            while(l>=0&&r<n)
            {
                c++;
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            if(c!=0)
            {
                ++l,--r;
                string str=s.substr(l,r-l+1);
                if(odd.length()<str.length())
                {
                    odd=str;
                }
            }
            i++;
            
        }
        return odd;
    }
    string evenPalindrome(string s)
    {
        int n=s.length();
        string even="";int i=1;
        while(i<n)
        {
            int l=i-1,r=i;int c=0;
            if(l<0||r>=n)
            {
                i++;
                continue;
            }
            while(l>=0&&r<n)
            {
                c++;
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            if(c!=0)
            {
                ++l,--r;
                string str=s.substr(l,r-l+1);
                if(even.length()<str.length())
                {
                    even=str;
                }
            }
            i++;
            
        }
        return even;
    }
    string longestPalindrome(string s) {
        string odd="";
        odd=oddPalindrome(s);
        string even="";
        even=evenPalindrome(s);
        string str="";
        str+=s[0];
        if(odd.length()==0&&even.length()==0)
        {
            return str;
        }
        if(odd.length()>even.length())
        {
            return odd;
        }
        else
            return even;
    }
};
