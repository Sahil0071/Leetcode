class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
        vector<pair<int,int>>v(m.size());vector<int>ans;
        for(auto i=0;i<m.size();i++)
        {
            int min_el=INT_MAX,pos=0;
            for(auto j=0;j<m[0].size();j++)
            {
                if(min_el>m[i][j])
                {
                    min_el=m[i][j];
                    pos=j;
                }
            }
            v[i]={min_el,pos};
            
        }
        int k=0;
        for(auto i=0;i<m.size();i++)
        {
            auto max_el=0;
            for(auto j=0;j<m.size();j++)
            {
                max_el=max(max_el,m[j][v[i].second]);
            }
            if(max_el==v[i].first)
            {
                ans.push_back(v[i].first);
            }
            
        }
        return ans;
    }
};
