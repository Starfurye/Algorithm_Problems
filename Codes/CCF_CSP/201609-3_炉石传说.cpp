#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n;
int hero1 = 30, hero2 = 30, fo1 = 0, fo2 = 0;
struct node {
	int hp, atk; bool flag;
	node() {
		hp = atk = 0; flag = false;
	}
	node(int _hp, int _atk, bool _flag) {
		hp = _hp; atk = _atk; flag = _flag;
	}
}fl1[8], fl2[8];
void die(int player, int pos) {
	if (player == 1) {
		for (int i = pos + 1; i <= 7; ++i) {
			fl1[i - 1] = fl1[i];
		}
		fl1[7].atk = 0; fl1[7].flag = false; fl1[7].hp = 0;
		--fo1;
	}
	else {
		for (int i = pos + 1; i <= 7; ++i) {
			fl2[i - 1] = fl2[i];
		}
		fl2[7].atk = 0; fl2[7].flag = false; fl2[7].hp = 0;
		--fo2;
	}
}
void summon(int player, int pos, int atk, int hp) {
	node follower(hp, atk, true);
	if (player == 1) {
		if (fl1[pos].flag) {
			for (int i = 7; i > pos; --i) {
				fl1[i] = fl1[i - 1];
			}
		}
		fl1[pos] = follower;
		++fo1;
	}
	else {
		if (fl2[pos].flag) {
			for (int i = 7; i > pos; --i) {
				fl2[i] = fl2[i - 1];
			}
		}
		fl2[pos] = follower;
		++fo2;
	}
}
void attack(int player, int atkpos, int defpos) {
	if (player == 1) {
		if (defpos == 0) {
			hero2 -= fl1[atkpos].atk;
		}
		else {
			fl1[atkpos].hp -= fl2[defpos].atk; fl2[defpos].hp -= fl1[atkpos].atk;
			if (fl1[atkpos].hp <= 0) die(1, atkpos);
			if (fl2[defpos].hp <= 0) die(2, defpos);
		}
	}
	else {
		if (defpos == 0) {
			hero1 -= fl2[atkpos].atk;
		}
		else {
			fl1[defpos].hp -= fl2[atkpos].atk; fl2[atkpos].hp -= fl1[defpos].atk;
			if (fl1[defpos].hp <= 0) die(1, defpos);
			if (fl2[atkpos].hp <= 0) die(2, atkpos);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("in.txt", "r", stdin);
	cin >> n;
	int player = 1;
	for (int i = 0; i < n; ++i) {
		string op; cin >> op;
		if (op == "summon") {
			int pos, atk, hp;
			cin >> pos >> atk >> hp;
			summon(player, pos, atk, hp);
		}
		else if (op == "attack") {
			int atk, def;
			cin >> atk >> def;
			attack(player, atk, def);
		}
		else player = player == 1 ? 2 : 1;
	}
	// fclose(stdin);
	if (hero1 <= 0 && hero2 > 0) cout << -1;
	else if (hero1 > 0 && hero2 <= 0) cout << 1;
	else cout << 0;
	cout << endl;
	cout << hero1 << endl;
	cout << fo1;
	if (fo1 > 0) {
		for (int i = 1; i <= 7; ++i) {
			if (fl1[i].flag) cout << " " << fl1[i].hp;
		}
	}
	cout << endl;
	cout << hero2 << endl;
	cout << fo2;
	if (fo2 > 0) {
		for (int i = 1; i <= 7; ++i) {
			if (fl2[i].flag) cout << " " << fl2[i].hp;
		}	
	}
	
	return 0;
}
