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

//Naive Approach
int maxProfit(vector<int>& prices) {

    int ans=0;
    int n=prices.size();
    for(auto i=0;i<n;i++)
    {
        for(auto j=i+1;j<n;j++)
        {
            if(ans<(prices[j]-prices[i]))
            {
                ans=prices[j]-prices[i];
            }
        }
    }
    return ans;

}

//Left and Right Approach
int maxProfit(vector<int>& prices) {

    int n=prices.size();
    if(n==0)
        return 0;
    vector<int>left(n),right(n);
    left[0]=prices[0],right[n-1]=prices[n-1];
    for(auto i=1;i<n;i++)
    {
        left[i]=min(left[i-1],prices[i]);
    }
    for(auto i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],prices[i]);
    }
    int ans=0;
    for(auto i=0;i<n;i++)
    {
        ans=max(right[i]-left[i],ans);
    }
    return ans;
    

}

//Using 1d DP
int maxProfit(vector<int>& prices) {

    int n=prices.size();
    int minp=INT_MAX,maxp=0;
    for(auto i=0;i<n;i++)
    {
        if(prices[i]<=minp)
        {
            minp=prices[i];
        }
        else if(prices[i]-minp>maxp)
        {
            maxp=prices[i]-minp;
        }
    }
    return maxp;
    

}

int32_t main()
{
	fast;
	int n;
	cin>>n;
	vector<int>prices(n);
	for(auto i=0;i<n;i++)
	{
		cin>>prices[i];
	}
	
	//Functions Call;
	

	return 0;
}

NOTE:
The logic to solve this problem is same as "max subarray problem" using Kadane's Algorithm. Since no body has mentioned this so far, I thought it's a good thing for everybody to know.

All the straight forward solution should work, but if the interviewer twists the question slightly by giving the difference array of prices, Ex: for {1, 7, 4, 11}, if he gives {0, 6, -3, 7}, you might end up being confused.

Here, the logic is to calculate the difference (maxCur += prices[i] - prices[i-1]) of the original array, and find a contiguous subarray giving maximum profit. If the difference falls below 0, reset it to zero.

    public int maxProfit(int[] prices) {
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.length; i++) {
            maxCur = Math.max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = Math.max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
*maxCur = current maximum value

*maxSoFar = maximum value found so far
