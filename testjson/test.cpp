#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

string test01(){
    json js;
    js["id"] = 12;
    js["name"] = "哈基米";
    js["age"]  = 16;
    string stringjs = js.dump();
    cout << stringjs << endl;
    return stringjs;
}



int main(){
    string receiveString = test01();
    json js = json::parse(receiveString);
    cout << js["id"] << endl;
    cout << js["name"] << endl;
    cout << js["age"] << endl;
    return 0;
}


