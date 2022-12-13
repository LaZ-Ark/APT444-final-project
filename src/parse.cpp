#include "parse.h"

std::vector<std::vector<std::string>> fileto2DV(const std::string & filename){
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