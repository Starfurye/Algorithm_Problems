#include<cstdio>
#include<cstring>
// Normal solution is much easier than using big numbers in this file, just practise. 

int T;
struct bign {
	int d[24];
	int len;
	bool pos;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0; pos = true;
	}
};
bign change(char str[]) {
	bign a;
	if (str[0] == '-') {
		a.pos = false;
		a.len = strlen(str) - 1;
		for (int i = 0; i <= a.len - 1; ++i) {
			a.d[i] = str[a.len - i] - '0';
		}
	}
	else {
		a.pos = true;
		a.len = strlen(str);
		for (int i = 0; i < a.len; ++i) {
			a.d[i] = str[a.len - i - 1] - '0';
		}
	}
	
	return a;
}
int compare(bign a, bign b) {
	if (a.len > b.len) return 1;
	else if (a.len < b.len) return -1;
	else {
		for (int i = a.len - 1; i >= 0; --i) {
			if (a.d[i] > b.d[i]) return 1;
			else if (a.d[i] < b.d[i]) return -1;
		}
		return 0;
	}
}
bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; ++i) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}
bign sub(bign a, bign b) {
	bign c;
	for (int i = 0; i < a.len || i < b.len; ++i) {
		if (a.d[i] < b.d[i]) {
			--a.d[i + 1];
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
		--c.len;
	}
	return c;
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		char str1[24], str2[24], str3[24];
		scanf("%s %s %s", str1, str2, str3);
		bign a, b, c, d;
		a = change(str1); b = change(str2); c = change(str3);
		if (a.pos == true && b.pos == false) {
			int result = compare(a, b);
			if (result == 1) {
				d = sub(a, b);
				d.pos = true;
			}
			else if (result == -1) {
				d = sub(b, a);
				d.pos = false;
			}
			else {
				d.len = 1; d.pos = true;
			}
		}
		else if (a.pos == false && b.pos == true) {
			int result = compare(a, b);
			if (result == 1) {
				d = sub(a, b);	d.pos = false;
			}
			else if (result == -1) {
				d = sub(b, a);	d.pos = true;
			}
			else {
				d.len = 1; d.pos = true;
			}
		}
		else {
			d = add(a, b); d.pos = a.pos == true ? true : false;
		}
		printf("Case #%d: ", i + 1);
		int result = compare(d, c);
		if (d.pos == true && c.pos == false) printf("true\n");
		else if (c.pos == true && d.pos == false) printf("false\n");
		else {
			if (d.pos == true) {
				if (result == 1) printf("true\n");
				else printf("false\n");
			}
			else {
				if (result == -1) printf("true\n");
				else printf("false\n");
			}
		}
	}
	
	return 0;
}
