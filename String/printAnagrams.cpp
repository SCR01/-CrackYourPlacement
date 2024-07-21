  
  class solution{
    public:
  
  vector<vector<string> > Anagrams(vector<string>& string_list) {
        
        vector<vector<string>> result;
        
        unordered_map<string, vector<string>> mp;
        
        for(auto x : string_list){
            
            string temp = x;
            sort(x.begin(), x.end());
            mp[x].push_back(temp);  
        }


        for(auto temp : mp){
            vector<string> ans = temp.second;
            result.push_back(ans);
        }
        return result;
    }

  }