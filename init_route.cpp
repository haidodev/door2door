#include<iostream>
#include<vector>
#include<fstream>
#define NUM_OF_TECHNICIANS 2
#define NUM_OF_POINTS 5
#define MAX_P 100
#define SPEED 5

using namespace std;

double graph[MAX_P][MAX_P];
vector<int> generate_permutation(int n){
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) permutation[i] = i + 1;
    for (int i = 0; i < n; ++i) swap(permutation[i], permutation[rand() % n]);
    return permutation;
}
void read_graph(){
    ifstream fi("graph.txt");
    int n;
    fi >> n;
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            fi >> graph[i][j];
        }
    }
}
class Technician{
public:
    double total_wait_time;
    Technician();
    void add_point(int point);
    void print_route();
    void end_route();
private:
    vector<int> route;
    double evaluate_wait_time();
};

Technician::Technician() {
    (this -> route).push_back(0);
}
void Technician::add_point(int point){
    (this -> route).push_back(point);
}
void Technician::end_route(){
    (this -> route).push_back(0);
    this -> total_wait_time = this -> evaluate_wait_time();

}
void Technician::print_route(){
    int cnt_point = 0;
    for (int point : this -> route){
        if (cnt_point++ > 0) cout << " -> ";
        cout << point;
    }
    cout << "\tTOTAL WAIT TIME: " << this -> total_wait_time <<endl;
}
double Technician::evaluate_wait_time(){
    double total_distance = 0;
    int n = (this -> route).size() - 1;
    for (int i = 1; i < n ; ++i) total_distance += i * graph[(this -> route)[i]][(this -> route)[i + 1]];
    return total_distance / SPEED;
}

class Solution{
public:
    double objective_value;
    Solution();
    void show_solution();
private:
    vector<int> route;
    vector<Technician> technicians;
    double evaluate_objective_value();
    void assign_route();
};
Solution::Solution(){
    this -> route = generate_permutation(NUM_OF_POINTS + NUM_OF_TECHNICIANS - 1);
    assign_route();
    this -> objective_value = evaluate_objective_value();
}
void Solution::assign_route(){
    Technician tmp_technician = Technician();
    for (int point : this -> route) {
        if (point > NUM_OF_POINTS) {
            tmp_technician.end_route();
            (this -> technicians).push_back(tmp_technician);
            tmp_technician = Technician();
            continue;
        }
        tmp_technician.add_point(point);
    }
    tmp_technician.end_route();
    (this -> technicians).push_back(tmp_technician);
}
double Solution::evaluate_objective_value(){
    double value = 0;
    for (Technician tech : this -> technicians) value += tech.total_wait_time;
    return value;
}
void Solution::show_solution(){
    for (Technician tech : this -> technicians) tech.print_route();
    cout << "OBJECTIVE VALUE: " << this -> objective_value << endl;
}
int main(){
    srand(time(NULL));
    read_graph();
    vector<int> init_route = generate_permutation(NUM_OF_POINTS + NUM_OF_TECHNICIANS - 1);
    Solution sol1 = Solution();
    sol1.show_solution();
}