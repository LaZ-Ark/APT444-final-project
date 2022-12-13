#include <iostream>
#include "util.h"
#include "parse.h"
#include "routes.h"
#include "node.h"

int main() {
    std::string first = "CMI";
    std::string second = "LAX";
    //Parameter to have the two datasets, and the source/current airport. 
    Node *n = new Node("./data/airportsdatas.csv", "./data/routes.csv", first);

    //Parameter to have the destination airport
    std::vector<std::string> to_print = n->AStarAlgo(second);
    cout << "Path from " << to_print[0] << " to " << to_print[to_print.size()-1] << endl;
    cout << to_print[0];
    for (unsigned i = 1; i < to_print.size(); ++i) {
        std::cout << " --> " << to_print.at(i);
    }
    cout << " " << endl;

    return 0;
}