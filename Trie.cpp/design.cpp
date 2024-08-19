class WordDictionary {
public:
    struct TrieNode {
      TrieNode* childNode[27];
      bool isLeaf;
      TrieNode( ) {
        for (int i = 0; i < 26; i++) { 
            childNode[i] = nullptr; 
        }
        isLeaf = false;
      }
    };

    TrieNode *root;

    void addWordIntoTrie(string word) {
      TrieNode* currentNode = root->childNode[word[0]-'a'] == nullptr? new TrieNode() : root->childNode[word[0]-'a'];
      root->childNode[word[0]-'a'] = currentNode;
      for(int i=1;i<word.size();i++) {
        TrieNode* nextNode = currentNode->childNode[word[i]-'a'] == nullptr? new TrieNode() : currentNode->childNode[word[i]-'a'];
        if(currentNode->childNode[word[i]-'a'] == nullptr)
        currentNode->childNode[word[i]-'a'] = nextNode;
        currentNode = nextNode;
      }
      currentNode->isLeaf = true;
      TrieNode* temp = root->childNode[word[0]-'a'];
      bool have = true;
    }

    bool searchD(string &word, TrieNode* current, int index) {
      if(current == nullptr) {
        return false;
      }

      if(index>=word.size()) {
        return false;
      }
      // if(word[index]=='.' && current && index==(word.size()-1) && current->isLeaf) {
      //   return true;
      // }
      current = word[index]!='.' ? current->childNode[word[index]-'a'] : current;
      if(word[index]!='.' && current && index==(word.size()-1) && current->isLeaf) {
        return true;
      }
      
      if(current == nullptr) {
        return false;
      }
      bool found = false;

      if(word[index]=='.') {
        for(int i=0;i<26;i++) {
          if(current->childNode[i] && current->childNode[i]->isLeaf && index == (word.size()-1)) {
            return true;
          }
          found = found | searchD(word, current->childNode[i], index+1);
        }
        // found = found | searchD(word, current, index+1);
      } else {
        found = searchD(word, current, index+1);
      }
      return found;

    }

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        addWordIntoTrie(word);
    }
    
    bool search(string word) {
        return searchD(word, root, 0);
    }
};