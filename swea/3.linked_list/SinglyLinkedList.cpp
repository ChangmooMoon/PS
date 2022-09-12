#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

struct Node {
    int data;
    Node *next;
};

Node *newNode(int data) { // 동적할당 방식
    Node *node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}

// 정적할당(메모리 풀) 방식. 메모리풀 - 사용할 노드를 한번에 모두 할당하고 필요할때마다 꺼내쓴다.
// 1. 동적할당을 하는 오버헤드 제거
// 2. 사용이 끝날때마다 메모리 해제 안해도 됨
// 3. 메모리주소가 뭉쳐져있어서 캐시효율 높음
constexpr size_t MAX_NODE = 10'000;
int nodeCnt = 0;
Node nodePool[MAX_NODE];

Node *newNode(int data) {
    nodePool[nodeCnt].data = data;
    nodePool[nodeCnt].next = nullptr;

    return &nodePool[nodeCnt++];
}

Node head; // 더미노드, doubly 인 경우에는 head, tail 정의

void insert(int x) {
    Node *node = newNode(x);
    node->next = head.next;
    head.next = node;
}

void remove(int x) {
    Node *prevPtr = &head;
    while (prevPtr->next != nullptr && prevPtr->next->data != x) {
        prevPtr = prevPtr->next;
    }

    if (prevPtr->next != nullptr) { prevPtr->next = prevPtr->next->next; }
}

bool find(int x) {
    Node *ptr = head.next;
    while (ptr != nullptr && ptr->data != x) {
        ptr = ptr->next;
    }
    return ptr != nullptr;
}

void init() { head.next = nullptr; }

int main() {
    FASTIO;

    return 0;
}
