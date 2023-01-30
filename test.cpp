#include<iostream>
#include<vector>
using namespace std;
class DataType{
public:
    vector<int> tmp;
    DataType(vector<int> tmp);
    void show();
};
DataType::DataType(vector<int> tmp){
    this -> tmp = tmp;
}
void DataType::show(){
    for (int elm : (this -> tmp)) cout << elm << " ";
    cout << endl;
}
void show_array(vector<int> tmp){
    for (int elm : tmp) cout << elm << " ";
    cout << endl;
}
void test1(){
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);

    DataType d = DataType(tmp);
    d.show();
    d.tmp[2] = 10;
    tmp.push_back(3);
    tmp.push_back(3);
    show_array(tmp);
    d.show();
}
void test2(){
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);
    show_array(tmp);
    vector<int> tmp_clone = tmp;
    tmp_clone[2] = 5;
    show_array(tmp);
    show_array(tmp_clone);
}
int main(){
    test2();
}