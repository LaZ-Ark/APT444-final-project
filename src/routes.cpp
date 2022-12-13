#include "routes.h"
#include <tuple>

std::vector<std::vector<std::string>> filesto2DV(const std::string & filename){
    std::vector<std::vector<std::string>> routes;
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
        routes.push_back(extra);
    }

    return routes;
}