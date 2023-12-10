#include <iostream>
using namespace std;
#include <sstream>
#include <string>

int main() {

 stringstream stream;
int num=9;
    stream << num;
     string str;

    stream >> str;
    cout<<str;
    stringstream ss;
    ss << str;
    int x;
    ss>>x;
    cout<<x;
    
}
