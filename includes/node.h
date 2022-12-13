#ifndef node_h
#define node_h
#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include "util.h"
#include <algorithm>
#include <fstream>

using namespace std;

class Node {
    public:
        Node(const std::string & airportfile, const std::string & routefile, std::string air);

        double Getdistance(std::string one, std::string two);
        std::vector<std::string> GetRoutes(const std::string & filename, std::string air);
        void GetAirports(const std::string & airportfile);
        void FillMatrix();
        std::vector<std::string> AStarAlgo(std::string air);
        std::vector<std::string> BFS(std::string air);
        void Final(std::string a, std::string b);

    private:

        std::string airport_;
        std::vector<std::vector<std::string>> airports;
        // std::vector<std::string> airportonly;
        std::vector<std::string> connections_;
        std::vector<double> distance_;
        std::vector<double> heuristic_;
        std::vector<std::vector<double>> matrix_;
        
        
        std::vector<std::vector<std::string>> to2DV(const std::string & filename);


};

#endif