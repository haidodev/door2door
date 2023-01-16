#include<iostream>
#include<vector>
using namespace std;
vector<int> generate_permutation(int n){
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) permutation[i] = i + 1;
    for (int i = 0; i < n; ++i) swap(permutation[i], permutation[rand() % n]);
    return permutation;
}
class Technician{
public:
    Technician();
    void add_point(int point);
    void print_route();
private:
    vector<int> route;
};
Technician::Technician() {
}
void Technician::add_point(int point){
    (this -> route).push_back(point);
}
void Technician::print_route(){
    for (int point : this -> route){
        cout << point;
        if (point != this -> route.back()) cout << " -> ";
    }
    cout << endl;
}
void assign_route(vector<int>& route, vector<Technician>& technicians, int num_of_points){
    int current_technician = 0;
    for (int point : route) {
        if (point > num_of_points) {
            ++current_technician;
            continue;
        }
        technicians[current_technician].add_point(point);
    }
}
int main(){
    srand(time(NULL));
    int num_of_technicians = 2, num_of_points = 10;
    vector<int> init_route = generate_permutation(num_of_points + num_of_technicians - 1);
    vector<Technician> technicians(num_of_technicians);
    assign_route(init_route, technicians, num_of_points);
    for (Technician tech : technicians){
        tech.print_route();
    }
}