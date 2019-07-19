#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct student {
    int mark;
    char reg[15];
    int final_rank;
    int loc_num;
    int loc_rank;
}stu[30020];

bool cmp(student a, student b) {
    if (a.mark != b.mark)   return a.mark > b.mark;
    else    return strcmp(a.reg, b.reg) < 0;
}

int main()
{
    int location, stunum, i, j, pointer = 0;
    scanf("%d", &location);
    // init
    for (i = 1; i <= location; ++i) {
        scanf("%d", &stunum);
        for (j = 1; j <= stunum; ++j) {
            scanf("%s %d", stu[pointer].reg, &stu[pointer].mark);
            stu[pointer].loc_num = i;
            ++pointer;
        }
        sort(stu + pointer - stunum, stu + pointer, cmp);
        stu[pointer - stunum].loc_rank = 1;
        int counter = 2;
        for (int k = pointer - stunum + 1; k < pointer; ++k) {
            stu[k].loc_rank = (stu[k].mark != stu[k - 1].mark) ? counter : stu[k - 1].loc_rank;
            ++counter;
        }
    }
    printf("%d\n", pointer);
    sort(stu, stu + pointer, cmp);
    int counter = 2;
    stu[0].final_rank = 1;
    for (int k = 1; k < pointer; ++k) {
            stu[k].final_rank = (stu[k].mark != stu[k - 1].mark) ? counter : stu[k - 1].final_rank;
            ++counter;
        }

    for (int k = 0; k < pointer; ++k) {
        printf("%s %d %d %d\n", stu[k].reg, stu[k].final_rank, stu[k].loc_num, stu[k].loc_rank);
    }

    return 0;
}
