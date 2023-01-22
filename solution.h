class Solution{
public:
    double objective_value;
    Solution();
    Solution(vector<Technician> technicians);
    void show_solution();
    void local_search();
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
Solution::Solution(vector<Technician> technicians){
    this -> technicians = technicians;
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
    cout << "OBJECTIVE VALUE: " << this -> objective_value << endl << endl;
}
void Solution::local_search(){
    int idx = rand_range((this -> technicians).size());
    this -> objective_value -= (this -> technicians)[idx].total_wait_time; 
    (this -> technicians)[idx] = (this -> technicians)[idx].local_search();
    this -> objective_value += (this -> technicians)[idx].total_wait_time; 

}
