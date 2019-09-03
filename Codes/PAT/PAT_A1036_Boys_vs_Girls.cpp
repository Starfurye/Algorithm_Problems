#include<cstdio>
#include<cstring>

int N;
char mName[12], mID[12], fName[12], fID[12];
int mMin = 101, fMax = -1;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char name[12], ID[12];
		char gender; int grade;
		scanf("%s %c %s %d", name, &gender, ID, &grade);
		if (gender == 'M') {
			if (grade < mMin) {
				strcpy(mName, name);	strcpy(mID, ID);	mMin = grade;
			}
		}
		else {
			if (grade > fMax) {
				strcpy(fName, name);	strcpy(fID, ID);	fMax = grade;
			}
		}
	}
	if (fMax == -1) {printf("Absent\n");}
	else {printf("%s %s\n", fName, fID);}
	if (mMin == 101) {printf("Absent\n");}
	else {printf("%s %s\n", mName, mID);}
	if (mMin == 101 || fMax == -1) {printf("NA");}
	else printf("%d", fMax - mMin);
	
	return 0;
}
