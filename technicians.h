class Technician{
public:
    double total_wait_time;
    Technician();
    Technician(vector<int> route);
    void add_point(int point);
    void print_route();
    void end_route();
    Technician local_search();
private:
    vector<int> route;
    double evaluate_wait_time();
};

Technician::Technician() {
    (this -> route).push_back(0);
}
Technician::Technician(vector<int> route) {
    this -> route = route;
    this -> total_wait_time = this -> evaluate_wait_time();
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
Technician Technician::local_search(){
    int route_len = (this -> route).size();
    if (route_len < 5) return *this;
    int segment[] = {rand_range(1, route_len - 2), -1}, point = rand_range(1, route_len - 1);
    segment[1] = segment[0] + 1;
    while (point == segment[0] || point == segment[1]) {
        point = rand_range(1, route_len);
    }
    vector<int> new_route;
    if (segment[0] < point) {
        for (int i = 0; i < segment[0]; ++i){
            new_route.push_back((this -> route)[i]);
        }
        new_route.push_back((this -> route)[point]);
        for (int i = segment[1] + 1; i < point; ++i){
            new_route.push_back((this -> route)[i]);
        }
        new_route.push_back((this -> route)[segment[0]]);
        new_route.push_back((this -> route)[segment[1]]);
        for (int i = point + 1; i < route_len; ++i){
            new_route.push_back((this -> route)[i]);
        }
    }
    else {
        for (int i = 0; i < point; ++i){
            new_route.push_back((this -> route)[i]);
        }
        new_route.push_back((this -> route)[segment[0]]);
        new_route.push_back((this -> route)[segment[1]]);
        for (int i = point + 1; i < segment[0]; ++i){
            new_route.push_back((this -> route)[i]);
        }
        new_route.push_back((this -> route)[point]);
        for (int i = segment[1] + 1; i < route_len; ++i){
            new_route.push_back((this -> route)[i]);
        }
    }
    return Technician(new_route);

}