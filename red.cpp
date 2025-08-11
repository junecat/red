#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// CONTAINER ID   IMAGE                        COMMAND                  CREATED         STATUS                 PORTS  NAMES

int main(){
    string line; 
    vector<string> lines;
    while ( getline(cin, line)  ){            // && !line.empty()
        lines.push_back(line);
    }
    size_t maxx = 0;
    for( auto l : lines )
        maxx = l.length()>maxx ? l.length() : maxx;

    size_t container_poz = lines[0].find("CONTAINER");
    size_t id_poz = lines[0].find("ID");
    size_t image_poz = lines[0].find("IMAGE");
    size_t command_poz = lines[0].find("COMMAND");
    size_t created_poz = lines[0].find("CREATED");
    size_t status_poz = lines[0].find("STATUS");
    size_t ports_poz = lines[0].find("PORTS");
    size_t names_poz = lines[0].find("NAMES");

    // cout << container_poz << ", "  << id_poz << ", " << image_poz << ", " << command_poz << ", " << created_poz << ", " << status_poz << ", " << ports_poz << ", " << names_poz << ", " << maxx << endl;
    
    for(auto l : lines) {
        auto x = l.substr(0, ports_poz+140) + "..." + l.substr(names_poz);
        cout << x << endl;
    }
}