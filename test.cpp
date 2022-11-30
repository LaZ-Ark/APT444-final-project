#include "airportsdatas.csv"
#include "routes.csv"
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

vector v = filesto2DV("routes.csv");
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

boolean routeExists(string start, string end, vector vec) {
    for (vector v: vec) {
        if (v.at(2) == start && v.at(4) == end) {
            return true;
        }
    }
    return false;
}