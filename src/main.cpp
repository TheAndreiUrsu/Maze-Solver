//
// Created by ebrinza on 11/17/2023.
//

#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> d;

    string key = to_string(0) + "," + to_string(0);

    d[key] = 0;
    d["1,0"] = d[key] + 1;
    d["2,0"] = d["1,0"] + 1;
    d["2,1"] = d["2,0"] + 1;
    d["2,2"] = d["2,1"] + 1;
    d["1,2"] = d["2,2"] + 1;
    d["0,2"] = d["1,2"] + 1;

    for(auto& node : d)
        cout <<  node.first << " | " << node.second << endl;


    return 0;
}
