#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
struct node {
	int addr;
	int data;
	int next;
}Node[100010];
vector<node> v1, v2, v3;
int n, st, k, data, next, p;

int main()
{
	scanf("%d%d%d", &st, &n, &k);
	for (int i = 0; i < n; ++i) {
		int addr;
		scanf("%d", &addr);
		scanf("%d%d", &Node[addr].data, &Node[addr].next);
		Node[addr].addr = addr;
	}
	p = st;
	while (p != -1) {
		if (Node[p].data < 0) v1.push_back(Node[p]);
		else if (Node[p].data > k) v3.push_back(Node[p]);
		else v2.push_back(Node[p]);
		p = Node[p].next;
	}
	for (int i = 0; i < v2.size(); ++i) v1.push_back(v2[i]);
	for (int i = 0; i < v3.size(); ++i) v1.push_back(v3[i]);
	for (int i = 0; i < v1.size(); ++i) {
		if (i == 0) printf("%05d %d ", v1[i].addr, v1[i].data);
		else printf("%05d\n%05d %d ", v1[i].addr, v1[i].addr, v1[i].data);
	}
	printf("-1\n");

	return 0;	
}
