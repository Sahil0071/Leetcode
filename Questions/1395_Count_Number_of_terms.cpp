class Solution {
public:
    int numTeams(vector<int>& r) {
        int n=r.size();
        int cnt=0;
        for(auto i=0;i<n;i++)
        {
            for(auto j=i+1;j<n;j++)
            {
                for(auto k=j+1;k<n;k++)
                {
                    if(r[i]>r[j]&&r[j]>r[k])
                    {
                        cnt++;
                    }
                    if(r[i]<r[j]&&r[j]<r[k])
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
//     
        
    }
};
