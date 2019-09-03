#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100005;
struct Node {
	int Data;
	int Next;
}node[maxn];
int hash[10005] = {0};
int N, head = 100000, head2 = 100001, pointer2 = head2;
void insNode(int addr) {
	node[pointer2].Next = addr;
	node[addr].Next = -1;
	pointer2 = addr;
}
void traverse() {
	int p = node[head].Next, q = head;
	while (p != -1) {
		int key = abs(node[p].Data);
		if (hash[key] == 0) hash[key] = 1;
		else {
			node[q].Next = node[p].Next;
			insNode(p);
			p = q;
		}
		q = p; p = node[p].Next;
	}
}
int abs(int key) { return key > 0 ? key : -key;}

int main()
{
	int hn;
	scanf("%d%d", &hn, &N);
	node[head].Next = hn;
	node[head2].Next = -1;
	for (int i = 0; i < N; ++i) {
		int addr, data, next;
		scanf("%d%d%d", &addr, &data, &next);
		node[addr].Data = data; node[addr].Next = next;
	}
	traverse();
	int p1 = node[head].Next;
	while (p1 != -1) {
		if (node[p1].Next == -1) printf("%05d %d -1\n", p1, node[p1].Data, node[p1].Next);
		else printf("%05d %d %05d\n", p1, node[p1].Data, node[p1].Next);
		p1 = node[p1].Next;
	}
	p1 = node[head2].Next;
	while (p1 != -1) {
		if (node[p1].Next == -1) printf("%05d %d -1\n", p1, node[p1].Data, node[p1].Next);
		else printf("%05d %d %05d\n", p1, node[p1].Data, node[p1].Next);
		p1 = node[p1].Next;
	}
	
	return 0;
}

