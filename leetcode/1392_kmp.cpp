class Solution {
public:
    string longestPrefix(string s) {
        
        vector<int> lps(s.length());
        lps[0]=0;
        int j=0;
        for(int i=1;i<s.length();)
        {
            if(s[i]==s[j])
            {
                lps[i]=j+1;
                j++;
                i++;
            }
            else
            {
                if(j!=0)
                    j=lps[j-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        // for(auto i:lps)
        //     cout<<i;
        return s.substr(0,lps[s.length()-1]);
    }
};
