#include"init.h"
#include "technicians.h"
#include "solution.h"

int main(){
    srand(time(NULL));
    read_graph();
    Solution sol1 = Solution();
    sol1.show_solution();
    for (int i = 0; i < 5; ++i){
        Solution sol2 = sol1.insert_segment_after_point();
        sol2.show_solution();
    }
    for (int i = 0; i < 10; ++i){
        Solution sol2 = sol1.swap_segment_and_point();
        sol2.show_solution();
    }
}