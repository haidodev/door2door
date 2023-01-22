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
int main(){
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);

    DataType d = DataType(tmp);
    d.show();
    d.tmp[2] = 10;
    tmp.push_back(3);
    tmp.push_back(3);
    for (int elm : tmp) cout << elm << " ";
    cout << endl;
    d.show();
}