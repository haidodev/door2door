#include<iostream>
#include<vector>
#include<fstream>
#define NUM_OF_TECHNICIANS 2
#define NUM_OF_POINTS 5
#define MAX_P 100
#define SPEED 5

using namespace std;
double graph[MAX_P][MAX_P];
int num_of_points;
int rand_range(int lowbound, int upbound = -1){
    if (upbound == -1) return rand_range(0, lowbound);
    return rand() % (upbound - lowbound) + lowbound;
}
vector<int> generate_permutation(int n){
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) permutation[i] = i + 1;
    for (int i = 0; i < n; ++i) swap(permutation[i], permutation[rand_range(n)]);
    return permutation;
}
void read_graph(){
    ifstream fi("graph.txt");
    int n;
    fi >> num_of_points;
    for (int i = 0; i <= num_of_points; ++i){
        for (int j = 0; j <= num_of_points; ++j){
            fi >> graph[i][j];
        }
    }
}