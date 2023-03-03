#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

class search
{
public:
    search();
    bool linear_search(const std::vector<int> &numbers, const int &searched_number) const;
    bool binarySearch(std::vector<int> numbers, const int &searched_number) const;
};

#endif // SEARCH_H
