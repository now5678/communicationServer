#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void test01(){
    json js;
    js["id"] = 12;
    js["name"] = "哈基米";
    js["age"]  = 16;
    cout << js << endl;
}



int main(){
    test01();
    return 0;
}


