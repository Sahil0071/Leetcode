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

//KADANE'S Algorithm
int maxSubArray(vector<int>& nums) {

    int currentSum =nums[0], totalSum = nums[0];

    for(int i=1; i<nums.size(); i++) {

        //Current max sum is either the current element OR current element + Previous Maximum subarray)
        currentSum = max(nums[i], currentSum+nums[i]); 

        //If the current maximum array sum is greater than the global total. Update it
        totalSum = max(totalSum, currentSum);
    }
    return totalSum;

}

//Another approach
int maxSubArray(vector<int>& nums) {
    fast;
    int n=nums.size();
    int m=0,ans=INT_MIN;
    if(n==1)
    {
        return nums[0];
    }
    for(auto i=0;i<n;i++)
    {
        m=max((m+nums[i]),nums[i]);
        ans=max(m,ans);
    }
    return ans;
        
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
