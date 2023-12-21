#include<bits/stdc++.h>
using namespace std;
const int N = 6; //battle clusters
const int M = 5; //number of UAVs
const int O = 8; //type of resources

vector<vector<int>> resource_request;
vector<vector<int>> uav_capacity;
vector<vector<int>> round_trip_service_time(N, vector<int>(M,0));
vector<int> time_req(N,0);
vector<int> time_taken(N,0);

int generateRandomInt() {
    int y = rand() % 100;
    cout << y << " ";
    return y;
}

void provide_requests(vector<vector<int>> &resource_request) {
    for(int i=0; i<N; i++) {
        vector<int> temp;
        cout << "Enter resource request for W - " << i << endl; 
        for(int j=0; j<O; j++) {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        resource_request.push_back(temp);
    }
}

void provide_uav_capacity(vector<vector<int>> &uav_capacity) {
    for(int i=0; i<M; i++) {
        vector<int> temp;
        cout << "Enter uav capacity for UAV - " << i << endl;
        for(int j=0; j<O; j++) {
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

void get_time_req_sum() {
    cout << "time required for each battle cluster" << endl;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            time_req[i] += round_trip_service_time[i][j];
        }
        cout << time_req[i] << " " << endl;
    }
}

void shortest_job_first() {
    for(int i=0; i<N; i++) {
        bool flag = 0;
        for(int j=0; j<O; j++) {
            if(resource_request[i][j]==1) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            for(int i=0; i<N; i++) {
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
            }
        }
    }
}

// void first_iteration(vector<vector<int>> &resource_request, vector<vector<int>> &uav_capacity, vector<vector<int>> &round_trip_service_time, vector<int> &time_taken) {
//     for(int i=0; i<N; i++) {
//         for(int j=0; j<M; j++) {
//             if(resource_request[i][j]==1) {
//                 if(uav_capacity[i][j]==1) {
//                     resource_request[i][j] = 0;
//                     time_taken[i] += round_trip_service_time[i][j];
//                 }
//             }
//         }
//     }
// }

// void remaining_iterations(vector<vector<int>> &resource_request, vector<vector<int>> &uav_capacity, vector<vector<int>> &round_trip_service_time, vector<int> &time_taken) {
//     for(int i=0; i<N; i++) {
//         bool flag = 0;
//         for(int j=0; j<M; j++) {
//             if(resource_request[i][j]==1) {
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag) {
//             for(int i=0; i<N; i++) {
//                 for(int j=0; j<M; j++) {
//                     if(resource_request[i][j]==1) {
//                         if(uav_capacity[i][j]==1) {
//                             resource_request[i][j] = 0;
//                             time_taken[i] += round_trip_service_time[i][j];
//                         }
//                     }
//                 }
//                 bool flag = 0;
//                 for(int j=0; j<M; j++) {
//                     if(resource_request[i][j]==1) {
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if(!flag)
//                     break;
//             }
//         }
//     }
// }

int main() {

    provide_requests(resource_request);
    provide_uav_capacity(uav_capacity);
    get_round_trip_service_time(round_trip_service_time);

    get_time_req_sum();

    sort(time_req.begin(),time_req.end());

    shortest_job_first();

    //first_iteration(resource_request, uav_capacity, round_trip_service_time, time_taken);

    //remaining_iterations(resource_request, uav_capacity, round_trip_service_time, time_taken);

    cout << "Maximum time taken = " << *max_element(time_taken.begin(), time_taken.end()) << endl;

    cout << "Time taken for each battle cluster:\n";
    for(int i=0; i<N; i++)
        cout << i << " - " << time_taken[i] << endl;

    //cout << *max_element(time_taken.begin(), time_taken.end()) << endl;
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