#include<cstdio>
#include<set>

using namespace std;
const int maxn = 10010; 
int seq[maxn];
int M, N;
set<int> st;
 
void Check() {
    int A, U, V;
    int i, flag1 = true, flag2 = true;
    scanf("%d%d", &U, &V);
    if(st.find(U) == st.end()){
        flag1 = false;
    }
    if(st.find(V) == st.end()){
        flag2 = false;
    }
    if(flag1 == false || flag2 == false){
        if(flag1 == false && flag2 == false){
            printf("ERROR: %d and %d are not found.\n",U,V);
        }else if(flag1 == false){
            printf("ERROR: %d is not found.\n",U);
        }else{
            printf("ERROR: %d is not found.\n",V);
        }
        return;
    }
    for(i = 0; i < N; i++){
        A = seq[i];
        if((A > U && A < V) || (A < U && A > V))
		{
            printf("LCA of %d and %d is %d.\n", U, V, A);
            return;
        }else if(A == U){
            printf("%d is an ancestor of %d.\n", A, V);
            return;
        }else if(A == V){
            printf("%d is an ancestor of %d.\n", A, U);
            return;
        }
    }
}
 
int main() 
{
    int a,i;
    scanf("%d%d",&M,&N);
    for(i = 0; i < N; ++i){
        scanf("%d", &a);
        st.insert(a);
        seq[i] = a;
    }
    while(M--){
        Check();
    }
    return 0;
}
