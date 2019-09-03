#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100005;
struct Node {
	int Data;
	int Next;
}node[maxn];
int N, K, size = 0, head = 100000;

void traverse() {
	int p = node[head].Next, q = 0;
	while (p != -1) {
		p = node[p].Next; ++size;
	}
}
void reverse(int left) {
	int p = node[left].Next, q = node[p].Next, r = p;
	for (int i = 1; i <= K; ++i) r = node[r].Next;
	int right = r;
	while (q != right) {
		node[p].Next = r; r = p; p = q; q = node[q].Next;
	}
	node[p].Next = r; node[left].Next = p;
}

int main()
{
	int ad;
	scanf("%d%d%d", &ad, &N, &K);
	node[head].Next = ad;
	for (int i = 0; i < N; ++i) {
		int addr, data, next;
		scanf("%d%d%d", &addr, &data, &next);
		node[addr].Data = data; node[addr].Next = next;
	}
	traverse();
	int times = size / K, p = head;
	for (int i = 0; i < times; ++i) {
		reverse(p);
		for (int j = 1; j <= K; ++j) p = node[p].Next;		
	}
	p = node[head].Next;
	while (node[p].Next != -1) {
		printf("%05d %d %05d\n", p, node[p].Data, node[p].Next);
		p = node[p].Next;
	}
	printf("%05d %d -1", p, node[p].Data);
	
	return 0;
}
