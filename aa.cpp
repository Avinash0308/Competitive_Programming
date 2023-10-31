#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

std::vector<int> findServer(int n, std::vector<int>& arrival, std::vector<int>& burstTime) {
    int m = arrival.size();
    vector<pair<pair<int,int>,int>> v(m);
    for(int i = 0; i<m; i++){
        v[i] = {{arrival[i],i},burstTime[i]};
    }

    sort(v.begin(),v.end());
    set<int> avi;
    set<pair<int,int>> bus;
    vector<int> res(m);
    for(int i = 1; i<=n; i++){
        avi.insert(i);
    }
    for(int i = 0; i<m; i++){
        int ind = v[i].first.second;
        int ari = v[i].first.first, bur = v[i].second;
        set<pair<int,int>> :: iterator it = bus.begin();
        while(!bus.empty() && (*it).first <= ari){
            avi.insert((*it).second);
            bus.erase(it);
            it = bus.begin();
        }
        if(avi.empty()){
            res[ind] = -1;
        }
        else{
            set<int> :: iterator itt = avi.begin();
            int val = *itt;
            avi.erase(itt);
            res[ind] = val;
            bus.insert({ari + bur,val});
        }
    }
    return res;
}

int main() {
    int n = 2;
    std::vector<int> arrival = {2, 2, 2, 3};
    std::vector<int> burstTime = {1, 3, 1, 2};

    std::vector<int> result = findServer(n, arrival, burstTime);

    std::cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
