class WordDictionary {
public:
    
    map<char,WordDictionary*> leeters;

    WordDictionary() {
    }
    
    void dpAdd(string word,int pos, WordDictionary* current){
        current->leeters['.'] =  new WordDictionary();
        if(pos>=word.size()){
            current->leeters['*'] =  new WordDictionary();
            return;
        }
        if(current->leeters[word[pos]]==NULL){
            current->leeters[word[pos]] = new WordDictionary();
        }
        dpAdd(word,pos+1,current->leeters[word[pos]]);

    }

    void addWord(string word) {
        dpAdd(word,0,this);
    }
    
    bool dpSearch(int pos,string word,WordDictionary* current){
        if(current!=NULL && pos>=word.size() ){
            if(current->leeters['*']!=NULL){
                return true;
            }
            return false;
        }
        if(word[pos]=='.' && current!=NULL){
            for(auto x:current->leeters){
                if(dpSearch(pos+1,word,x.second)){
                    return true;
                }
            }
            return false;
        }
        else if(current!=NULL && current->leeters[word[pos]]!=NULL){
            return dpSearch(pos+1,word,current->leeters[word[pos]]);
        }
        return false;
    }

    bool search(string word) {
        return dpSearch(0,word,this);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */