#ifndef RECORD_HPP
#define RECORD_HPP

#include <vector>

class Record
{
public:
    Record(int n):x_list(n), mu_list(n){}
    std::vector<double> x_list;
    std::vector<double> mu_list;
};

#endif