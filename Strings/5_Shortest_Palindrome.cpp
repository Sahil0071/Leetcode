class Solution {
public:
    
    
    int palindrome(string s)
    {
        int n=s.length();
        int m=-1;
        for(auto i=1;i<=n;i++)
        {
            string str=s.substr(0,i);
            string s1=str;
            reverse(str.begin(),str.end());
            if(s1==str)
            {
                m=i;
            }
        }
        return m;
    }
    
    int palindromeLength(string s)
    {
        int n=s.length();
        int max_len=-1,cur_len=0;
        for(auto i=n-1;i>=0;i--)
        {
            int l=i,r=i;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                if(l==0)
                {
                    cur_len=(r-l+1);
                    max_len=max(max_len,cur_len);
                }
                l--,r++;
            }
            l=i,r=i+1;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                if(l==0)
                {
                    cur_len=(r-l+1);
                    max_len=max(max_len,cur_len);
                }
                l--,r++;
            }
        }
        return max_len;
    }
    
    string shortestPalindrome(string s)
    {
        /*
        int m=palindrome(s);
        
        if(m!=0)
        {
            string str=s.substr(m);
            reverse(str.begin(),str.end());
            return (str+s);
        }
        else
        {
            string str=s;
            reverse(str.begin(),str.end());
            return (str+s);
        }
        */
        
        /*int n = s.size();
        string rev=s;
        reverse(rev.begin(), rev.end());
        int j = 0;
        for (int i = 0; i < n; i++) {
            //cout<<rev.substr(i)<<endl;
            if (s.substr(0, n - i) == rev.substr(i))
                return rev.substr(0, i) + s;
        }
        return "";*/
        
        
        cout<<s<<endl;
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }
        if (i == n)
            return s;
        string remain_rev = s.substr(i, n);
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};
