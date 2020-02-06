#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define input(a,b) vector<ll>v(b);for(auto i=a;i<b;i++)cin>>v[i]
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef unordered_map<ll,ll> mpp;
typedef pair<ll,ll> ii;

//TLE using this approach
int numSquares(int n) 
{
    vector<int>dp(n+1,INT_MAX);
    for(auto i=0;i*i<=n;i++)
    {
        dp[i*i]=1;
    }
    if(dp[n]==1)
        return 1;
    
    for(auto i=1;i<n+1;i++)
    {
        if(dp[i]!=1)
        for(auto j=1;j<=i/2;j++)
        {
            if(dp[i]!=1&&(i-j)>=0)
            {
                dp[i]=min(dp[i],dp[j]+dp[i-j]);
            }
        }
    }
    return dp[n];
        
}

//Using DP
int numSquares(int n) {
        
    vector<int>arr;
    for(auto i=1;i*i<=n;i++)
    {
        arr.push_back(i*i);
        if(i*i==n)
        {
            return 1;
        }
    }
    vector<int>dp(n+1,-1);
    dp[0]=0;
    
    for(auto i=1;i<=n;i++)
    {
        for (auto & c : arr)
            if (i - c >= 0 && dp[i - c] != -1)
                dp[i] = dp[i] > 0 ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;

    }
    return dp[n];
        
}


int32_t main()
{
	fast;
	int n;
	cin>>n;
	cout<<numSquares(n)<<endl;


	return 0;
}
