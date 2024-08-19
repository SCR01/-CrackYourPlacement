class trienode{
    public:
    char data;
    trienode* children[26];
    bool isterminal;
    trienode(char data){
        this->data= data;
        for(int i=0; i<26; i++){
            children[i]=nullptr;
            
        }
        isterminal=false;
        
    }
};
class trie{
    public:
    trienode* root;
    
  trie(){
    root= new trienode('\0');
    
  } 
  
  void insertword(trienode* root, string word){
      
      if(word.length()==0){
         root-> isterminal= true;
          return;
          
      }
      int index= word[0]-'a';
      trienode* child;
      if(root->children[index]!=nullptr){
          child= root->children[index];
          
      }
      else{
          child= new trienode(word[0]);
          root->children[index]= child;
          
      }
      //recudsion call
      insertword(child, word.substr(1));
      
      
  }
  void insertstring(string word){
      insertword(root, word);
  }
  void printSuggestion(string &prefix, vector<string>&temp, trienode* curr){
      
      if(curr->isterminal){
          temp.push_back(prefix);
          
      }
      for(char ch= 'a'; ch<='z'; ch++){
          trienode* next= curr->children[ch-'a'];
          if(next!=NULL){
              prefix.push_back(ch);
              printSuggestion(prefix, temp, next);
              prefix.pop_back();
          }
      }
      
      
  }
  vector<vector<string>>getSuggestion(int n, string contact[], string s){
      
      
      trienode* prev= root;
      vector<vector<string>> output;
      
      string prefix="";
      for(int i=0; i<s.length(); i++){
          char lastch= s[i];
          prefix.push_back(lastch);
          trienode* curr= prev->children[lastch-'a'];
          if(curr==nullptr){
              break;
          }
          vector<string>temp;
          printSuggestion(prefix, temp, curr );
          
          output.push_back(temp);
          temp.clear();
          prev= curr;
          
          
          
      }
      int r= s.size()-output.size();
      for(int i=0; i<r; i++){
          output.push_back({"0"});
      }
      return output;
      
  }
  
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        //ctreate an objectr
        trie* t= new trie;
        
        for(int i=0; i<n; i++){
            string str=contact[i];
            
         t->insertstring(str);
            
     
        }
        
        return t->getSuggestion(n, contact, s);
        
    }
};