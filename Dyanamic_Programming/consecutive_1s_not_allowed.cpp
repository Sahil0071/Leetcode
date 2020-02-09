#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define test ll t;cin>>t;while(t--)
#define input(a,b) vector<ll>v(b);for(auto i=a;i<b;i++)cin>>v[i]
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mod 1000000007
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef unordered_map<ll,ll> mpp;
typedef pair<ll,ll> ii;


int32_t main()
{
	fast;
	test
	{
	    int n;int nz=1,no=0,ans=0;
	    cin>>n;
	    for(auto i=1;i<=n;i++)
	    {
	        auto t=nz;
	        nz=(nz+no)%mod;
	        no=t;
	        ans=(nz+no)%mod;
	    }
	    cout<<ans%mod<<endl;
	    
	}


	return 0;
}
