#include<vector>
#include<iostream>
#include<fstream>
#define MAX_DIS 18
#define MIN_DIS 3
#define MAX_P 100
using namespace std;
int main(){
    ofstream fo("graph.txt");
    srand(time(NULL));
    int n = 10;
    double graph[MAX_P][MAX_P];
    for (int i = 0; i <= n; ++i){
        graph[i][i] = 0;
        for (int j = i + 1; j <= n; ++j){
            graph[i][j] = rand() % (MAX_DIS - MIN_DIS) + MIN_DIS;
            graph[j][i] = graph[i][j];
        }
    }
    fo << n << "\n";
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            fo << graph[i][j] << "\t";
        }
        fo << endl;
    }

}