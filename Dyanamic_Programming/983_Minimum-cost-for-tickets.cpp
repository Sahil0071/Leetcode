int mincostTickets(vector<int>& days, vector<int>& costs) {

    vector<int>dp(days[days.size()-1]+1);
    for(auto i=0;i<days.size();i++)
    {
        dp[days[i]]=1;
    }
    dp[0]=0;
    for(auto i=1;i<=days[days.size()-1];i++)
    {
        if(dp[i]==1)
        {
            int day7=((i-7)>0)?i-7:0;
            int day30=((i-30)>0)?i-30:0;
            dp[i]=min(dp[i-1]+costs[0],min(dp[day7]+costs[1],dp[day30]+costs[2]));
        }
        else
            dp[i]=dp[i-1];
    }
    
    return dp[days[days.size()-1]];
    
}
