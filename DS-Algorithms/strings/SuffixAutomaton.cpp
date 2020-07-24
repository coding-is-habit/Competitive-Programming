#include<bits/stdc++.h>
using namespace std;

template<int MAXN>
class SuffixAutomation{
    struct state{
        int len, link;
        map<char,int> next;
        state()len(0),link(-1){}
    } *tree;
    int sz, last;
public:
    SuffixAutomation(){
        tree = new state[MAXN];
        last = 0;
        sz = 1;
    }
    void add(char c){
        int cur = sz++, p = last;
        tree[cur].len = tree[last].len + 1;
        for(; p != -1 && !tree[p].next.count(c); p = tree[p].link)
            tree[p].next[c] = cur;
        if(p == -1){
            tree[cur].link = 0;
        }else{
            int q = tree[p].next[c];
            if(tree[q].len == tree[p].len+1){
                tree[cur].link = q;
            }else{
                int clone = sz++;
                tree[clone].len = tree[p].len+1;
                tree[clone].next = tree[q].next;
                tree[clone].link = tree[q].link;
                for(p != -1 && tree[p].next[c] == q; p = tree[p].link){
                    tree[p].next[c] = clone;
                }
                tree[q].link = tree[cur].link = clone;
            }
        }
        last = cur;
    }
};

int main(){

    return 0;
}