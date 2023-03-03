#include "search.h"
#include <algorithm>

search::search()
{

}

bool
search::linear_search(const std::vector<int> &numbers, const int &searched_number) const
{
    for (auto &i : numbers)
        if (i == searched_number)
            return true;

    return false;
}

bool
search::binarySearch(std::vector<int> numbers, const int &searched_number) const
{
    /* It needs the array to be sorted */
    std::sort(numbers.begin(),numbers.end());

    int lo = 0, hi = numbers.size() - 1;

    while ((hi - lo) > 1) {
        int mid = (hi + lo) / 2;
        if (numbers[mid] < searched_number) {
            lo = mid + 1;
        } else if (numbers[mid] > searched_number) {
            hi = mid;
        } else if(numbers[mid] == searched_number) {
            return true;
        }
    }

    if (numbers[lo] == searched_number) {
        return true;
    } else if (numbers[hi] == searched_number) {
        return true;
    } else {
        return false;
    }
}
