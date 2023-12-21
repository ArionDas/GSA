#include<bits/stdc++.h>
using namespace std;
const int N = 6;
const int M = 5;

vector<vector<int>> resource_request;
vector<vector<int>> uav_capacity;
vector<vector<int>> round_trip_service_time(N, vector<int>(M,0));
vector<int> time_taken(N,0);
// vector<vector<int>> round_trip_service_time = { {8,7,11,14,11,13},
//                                                 {6,10,8,7,8,7},
//                                                 {18,9,6,12,6,12},
//                                                 {11,8,16,9,14,16},
//                                                 {10,7,12,6,6,8} };

int generateRandomInt() {
    int y = rand() % 100;
    //cout << y << " ";
    return y;
}

void provide_requests(vector<vector<int>> &resource_request) {
    for(int i=0; i<N; i++) {
        vector<int> temp;
        cout << "Enter resource request for W - " << i << endl; 
        for(int j=0; j<M; j++) {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        resource_request.push_back(temp);
    }
}

void provide_uav_capacity(vector<vector<int>> &uav_capacity) {
    for(int i=0; i<N; i++) {
        vector<int> temp;
        cout << "Enter uav capacity for UAV - " << i << endl;
        for(int j=0; j<M; j++) {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        uav_capacity.push_back(temp);
    }
}

void get_round_trip_service_time(vector<vector<int>> &round_trip_service_time) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            round_trip_service_time[i][j] = generateRandomInt();
        }
    }
    cout << endl;
}

void first_iteration(vector<vector<int>> &resource_request, vector<vector<int>> &uav_capacity, vector<vector<int>> &round_trip_service_time, vector<int> &time_taken) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(resource_request[i][j]==1) {
                if(uav_capacity[i][j]==1) {
                    resource_request[i][j] = 0;
                    time_taken[i] += round_trip_service_time[i][j];
                }
            }
        }
    }
}

void remaining_iterations(vector<vector<int>> &resource_request, vector<vector<int>> &uav_capacity, vector<vector<int>> &round_trip_service_time, vector<int> &time_taken) {
    for(int i=0; i<N; i++) {
        bool flag = 0;
        for(int j=0; j<M; j++) {
            if(resource_request[i][j]==1) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            //for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    if(resource_request[i][j]==1) {
                        if(uav_capacity[i][j]==1) {
                            resource_request[i][j] = 0;
                            time_taken[i] += round_trip_service_time[i][j];
                        }
                    }
                }
                bool flag = 0;
                for(int j=0; j<M; j++) {
                    if(resource_request[i][j]==1) {
                        flag = 1;
                        break;
                    }
                }
                if(!flag)
                    break;
            //}
        }
    }
}

int main() {

    provide_requests(resource_request);
    provide_uav_capacity(uav_capacity);
    get_round_trip_service_time(round_trip_service_time);

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << round_trip_service_time[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    first_iteration(resource_request, uav_capacity, round_trip_service_time, time_taken);

    remaining_iterations(resource_request, uav_capacity, round_trip_service_time, time_taken);

    cout << "Maximum time taken = " << *max_element(time_taken.begin(), time_taken.end()) << endl;

    cout << "Time taken for each battle cluster:\n";
    for(int i=0; i<N; i++)
        cout << i << " - " << time_taken[i] << endl;
}


/*

INPUT:
1 1 1 0 0 1 0 0
1 1 0 0 1 0 0 1
0 1 1 1 0 1 1 0
0 0 1 1 1 1 1 1
1 0 0 1 1 0 1 1
0 0 1 1 0 0 0 1
1 1 0 0 1 1 0 0
0 1 0 1 1 1 0 1
1 0 1 0 0 1 0 0
1 1 0 1 1 1 0 1
0 1 1 1 0 1 1 1
1 1 0 0 1 1 0 0

OUTPUT:
236
*/