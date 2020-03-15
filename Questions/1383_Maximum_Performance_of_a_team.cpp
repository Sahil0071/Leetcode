typedef long long ll;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<array<ll, 2>> v;
        for(int i=0; i<n; ++i)
            v.push_back({efficiency[i], speed[i]});
        sort(v.begin(), v.end());
        ll s=0, ans=0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i=n-1; ~i; --i) {
            pq.push(v[i][1]);
            s+=v[i][1];
            if(pq.size()>k) {
                s-=pq.top();
                pq.pop();
            }
            ans=max(ans, s*v[i][0]);
        }
        return ans%1000000007;
    }
};
