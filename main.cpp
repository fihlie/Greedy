#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
int main(int argc, char* argv[]) {
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    vector<pair<pair<double,double>,pair<double,int>>> v;
    int N;
    int M;
    inFile>> N;
    inFile>> M;
    for(int i=0;i<N;i++){
        double value;
        double cost;
        inFile>> value;
        inFile>> cost;
        v.push_back(make_pair(make_pair(value,cost),make_pair(value/cost,i+1)));
    }
    for(int i=1;i<N;i++){
        for(int j=i-1;j>=0;j--){
            if(v[j+1].second.first>v[j].second.first){
                auto x= v[j];
                v[j]=v[j+1];
                v[j+1]=x;
            }
            else{
                break;
            }
        }
    }
    int total;
    total=0;
    int count;
    count=0;
    for(int i=0;i<N;i++){
        if(M-v[i].first.second>=0){
            M-=v[i].first.second;
            total+=v[i].first.first;
            outFile<<v[i].second.second<<" "<<v[i].first.first<<" "<<v[i].first.second<<endl;
        }
    }
    outFile<<"Total Profit: "<<total;
}