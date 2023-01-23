#include"init.h"
#include "technicians.h"
#include "solution.h"

int main(){
    srand(time(NULL));
    read_graph();
    Solution sol1 = Solution();
    sol1.show_solution();
    for (int i = 0; i < 5; ++i){
        sol1.local_search();
        sol1.show_solution();
    }
}