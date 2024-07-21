class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        //we will be keeping track of frequency of p in a map
       // unordered_map<char,int>tmap;
        vector<int>cur(26,0);
        for(int i=0;i<p.size();i++)
        {
            cur[p[i]-'a']++;
        }
       // for(auto c:p)tmap[c]++;
        
        int i=0,j=0,counter=p.size(),minstart=0,minlen=INT_MAX;
        int n=s.size();
        
        while(j<n)
        {
            if(cur[s[j]-'a']>0)
            {
                counter--;
            }
            
            cur[s[j]-'a']--;
            
            while(counter==0) //means we got a substring consisiting of our string p
            {
                if(j-i+1<minlen)
                {
                    minstart=i;
                    minlen=j-i+1;
                }
                
                cur[s[i]-'a']++;  
                if(cur[s[i]-'a']>0)
                {
                    counter++;
                }
                i++;
            }
            
            j++;
        }
        
        return (minlen!=INT_MAX?s.substr(minstart,minlen):"-1");
        
    }
};
..... see less

1

0
Reply