class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int nows = 0;
        int newLen = 0;
        int mainLen = words.size();
        vector<string> updatedStrings;
        for(int i = 0; i < mainLen; i++){
            newLen = newLen + words[i].size();
            nows++;
            
            if(newLen + (nows-1) <= maxWidth){
                if(i == (mainLen - 1)){
                    string s = "";
                    for(int k = 0; k < nows; k++){
                        s += words[i - (nows - 1) + k];
                        if(k < (nows-1)) s += " ";
                    }
                    for(int l = s.size(); l < maxWidth; l++)
                        s += " ";
                
                    updatedStrings.push_back(s);
                    break;
                }
                else 
                    continue;
            }
            else{
                nows--;
                int spaces = maxWidth - (newLen - words[i].size());
                int ws = spaces, extra=0;
                string s1 = "";
                string s2 = "";
                if(nows > 1){
                    ws = spaces/(nows - 1);
                    extra = spaces%(nows - 1); 
                }
                for(int k = 0; k < ws; k++){
                        s2 += " ";
                }
                if(nows == 1){
                    s1 += words[i - 1];
                    s1 += s2;
                }
                else{
                    for(int j = 0; j < nows - 1; j++){
                        s1 += words[i - nows + j];
                        s1 += s2;
                        if(extra){
                            s1 += " ";  
                            extra--;
                        }                       
                    }
                    s1 += words[i - 1];
                }
                
                updatedStrings.push_back(s1);
                newLen = 0;
                nows = 0;
                
            }
            i -= 1;
        }
        return updatedStrings;
    }
};