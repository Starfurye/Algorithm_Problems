#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct Action {
    int room;
    int time;
    int type; // 0:put, 1:get
    Action(int room_, int time_, int type_) : room(room_), time(time_), type(type_) {}
    bool operator<(const Action &other) const {
        if(time<other.time) return true;
        else if(time==other.time && type<other.type) return true;
        else if(time==other.time && type==other.type && room<other.room) return true;
        return false;
    }
};

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    vector<Action> actions;
    vector<int> states(N+1);
    for(int n=1; n<=N; n++) states[n] = n;
    
    for(int k=0; k<K; k++) {
        int room, begin, length;
        scanf("%d%d%d", &room, &begin, &length);
        actions.push_back(Action(room, begin, 1));
        actions.push_back(Action(room, begin+length, 0));
    }
    sort(actions.begin(), actions.end());
    for(int i=0; i<actions.size(); i++) {
        Action &act = actions[i];
        if(act.type == 0) { // put
            for(int n=1; n<=N; n++) {
                if(states[n] == -1) {
                    states[n] = act.room;
                    break;
                }
            }
        }
        else { // get
            for(int n=1; n<=N; n++) {
                if(states[n] == act.room) {
                    states[n] = -1;
                    break;
                }
            }
        }
    }
    for(int n=1; n<=N; n++) {
        printf("%d ", states[n]);
    }
    return 0;
}
