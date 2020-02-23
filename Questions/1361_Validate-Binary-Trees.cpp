//https://leetcode.com/contest/weekly-contest-177/problems/validate-binary-tree-nodes/
#include<bits/stdc++.h>
class Solution {
public:
    
    bool findCycle_dup(vector<int>g[],vector<bool>&vis,int src)
    {
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            vis[node]=true;
            for(auto n:g[node])
            {
                if(!vis[n])
                {
                    vis[n]=true;
                    q.push(n);
                }
                else
                    return true;
            }
        }
        return false;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
       // int n=leftChild.size();
        vector<int>g[n];
        for(auto i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
                g[i].push_back(leftChild[i]);
            if(rightChild[i]!=-1)
                g[i].push_back(rightChild[i]);
        }
        vector<bool>vis(n,0);int nc=0;
        for(auto i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(findCycle_dup(g,vis,i))
                {
                    return false;
                }
                nc++;
            }
        }
        if(nc>1)
        {
            return false;
        }
        return true;
        
    }
};
