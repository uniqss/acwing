
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <climits>
#include <cstring>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, long long> PIL;
typedef pair<long long, int> PLI;
#define ALL(__x__) __x__.begin(), __x__.end()

struct LListNode {
    int value;
    LListNode *prev = nullptr, *next = nullptr;
};
struct LList {
    LListNode* head = nullptr;
    LListNode* tail = nullptr;
};
void llist_initialize(LList* l) {
    l->head = new LListNode();
    l->tail = new LListNode();
    l->head->next = l->tail, l->tail->prev = l->head;
    l->head->prev = nullptr, l->tail->next = nullptr;
}
// insert after p
LListNode* llist_insert(LListNode* p, int val) {
    auto q = new LListNode();
    q->value = val;
    p->next->prev = q;
    q->next = p->next;
    p->next = q, q->prev = p;
    return q;
}
void llist_foreach(LList* l, function<bool(LListNode*)> f) {
    LListNode *curr = l->head->next, *tail = l->tail;
    while (curr != tail) {
        if (!f(curr)) break;
        curr = curr->next;
    }
}
// 头插
LListNode* llist_insert_head(LList* l, int val) {
    return llist_insert(l->head, val);
}
// 尾插
LListNode* llist_insert_tail(LList* l, int val) {
    return llist_insert(l->tail->prev, val);
}
void llist_remove(LListNode* p) {
    if (p == nullptr) return;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}
LListNode* llist_find(LList* l, int val) {
    LListNode *curr = l->head->next, *tail = l->tail;
    while (curr != tail) {
        if (curr->value == val) return curr;
        curr = curr->next;
    }
    return nullptr;
}
void llist_free(LList* l, bool delete_self = false) {
    LListNode *head = l->head, *next;
    while (head != nullptr) {
        next = head->next;
        delete head;
        head = next;
    }
    if (delete_self) delete l;
}

#define SIZE 10
struct AListNode {
    int value;
    int prev, next;
} node[SIZE];
int head, tail, tot;
int ainitizlize() {
    tot = 2;
    head = 1, tail = 2;
    node[head].next = tail;
    node[tail].prev = head;
}
void ainsert(int p, int val) {
    int q = ++tot;
    node[q].value = val;
    node[node[p].next].prev = q;
    node[q].next = node[p].next;
    node[p].next = q;
    node[q].prev = p;
}
void aremove(int p) {
    if (p <= head || p >= tail) return;
    node[node[p].prev].next = node[p].next;
    node[node[p].next].prev = node[p].prev;
}
int aserach(int val) {
    int curr = 2;
    while (curr != tail) {
        if (node[curr].value == val) return curr;
        curr = node[curr].next;
    }
    return 0;
}
void aclear() {
    memset(node, 0, sizeof(node));
    head = tail = tot = 0;
}

int main() {
    LList l;
    llist_initialize(&l);
    // for (int i = 1; i <= 5; ++i) {
    //     llist_insert_head(&l, i);
    // }
    for (int i = 5; i >= 1; --i) {
        llist_insert_tail(&l, i);
    }
    llist_remove(llist_find(&l, 0));
    int idx = 0;
    llist_foreach(&l, [&idx](LListNode* p) {
        cout << "l[" << idx++ << "] = " << p->value << ", ";
        return true;
    });
    cout << endl;
    llist_free(&l);

    ainitizlize();
    for (int i = 1; i <= 5; ++i) {
        
    }
    aclear();

    return 0;
}
