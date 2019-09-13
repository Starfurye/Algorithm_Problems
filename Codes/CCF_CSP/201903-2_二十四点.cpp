#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct node {
	int num;
	char op;
	bool flag;
};
string str;
stack<node> s;
queue<node> q;
map<char, int> op;
int n;
void Change() {
	int num;
	node temp;
	for (int i = 0; i < str.size();) {
		if (str[i] >= '0' && str[i] <= '9') {
			temp.flag = true;	temp.num = str[i++] - '0';
			while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
				temp.num = temp.num * 10 + (str[i] - '0'); ++i;
			}
			q.push(temp);
		}
		else {
			temp.flag = false;
			while (!s.empty() && op[str[i]] <= op[s.top().op]) {
				q.push(s.top());	s.pop();	
			}
			temp.op = str[i]; s.push(temp); ++i;
		}
	}
	while (!s.empty()) {
		q.push(s.top()); s.pop();
	}
}
int Cal() {
	double temp1, temp2;
	node cur, temp;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.flag == true) s.push(cur);
		else {
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			temp.flag = true;
			if (cur.op == '+') temp.num = temp1 + temp2;
			else if (cur.op == '-') temp.num = temp1 - temp2;
			else if (cur.op == 'x') temp.num = temp1 * temp2;
			else {
				temp.num = temp1 / temp2;
			}
			s.push(temp);
		} 
	}
	return s.top().num;
}

int main()
{
	op['+'] = op['-'] = 1; op['x'] = op['/'] = 2;
	scanf("%d", &n); getchar();
	for (int i = 0; i < n; ++i) {
		getline(cin, str);
		while (!s.empty()) s.pop();
		Change();
		if (Cal() == 24) {
			printf("Yes\n");
		}
		else printf("No\n");
	}
	
	return 0;
}
