struct Trie{
        struct Node{
            Node *child[26];
            int prefix,end;
            Node(){
                prefix=end=0;
                memset(child, 0, sizeof child);
            }
        };
        Node *root=new Node();
        void insert(string &s){
            Node *cur=root;
            for(auto it:s){
                int idx=it-'a';
                if(cur->child[idx]==0){
                    cur->child[idx]=new Node();
                }
                cur=cur->child[idx];
                cur->prefix++;
            }
            cur->end++;
        }
        int cnt_prefix(string &s){
            Node *cur=root;
            for(auto it:s){
                int idx=it-'a';
                if(cur->child[idx]==0){
                    return 0;
                }
                cur=cur->child[idx];
            }
            return cur->prefix;
        }
        ll cnt_word(string &s){
            ll ret=0;
            Node *cur=root;
            for(auto it:s){
                int idx=it-'a';
                if(cur->child[idx]==0){
                    break;
                }
                cur=cur->child[idx];
                ret+=cur->prefix*2;
            }
            return ret;
        }
    };
