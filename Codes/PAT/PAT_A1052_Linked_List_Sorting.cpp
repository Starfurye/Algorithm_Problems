#include<algorithm>
#include<cstdio>

using namespace std;

int N;
const int maxn = 100002;

struct Node {
    int Addr, key, next;
    bool flag;
}node[maxn];

bool cmp(Node a, Node b) {
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    }
    else return a.key < b.key;
}

int main()
{
    for (int i = 0; i < maxn; ++i) {
        node[i].flag = false;
    }
    int head, address;
    scanf("%d", &N);
    scanf("%d", &head);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].key, &node[address].next);
        node[address].Addr = address;
    }
    int count = 0, p = head;
    while (p != -1) {
        node[p].flag = true;
        ++count;
        p = node[p].next;
    }

    if (count == 0) printf("0 -1");
    else {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].Addr);
        for (int i = 0; i < count; ++i) {
            if (i != count - 1) {
                printf("%05d %d %05d\n", node[i].Addr, node[i].key, node[i + 1].Addr);
            }
            else {
                printf("%05d %d -1\n", node[i].Addr, node[i].key);
            }
        }
    }

    return 0;
}
