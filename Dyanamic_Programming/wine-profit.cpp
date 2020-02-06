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


//Recursive approach(max(wines[s]*year+func(s+1,e),wines[e]*year+func(s,e-1)))
int calls=0;
int maxprofit(vector<int>wines,int s,int e,int year)
{
	calls++;
	if(s>e)
		return 0;
	int op1=wines[s]*year+maxprofit(wines,s+1,e,year+1);
	int op2=wines[e]*year+maxprofit(wines,s,e-1,year+1);
	return max(op1,op2);
}

//DP Approach

int maxprofitDP(vector<int>wines,int s,int e,int year,int dp[][100])
{
	calls++;
	if(s>e)
		return 0;
	if(dp[s][e]!=0)
		return dp[s][e];
	int op1=wines[s]*year+maxprofitDP(wines,s+1,e,year+1,dp);
	int op2=wines[e]*year+maxprofitDP(wines,s,e-1,year+1,dp);
	dp[s][e]= max(op1,op2);
	return dp[s][e];
}




int32_t main()
{
	fast;
	int n;
	cin>>n;
	vector<int>wines(n);
	for(auto i=0;i<n;i++)
	{
		cin>>wines[i];
	}

	//Recursion
	cout<<maxprofit(wines,0,n-1,1)<<endl;
	cout<<"NO OF Calls : "<<calls<<endl;

	calls=0;

	//DP Approach
	int dp[100][100]={0};
	cout<<maxprofitDP(wines,0,n-1,1,dp)<<endl;
	cout<<"NO OF Calls : "<<calls<<endl;




	return 0;
}
