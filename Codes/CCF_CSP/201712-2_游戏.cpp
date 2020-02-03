#include<iostream>

using namespace std;
const int maxn = 1010;
int n, k;
struct node {
	int pre;
	int next;
} nodes[maxn];
int main()
{
	cin >> n >> k;
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		nodes[i].next = i + 1;
		nodes[i].pre = i - 1;
	}
	nodes[0].next = 1; nodes[1].pre = n; nodes[n].next = 1;
	
	int num = n, cur = 0; // head node
	int i = 0;
	bool flag = false;
	while (num > 1) {
		// find next
		while (i == 0 || flag == false || i % k != 0 && i % 10 != k) {
			flag = true;
			cur = nodes[cur].next;
			++i;
		}
		
		//delete node
		node t = nodes[cur];
		nodes[t.pre].next = t.next;
		nodes[t.next].pre = t.pre;
		cur = t.pre;
		--num;
		flag = false; 
	}
	printf("%d\n", cur);
	
	return 0;
}
