#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
const int NOLEVEL = -2;
 
struct operating{
	string act;
	int level;
};
typedef pair<string, string> link;
typedef vector<string> ceta;
map<string,ceta> user;
map<link,int> admin; 
vector<string> all_ceta;
vector<string> ceta_t;
void Associate_user(string user_name,string admin_name){
	for(int i = 0; i < user[admin_name].size(); i++){
		int lv = admin[make_pair(user_name,user[admin_name][i])];
		if(lv == 0){
			admin[make_pair(user_name,user[admin_name][i])] = admin[make_pair(admin_name,user[admin_name][i])];
		}
		else{
			admin[make_pair(user_name,user[admin_name][i])] =
			max(lv,admin[make_pair(admin_name,user[admin_name][i])]);
		}
	}
	
}
operating getOp(string op){
	operating r;
	if(op.size() < 3) {r.act = op; r.level = NOLEVEL;return r;}
	if(op[op.size() - 2] == ':'){
		int endindex = op.size()-1;
		if(op[op.size()-1] >= '0' && op[op.size()-1] <='9'){
			r.act = op.substr(0,endindex-1);
			r.level = op[endindex] - '0' + 1;
			return r;
		}			
	}
	else{
		r.act = op; r.level = NOLEVEL;return r;
	}
	
} 
int main(){
	ios::sync_with_stdio(false);
// freopen("in.txt", "r", stdin);
	int n, m;
	string op,user_name,admin_name;
	operating temp;
	cin >> n;	
	for(int i = 0 ; i < n ; i++){
		cin >> op;
		all_ceta.push_back(op);
	}
		
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> admin_name;
		cin >> m;
		ceta_t.clear();
		for(int j = 0 ; j < m ; j++){
			cin>>op;
			temp = getOp(op);
			if(admin[make_pair(admin_name,temp.act)] < temp.level || temp.level == NOLEVEL) 
				admin[make_pair(admin_name,temp.act)] = temp.level;	
			ceta_t.push_back(temp.act);		
		}
		user[admin_name] = ceta_t;
	}
	
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> user_name;
		cin >> m;
		for(int j = 0 ; j < m ; j++){
			cin >> admin_name;
			Associate_user(user_name,admin_name);		
		}
	}
	
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin>>user_name >> op;
		temp = getOp(op);
		int result = admin[make_pair(user_name,temp.act)];
				
		if(temp.level == NOLEVEL){
			if(result == NOLEVEL) cout << "true" <<endl;
			else if(result == 0) cout << "false" << endl;
			else cout << result - 1 << endl;			
		}
		else{
			if(result == 0 || result < temp.level)cout << "false" << endl;
			else cout << "true"<< endl;
		}
	}		
// fclose(stdin);
	return 0;
}
