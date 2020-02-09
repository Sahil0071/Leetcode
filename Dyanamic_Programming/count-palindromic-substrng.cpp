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

int countSubstrings(string s) {
    int n = s.length();
    int ans[n][n];
    
//         String of Length 1
    for(int i=0; i<n; i++) 
    {
        ans[i][i] = 1;
        if(i!=n-1)
            ans[i+1][i]=1;
    }
    int sum=0;
    
//         Loop of string of lengths starting from 2;
    for(int L=2; L<=n; L++){
        for(int i=0; i<n-L+1; i++){
            int j = i+L-1;
            if(s[i] == s[j]){
                ans[i][j] = ans[i+1][j-1];
            }else ans[i][j] = 0;
            sum+=ans[i][j];
        }
    }
    
     sum+=n;
    
    
    return sum;
}


int32_t main()
{
	fast;
    test
	{
	    string x,y;
	    cin>>x;y=x;reverse(x.begin(),x.end());
	    cout<<lcs_dp(x,y)<<endl;
	}

	return 0;
}
