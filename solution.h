class Solution{
public:
    double objective_value;
    Solution();
    Solution(vector<Technician> technicians);
    void show_solution();
    Solution swap_segment_and_point();
    Solution insert_segment_after_point();
private:
    vector<int> route;
    vector<Technician> technicians;
    double evaluate_objective_value();
    void assign_route();
};
Solution::Solution(){
    this -> route = generate_permutation(num_of_points + NUM_OF_TECHNICIANS - 1);
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
        if (point > num_of_points) {
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
Solution Solution::swap_segment_and_point(){
    int idx = rand_range((this -> technicians).size());
    vector<Technician> new_technicians = this -> technicians;
    new_technicians[idx] = new_technicians[idx].swap_segment_and_point();
    return Solution(new_technicians);
}
Solution Solution::insert_segment_after_point(){
    int idx = rand_range((this -> technicians).size());
    vector<Technician> new_technicians = this -> technicians;
    new_technicians[idx] = new_technicians[idx].insert_segment_after_point();
    return Solution(new_technicians);
}
