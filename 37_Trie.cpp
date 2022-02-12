#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int GO_MAX = 10; // 트라이 노드마다 포인터 개수

struct Trie{
    Trie* go[GO_MAX]; // 다음 노드를 가리키는 포인터 배열
    bool output; // 이 노드에서 끝나는 전화번호가 있는가?
    bool goexist; // 이 노드의 자식이 있는가?

    // 생성자
    Trie(){
        fill(go, go+GO_MAX, nullptr);
        output = goexist = false;
    }

    // 소멸자
    ~Trie(){
        for(int i=0;i<GO_MAX;i++){
            if(go[i]) delete go[i];
        }
    }
    // 문자열 key를 현재 노드부터 삽입
    void insert(const char* key){
        // 문자열이 끝남
        if(*key == '\0') output = true;
        else{
            int next = *key - '0';
            // 해당 노드가 없으면 새로 동적 할당해서 만듦
            if(!go[next]) go[next] = new Trie;
            goexist = true;
            // 자식 노드에서 이어서 삽입
            go[next]->insert(key+1);
        }
    }
    // 이 노드가 일관성이 있는가?
    bool consistent(){
        // 자식도 있으면서 여기서 끝나는 전화번호도 있다면 일관성 없음
        if(goexist && output) return false;
        // 자식들 중 하나라도 일관성이 없으면 이 노드도 일관성이 없음
        for(int i=0;i<GO_MAX;i++)
            if(go[i] && !go[i]->consistent()) return false;
        return true;
    }
};

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N;
        scanf("%d",&N);
        Trie *root = new Trie;
        for(int i=0;i<N;i++){
            char tel[11];
            scanf("%s",tel);
            root->insert(tel);
        }
        cout<<(root->consistent()?"YES":"NO")<<'\n';
        delete root;
    }
}