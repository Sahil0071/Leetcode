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

int climbStairs(int n) {
    int dp[n+1]={0};
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    dp[1]=1,dp[2]=2;
    for(auto i=3;i<n+1;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}



int32_t main()
{
	fast;
	int n;
	cin>>n;
	cout<<climbStairs(n)<<endl;
	return 0;
}
