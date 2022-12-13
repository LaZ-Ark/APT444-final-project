#include "node.h"
#include "routes.h"
#include "parse.h"
#include <cmath>
#include <string>
#include <float.h>
#include <algorithm>
using namespace std;

// Converting the data set, into a parsed String File
void Node::GetAirports(const std::string & airportfile) {
    std::vector<std::vector<std::string>> airportscheck;
    airportscheck = to2DV(airportfile);
    for (unsigned int i = 0; i < airportscheck.size(); ++i) {
        // if (airportscheck[i][3] == "\"United States\"") {
        //     // Can change the country name, to find the airport connections for any other country. All countries in the world are supported. 
        //     airports.push_back(airportscheck[i]);
        // }
        airports.push_back(airportscheck[i]);
        
        // Comment previous line and uncomment the if loop, to add a country filter from the data set. 
    }
}
// Constructor to store the data for each node(airport in this case) of the graph
// Each and every airport of the dataset that is being used will have its own unique collection of data, and its routes attached to it.
Node::Node(const std::string & airportfile, const std::string & routefile, std::string air) {
    airport_ = air;
    std::vector<std::string> connections;
    GetAirports(airportfile);
    connections = GetRoutes(routefile, air);
    
    for (unsigned i = 0; i < connections.size(); ++i) {
        distance_.push_back(Getdistance(air, connections_[i]));
    }
    // FillMatrix();
    // cout << "Check complete" << endl;
    // Final ("LAX", "ORD");
}
// Printing out the output of the Floyd - Warshall Algorithm 
void Node::Final(std::string a, std::string b) {
    unsigned x,y;
    if (a[0] != '"') {
        a = '"' + a + '"';
        b = '"' + b + '"';
    }
    unsigned counter = airports.size();
    for (unsigned i = 0; i < counter; ++i) {
        if (airports[i][4] == a) {
            x = i;
        }
        if (airports[i][4] == b) {
            y = i;
        }
    }
    // Floyd - Warshall output
    cout << x << " " << y << endl;
    cout << "Value = " << matrix_[x][y] << endl;
}
// Implementation of the Floyd - Warshall Algorithm, by setting a N*N matrix, with its connected distances for the current node. 
void Node::FillMatrix() {
    std::vector<std::string> con;
    for(unsigned i = 0; i < connections_.size(); ++i) {
        std::string a = connections_[i];
        a = '"' + a + '"';
        con.push_back(a);
    }
    unsigned count = airports.size();
    int check = 0;
    for (unsigned i = 0; i < count; ++i) {
        std::vector<double> parse;
        for (unsigned j = 0; j < count; ++j) {
            if (i!=j) {
                check = 0;
                for (unsigned k = 0; k < con.size(); ++k) {
                    if (airports[j][4] == con[k]) {
                        parse.push_back(Getdistance(airport_, con[k]));
                        check = 1;
                    }
                }
                if (check == 0) {
                    parse.push_back(DBL_MAX);
                }
            } else {
                parse.push_back(0.0);
            }
        }
        // For entertainment, as the implementation of the code is really long. 
        // cout << i << endl;
        matrix_.push_back(parse);
    }
    
    for (unsigned k = 0; k < count; ++k) {
        for (unsigned i = 0; i < count; ++i) {
            for (unsigned j = 0; j < count; ++j) {
                matrix_[i][j] = std::min(matrix_[i][j], matrix_[i][k] + matrix_[k][j]);
            }
        }
        // For entertainment, as the implementation of the code is really long. 
        cout << k << endl;
    }
    // Floyd - Warshall Code Implementation check, by printing out the final matrix obtained. 
    // for (unsigned i = 0; i < count; ++i) {
    //     for (unsigned j = 0; j < count; ++j) {
    //         cout << matrix_[i][j] << " ";
    //     }
    //     cout << " " << endl;
    // }
    
}
// Parsing the data of the dataset 
std::vector<std::vector<std::string>> Node::to2DV(const std::string & filename){
    std::vector<std::vector<std::string>> data_;
    std::string alldata = file_to_string(filename);
    std::vector<std::string> rows;
    SplitString(alldata, '\n', rows);

    for (unsigned i = 0; i < rows.size(); ++i) {
        std::vector<std::string> eachrow;
        SplitString(rows[i], ',', eachrow);
        std::vector<std::string> extra;
        for (unsigned j = 0; j < eachrow.size(); ++j) {
            std::string s = Trim(eachrow[j]);
            extra.push_back(s); 
        }
        data_.push_back(extra);
    }

    return data_;
}
//To find all the available direct routes from the given airport
std::vector<std::string> Node::GetRoutes(const std::string & filename, std::string air) {
    std::vector<std::vector<std::string>> allroute;
    allroute = to2DV(filename);
    for (unsigned i = 0 ; i < allroute.size(); ++i) {
        if (allroute[i][2] == air) {
            for (unsigned j = 0; j < airports.size(); ++j) {
                std::string abc = allroute[i][4];
                abc = '"' + abc + '"'; 
                if (airports[j][4] == abc) {
                    connections_.push_back(allroute[i][4]);
                }
            }
        }
    }
    return connections_;
}
//To Calculate the distance between any two airports
double Node::Getdistance(std::string one, std::string two) {
    one = '"'+one+'"';
    two = '"'+two+'"';
    std::string a1, b1, a2, b2;
    for (unsigned i = 0; i < airports.size(); ++i) {
        if (airports[i][4] == one) {
            a1 = airports[i][6];
            b1 = airports[i][7];
        }
        if (airports[i][4] == two) {
            a2 = airports[i][6];
            b2 = airports[i][7];
        }
    }
    double x1;
    double x2;
    double y1;
    double y2;
    int x = 0;
    int y = 1;
    int first = 0, second = 0, third = 0, fourth = 0;
    // To tackle different situations and different hemispheres, (especially negative lattitudes and longitudes)
    for (char ch : a1) {
        int a = (int)ch;
        if (a >= 48 && a <= 57) {
            if (x == 0) {
                x1 = (x1*10) + a - 48;
            } else {
                x1 = x1 + (a-48)/(pow(10,y));
                y++;
            }
        } else if (a == 45) {
            first = 1;
        } else {
            x = 1;
        }
    }
    x = 0;
    y = 1;
    for (char ch : b1) {
        int a = (int)ch;
        if (a >= 48 && a <= 57) {
            if (x == 0) {
                y1 = (y1*10) + a - 48;
            } else {
                y1 = y1 + (a-48)/(pow(10,y));
                y++;
            }
        } else if (a == 45) {
            third = 1;
        } else {
            x = 1;
        }
    }
    x = 0;
    y = 1;
    for (char ch : a2) {
        int a = (int)ch;
        if (a >= 48 && a <= 57) {
            if (x == 0) {
                x2 = (x2*10) + a - 48;
            } else {
                x2 = x2 + (a-48)/(pow(10,y));
                y++;
            }
        } else if (a == 45) {
            second = 1;
        } else {
            x = 1;
        }
    }
    x = 0;
    y = 1;
    for (char ch : b2) {
        int a = (int)ch;
        if (a >= 48 && a <= 57) {
            if (x == 0) {
                y2 = (y2*10) + a - 48;
            } else {
                y2 = y2 + (a-48)/(pow(10,y));
                y++;
            }
        } else if (a == 45) {
            fourth = 1;
        } else {
            x = 1;
        }
    }

    double lat,lon;
    if (first == second) {
        lat = abs(x2-x1);
    } else {
        lat = abs(x2+x1);
    }

    if (third == fourth) {
        lon = abs(y2-y1);
    } else {
        lon = abs(y2+y1);
    }
    
    double toret = ((lat*lat) + (lon*lon));
    return toret;
}
// Implementation of the AStar Algo
std::vector<std::string> Node::AStarAlgo(std::string goal) {
    std::vector<std::string> to_return;
    to_return.push_back(airport_);
    if (airport_ == goal) {
        return to_return;
    }
    for (unsigned i = 0; i < connections_.size(); i++) {
       // cout << i << endl;
        double d = Getdistance(connections_.at(i), goal);
        if (d == 0) {
            to_return.push_back(goal);
            return to_return;
        }
        heuristic_.push_back(d + distance_.at(i));
    }
    double f = heuristic_.at(0);
    int index = 0;
    // To set up the heuristics
    for (unsigned i = 1; i < heuristic_.size(); i++) {
        if (heuristic_.at(i) < f) {
            index = (int) i;
            f = heuristic_.at(i);
        }
    }
    std::string connect = connections_[index];
    
    airport_ = connect;
    distance_.clear();
    connections_.clear();
    std::vector<std::string> extras = GetRoutes("./data/routes.csv", connect);
    for (unsigned i = 0; i < connections_.size(); ++i) {
        distance_.push_back(Getdistance(connect, connections_[i]));
    }
    heuristic_.clear();
    // Recursion to find the next connected airport (the closest) to reach the final destination
    std::vector<std::string> loop = AStarAlgo(goal);
    to_return.insert(to_return.end(), loop.begin(), loop.end());
    return to_return;
}

