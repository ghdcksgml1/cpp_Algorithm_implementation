#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define HASH_SIZE (1<<18)
#define MAXN 100000
#define DIV (HASH_SIZE - 1)

using namespace std;

typedef unsigned long long ll;

// 문자열 비교
bool strCmp(char a[],char b[]){
    int i = 0;

    for(;a[i];i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return a[i] == b[i];
}

// 문자열 복사
void strCpy(char dst[],char src[]){
    while(*src){
        *dst++ = *src++;
    }

    *dst = 0;
}

// 구조체
struct Node{
    char key[11];
    int data;
    Node *next;

    // 할당하기
    Node *alloc(char _key[],int _data,Node *_next){
        strCpy(key,_key); // key를 복사해서 넣는다.
        data = _data; // 데이터도 복사
        next = _next; // next 도 복사
        return this;
    }

    // 찾는 node의 바로 이전 node를 반환한다.
    Node *getPrevNode(char _key[]){
        Node *ptr = this;

        while(ptr->next){
            // 찾는 키가 다음 노드의 키와 같다면 멈춤!
            if(strCmp(_key,ptr->next->key)){
                break;
            }
            ptr = ptr->next;
        }
        return ptr;
    }
};

int bCnt;
Node buf[MAXN];
Node hashTable[HASH_SIZE];

void init(){
    bCnt = 0;
    for(int i=0;i<HASH_SIZE;i++){
        hashTable[i].next = 0;
    }
}

// 해쉬 값 반환.
int getKey(char str[]){
    ll key = 5381;
    for(int i=0;str[i];i++){
        key = ((key<<5)+key)+(str[i]-'a'+1);
    }

    return (int)(key & DIV);
}

// 키를 통해 찾기
int find(char key[]){
    Node *prevNode;
    int target = getKey(key); // 키값을 통해 해시 값을 받아와서
    prevNode = hashTable[target].getPrevNode(key); // 해시값으로 찾기

    return prevNode->next->data;
}

// 추가하기
void add(char key[],int data){
    int target = getKey(key);  // 키 값을 통해 해시 값을 받아와서
    hashTable[target].next = buf[bCnt++].alloc(key,data,hashTable[target].next);
}

// 삭제하기
int remove(char key[]){
    Node *prevNode, *targetNode;
    int target = getKey(key);
    prevNode = hashTable[target].getPrevNode(key);
    targetNode = prevNode->next;

    prevNode->next = targetNode->next;
    return targetNode->data;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<"#"<<tc<<' ';

    }

    return 0;
}