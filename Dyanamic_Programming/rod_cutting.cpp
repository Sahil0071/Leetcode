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

vector<int>memo(100,-1);
vector<int>dp(100,0);

int maxProfit_rec(vector<int>arr,int tl)
{
	if(tl==0)
	{
		return 0;
	}
	int best=0;
	for(auto i=1;i<=tl;i++)
	{
		int netprofit=arr[i]+maxProfit_rec(arr,tl-i);
		best=max(best,netprofit);
	}
	return best;
}

int maxProfit_memo(vector<int>arr,int tl)
{
	if(tl==0)
	{
		return 0;
	}
	if(memo[tl]!=-1)
	{
		return memo[tl];
	}
	int best=0;
	for(auto i=1;i<=tl;i++)
	{
		int netprofit=arr[i]+maxProfit_memo(arr,tl-i);
		best=max(best,netprofit);
	}
	memo[tl]=best;
	return memo[tl];
}

int maxProfit_bu(vector<int>arr,int tl)
{
	int m=0;
        for(auto i=1;i<=tl;i++)
        {
            m=0;
            for(auto j=1;j<=i;j++)
            {
                m=max(m,arr[j]+dp[i-j]);
            }
            dp[i]=m;
        }
	return dp[tl];
}


int32_t main()
{
	fast;
	ll n;
	cin>>n;
	vector<int>arr(n+1);
	for(auto i=0;i<n;i++)
	{
		cin>>arr[i+1];
	}
	cout<<maxProfit_rec(arr,n);
	cout<<endl;

	cout<<maxProfit_memo(arr,n);
	cout<<endl;

	cout<<maxProfit_bu(arr,n);
	cout<<endl;

	return 0;
}
