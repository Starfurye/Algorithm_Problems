#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100007;

int N, L, H;
struct Person {
	int id;
	int vir, tal;
	int total;
}sage[maxn], noble[maxn], fool[maxn], other[maxn];
int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

bool cmp(Person a, Person b) {
	if (a.total == b.total) {
		if (a.vir == b.vir) {
			return a.id < b.id;
		}
		return a.vir > b.vir;
	}
	return a.total > b.total;
}

int main()
{
	scanf("%d%d%d", &N, &L, &H);
	for (int i = 0; i < N; ++i) {
		int id, vir, tal;
		scanf("%d%d%d", &id, &vir, &tal);
		if (vir >= H && tal >= H) {
			sage[p1].id = id; sage[p1].vir = vir; sage[p1].tal = tal; sage[p1++].total = vir + tal;
		}
		else if (vir >= H && tal >= L) {
			noble[p2].id = id; noble[p2].vir = vir; noble[p2].tal = tal; noble[p2++].total = vir + tal;
		}
		else if (vir >= L && tal >= L && vir >= tal) {
			fool[p3].id = id; fool[p3].vir = vir; fool[p3].tal = tal; fool[p3++].total = vir + tal;
		}
		else if (vir >= L && tal >= L){
			other[p4].id = id; other[p4].vir = vir; other[p4].tal = tal; other[p4++].total = vir + tal;
		}
	}
	sort(sage, sage + p1, cmp); sort(noble, noble + p2, cmp); sort(fool, fool + p3, cmp); sort(other, other + p4, cmp);
	printf("%d\n", p1 + p2 + p3 + p4);
	for (int i = 0; i < p1; ++i) { printf("%d %d %d\n", sage[i].id, sage[i].vir, sage[i].tal); }
	for (int i = 0; i < p2; ++i) { printf("%d %d %d\n", noble[i].id, noble[i].vir, noble[i].tal); }
	for (int i = 0; i < p3; ++i) { printf("%d %d %d\n", fool[i].id, fool[i].vir, fool[i].tal); }
	for (int i = 0; i < p4; ++i) { printf("%d %d %d\n", other[i].id, other[i].vir, other[i].tal); }
	
	return 0;
}
