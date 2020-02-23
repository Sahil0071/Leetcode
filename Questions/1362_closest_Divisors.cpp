//https://leetcode.com/contest/weekly-contest-177/problems/closest-divisors/
class Solution {
public:
    vector<int>v1,v2;
    int find_factor(int n)
    {
        int c1=0,c2=0;
        for(auto i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                c1=i;
                c2=n/i;
            }
        }
        if(v1.size()==0)
        {
            v1.push_back(c1);
            v1.push_back(c2);
        }
        else
        {
            v2.push_back(c1);
            v2.push_back(c2);
        }  
        return abs(c1-c2);
    }
    
    vector<int> closestDivisors(int num) {
        
        
        int f1=find_factor(num+1);
        int f2=find_factor(num+2);
        if(f1<f2)
        {
            return v1;
        }
        else
            return v2;
    }
};
