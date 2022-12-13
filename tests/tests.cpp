#include "../includes/node.h"
#include "../includes/routes.h"
#include "../includes/parse.h"
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 
#include <stdexcept>
typedef bool boolean;

using namespace std;

boolean routeExists(string start, string end, std::vector<std::vector<std::string>> vec) {
    for (std::vector<std::string> v: vec) {
        if (v.at(2) == start && v.at(4) == end) {
            return true;
        }
    }
    return false;
}

std::vector<std::vector<std::string>> v = filesto2DV("routes.csv");
enum cols { START = 2, DEST = 4};

TEST_CASE("readRoutesCSV", "[part1]") {
    REQUIRE(v.at(0).at(START) == "AER");
    REQUIRE(v.at(19465).at(START) == "YNJ");
    REQUIRE(v.at(10).at(DEST) == "KZN");
    REQUIRE(v.at(51122).at(DEST) == "ODS");
    REQUIRE(v.at(12051).at(START) != "AGA");
    REQUIRE(v.at(11654).at(DEST) != "NFG");
}

TEST_CASE("checkRouteMatches") {
    REQUIRE(routeExists("LUZ", "GDN", v));
    REQUIRE(!routeExists("NLC", "ICK", v));
}

TEST_CASE("A Star") {
    Node *n = new Node("./data/airportsdatas.csv", "./data/routes.csv", "CMI");
    std::vector<std::string> user = n->AStarAlgo("PNS");
    std::vector<std::string> answer;
    answer.push_back("CMI");
    answer.push_back("ORD");
    answer.push_back("PNS");
    REQUIRE(user == answer);
}
