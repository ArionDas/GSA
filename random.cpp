#include<bits/stdc++.h>
using namespace std;
const int N = 6; //battle clusters
const int M = 8; //types of resources

vector<vector<int>> resource_request;
vector<vector<int>> uav_capacity;
vector<vector<int>> round_trip_service_time(N, vector<int>(N,0));
vector<int> time_taken(N,0);
unordered_map<int,int> um;


int generateRandomInt() {
    int y = rand() % 100;
    //cout << y << " ";
    return y;
}

int generateRandom() {
    int y = rand() % N+1;
    cout << y << " hey ";
    return y;
}

int genRan() {
    int y = rand() % M+1;
    cout << y << " hi ";
    return y;
    //cout << "hi\n";
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
        // vector<int> temp;
        // cout << "Enter uav capacity for UAV - " << i << endl;
        for(int j=0; j<M; j++) {
            uav_capacity[i][j]=1;
        }
        //uav_capacity.push_back(temp);
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

int iterations(vector<vector<int>> &resource_request, vector<vector<int>> &round_trip_service_time) {
    int count = 0, total_time = 0;

    while(count<N) {
        int ran = generateRandom();
        if(um.find(ran)==um.end()) {
            //continue;
        cout << "count = " << count << endl;
        int ran_uav = genRan();
        //if(ran_uav==0) continue;
        um[ran]++;
        count += 1;
        //for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(resource_request[ran][j]==1)
                    total_time += round_trip_service_time[ran_uav-1][ran-1];
            }
        //}
        }
    }

    return total_time;
}


int main() {

    provide_requests(resource_request);
    //provide_uav_capacity(uav_capacity);
    get_round_trip_service_time(round_trip_service_time);

    //first_iteration(resource_request, uav_capacity, round_trip_service_time, time_taken);

    int time_req = iterations(resource_request, round_trip_service_time);

    cout << time_req << endl;
}


/*

INPUT:
1 1 1 0 0 1 0 0
1 1 0 0 1 0 0 1
0 1 1 1 0 1 1 0
0 0 1 1 1 1 1 1
1 0 0 1 1 0 1 1
0 0 1 1 0 0 0 1

OUTPUT:
236
*/