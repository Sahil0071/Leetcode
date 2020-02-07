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

bool canJump(vector<int>& nums) {

    int n=nums.size();int jmp=nums[0];
    if(jmp>=n-1)
    {
        return true;
    }
    if(n==1)
        return true;
    for(auto i=1;i<n-1;i++)
    {
        if(jmp>=i)
        {
            jmp=max(i+nums[i],jmp);
        }
        if(jmp>=n-1)
        {
            return true;
        }
    }
    return false;
}

//Greedy Approach
bool canJump(vector<int>& nums) {

    int n=nums.size();int jmp=n-1;
    for(auto i=n-1;i>=0;i--)
    {
        if(i+nums[i]>=jmp)
        {
            jmp=i;
        }

    }
    return jmp==0;
}


int32_t main()
{
	fast;


	return 0;
}
