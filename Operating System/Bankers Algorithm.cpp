#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int total_allocated(vector<vector<int>> &allocated_res, int res_no) {
    // res_no = resource number, colum 
    int sum = 0;
    for(int i = 0; i < allocated_res.size(); i++) 
        sum += allocated_res[i][res_no];
}

bool is_possible(vector<int> &available_need, vector<int> &available_res) {
    for(int i = 0; i < available_need.size(); i++) {
        if(available_need[i] > available_res[i])
            return false;
    }
    return true;
}

void solve_problem() {
    // all input would taken from file

    int num_of_res;
    cin >> num_of_res;

    vector<int> total_resources(num_of_res);
    for(int i = 0; i < num_of_res; i++)
        cin >> total_resources[i];

    int num_of_process;
    cin >> num_of_process;

    vector<vector<int>> allocated_res(num_of_process, vector<int>(num_of_res));
    for(int i = 0; i < num_of_process; i++) {
        for(int j = 0; j < num_of_res; j++)
            cin >> allocated_res[i][j];
    }

    vector<vector<int>> max_need(num_of_process, vector<int>(num_of_res));
    for(int i = 0; i < num_of_process; i++) {
        for(int j = 0; j < num_of_res; j++)
            cin >> max_need[i][j];
    }

    vector<int> available_res(num_of_res);
    for(int i = 0; i < num_of_res; i++) {
        available_res[i] = total_resources[i] - total_allocated(allocated_res, i);
    }

    vector<vector<int>> available_need(num_of_process, vector<int>(num_of_res));
    for(int i = 0; i < num_of_process; i++) {
        for(int j = 0; j < num_of_res; j++)
            available_need[i][j] = max_need[i][j] - allocated_res[i][j];
    }

    bool updated = true;
    vector<bool> in_safe(num_of_process, false);
    vector<int> safe_states;
    while(updated) {
        updated = false;
        for(int i = 0; i < num_of_process; i++) {
            // check i is inside safe state or not
            if(in_safe[i]) continue;

            if(is_possible(available_need[i], available_res)) {
                safe_states.push_back(i);
                in_safe[i] = true;
                updated = true;
                // free allocated resources for i
                for(int j = 0; j < num_of_res; j++) 
                    available_res[j] += allocated_res[i][j];
            }
        }   
    }
    
    if(safe_states.size() != num_of_process) {
        cout << "System is in deadlock" << endl;
    } 
    else {
        cout << "System is safe" << endl;
        cout << "Process sequence: " << endl;
        for(int i = 0; i < num_of_process; i++) 
            cout << safe_states[i] << " "; 
    }
}

/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 
