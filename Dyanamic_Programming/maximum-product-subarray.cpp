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

int maxProduct(vector<int>& nums) {

    if (nums.size() == 0) return 0;

    int cur_max = nums[0], cur_min = nums[0];
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {

        int temp=cur_max
        cur_max = max(nums[i], max(cur_max * nums[i], cur_min * nums[i]));//For storing current maximum
        cur_min = min(nums[i], min(temp * nums[i], cur_min * nums[i]));//For storing current min so when a negative value meets with another negative it may leed to another maximum value(-2,3,-4) and in the next loop it will be updated
        ans = max(ans, cur_max);

    }
    return ans;
}

int32_t main()
{
	fast;
	int n;
	cin>>n;
	vector<int>nums(n);
	for(auto i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	
	//Functions Call;
	

	return 0;
}
