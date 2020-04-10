class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        
        int n=a.size();
        
        vector<int> presum(n+2,0),dp(n+2,0);
        presum[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
            presum[i]=presum[i+1]+a[i];
        
        dp[n-1]=a[n-1];
        
        int x,y,z;
        
        for(int i=n-2;i>=0;i--)
        {
            y=z=-99999;
            x=a[i]+presum[i+1]-dp[i+1];
            if(i<=n-2) y=a[i]+a[i+1]+presum[i+2]-dp[i+2];
            if(i<=n-3) z=a[i]+a[i+1]+a[i+2]+presum[i+3]-dp[i+3];
            dp[i]=max(x,max(y,z));
            //cout<<"x= "<<x<<", y= "<<y<<", z= "<<z<<endl;
        }
        
        if(dp[0]*2==presum[0]) return "Tie";
        if(dp[0]*2>presum[0]) return "Alice";
        return "Bob";
    }
};
