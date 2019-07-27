#include<stack>
#include<algorithm>
#include<cstdio>
#include<iostream>

using namespace std;

int M, N, K;

int main()
{
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 1; i <= K; ++i) {
        int j = 1, k;
        bool valid = true;
        stack<int> st;
        for (k = 1; k <= N; ++k) {
            int num;
            scanf("%d", &num);
            while (j <= N + 1) {
                if (j <= num) {
                    if (st.size() < M) st.push(j++);
                    else {
                        valid = false;
                        break;
                    }
                }
                if (j > num) {
                    if (st.top() == num) {
                        st.pop();
                    }
                    else {
                        valid = false;
                    }
                    break;
                }
            }
            if (valid == false) break;
        }
        if (valid == false) printf("NO\n");
        else printf("YES\n");
        int tmp;
        for (int i = N - k; i > 0; --i)    scanf("%d", &tmp);
    }

    return 0;
}
