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

int call=0;

bool coinChange(vector<int>coin,int sum,int c,int *ans,int n)
{
	call++;
	if(sum==0)
	{
		*ans=min(c,*ans);
		return true;
	}
	if(sum<0)
	{
		return false;
	}
	for(auto i=0;i<n;i++)
	{
		bool check=coinChange(coin,sum-coin[i],c+1,ans,n);
	}
}

int minCoin(vector<int>coin,int sum)
{
	call++;
	if(sum==0)
	{
		return 0;
	}
	int cmin=INT_MAX;
	for(auto i=0;i<coin.size();i++)
	{
		if(coin[i]<=sum)
		{
			cmin=min(cmin,minCoin(coin,sum-coin[i]));
		}
	}
	return cmin+1;
}

int minCoinMemo(vector<int>coin,int sum,vector<int>&memo)
{
	call++;
	if(sum==0)
	{
		return 0;
	}
	int cmin=INT_MAX;
	for(auto i=0;i<coin.size();i++)
	{
		if(coin[i]<=sum)
		{
			if(memo[sum-coin[i]]!=-1)
			{
				cmin=min(cmin,memo[sum-coin[i]]);
			}
			else
				cmin=min(cmin,minCoinMemo(coin,sum-coin[i],memo));
		}
	}
	memo[sum]= cmin+1;
	return memo[sum];
}


void minCoinDP(vector<int>coin,int sum,vector<int>&memo)
{
        for(auto j=1;j<=sum;j++)
        {
            for(auto i=0;i<coin.size();i++)
            {
                if(coin[i]<=j)
                {
                    memo[j]=min(memo[j],memo[j-coin[i]]+1);
                }
                    
            }
        }
}



int coinChange(vector<int>& coins, int amount) {
 	
	/*
        vector<int>memo(amount+1,amount+1);
        memo[0]=0;
        minCoinDP(coins,amount,memo);
        return memo[amount]>amount?-1:memo[amount];*/
	
	//Best Approach
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; ++i)
            for (auto & c : coins)
                if (i - c >= 0 && dp[i - c] != -1)
                    dp[i] = dp[i] > 0 ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;
        
        return dp[amount];
        
}


int32_t main()
{
	fast;
	vector<int>arr={2,4};
	sort(arr.begin(),arr.end(),greater<int>());
	int sum;
	cin>>sum;
	
	/*int ans=INT_MAX;
	bool find=coinChange(arr,sum,0,&ans,3);
	cout<<"No of calls : "<<call<<endl;
	cout<<ans<<endl;*/

	/*int ans=0;
	ans=minCoin(arr,sum);
	cout<<"No of calls : "<<call<<endl;
	cout<<ans<<endl;*/

	int ans=0;
	vector<int>memo(sum+1,-1);
	ans=minCoinMemo(arr,sum,memo);
	cout<<"No of calls : "<<call<<endl;
	cout<<ans<<endl;

	return 0;
}
