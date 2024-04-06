
class Trie {
public:
    
    Trie* head;
    vector<bool> existe; 
    map<char,Trie*> letters;
    bool  fisrTime;
    
    Trie() {
        fisrTime = true;
        existe = vector<bool>('z'+5, false);
    }
   

    void insert(string word) {
        
        if(fisrTime){
            head = new Trie();
            head->existe['z'+1] = 1;
            fisrTime = false;
        }

        Trie* current = this->head;

        for(int i=0;i<word.size();i++){
            if(!current->existe[word[i]]){
                current->existe[word[i]] = 1;
                Trie* next = new Trie();
                current->letters[word[i]]=next;
            }
            current = current->letters[word[i]];
        }
         current->existe['z'+1] = 1;
    }
    
    bool movement(string word,int pos,Trie* current,int tipe){

        if(pos>=word.size()){
            if(tipe == 0){
                return  current->existe['z'+1];
            }
            return true;
        }
        if(!current->existe[word[pos]]){
            return false;
        }
        return movement(word,pos+1,current->letters[word[pos]],tipe);
    }

    bool search(string word) {
        if(fisrTime)
            return false;
        Trie* current = this->head;
        return movement(word,0,current,0);
    }
    
    bool startsWith(string prefix) {
        if(fisrTime)
            return false;
        Trie* current = this->head;
        return movement(prefix,0,current,1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */