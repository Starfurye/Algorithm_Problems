#include<cstdio>

const int maxn = 100000;

struct Node {
	int next;
	bool inL1;
	Node() {
		next = -1;	inL1 = false;
	}
}nodes[maxn];
int head1, head2, N;

int traverse() {
	int addr = head1;
	while (addr != -1) {
		nodes[addr].inL1 = true;
		addr = nodes[addr].next;
	}
	addr = head2;
	while (addr != -1) {
		if (nodes[addr].inL1 == true)	return addr;
		addr = nodes[addr].next;
	}
	return -1;
}

int main()
{
	scanf("%d%d%d", &head1, &head2, &N);
	for (int i = 0; i < N; ++i) {
		int addr, next;	char data;
		scanf("%d %c %d", &addr, &data, &next);
		nodes[addr].next = next;
	}
	int suf = traverse();
	if (suf != -1) {
		printf("%05d", suf);
	}
	else printf("-1");
	
	return 0;
}
