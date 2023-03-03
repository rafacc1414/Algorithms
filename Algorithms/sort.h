#ifndef SORT_H
#define SORT_H

#include <vector>

class sort
{
public:
    sort();

    template <class T> void
    buble_sort(std::vector<T> &elements) const
    {
        for (int i = 0; i < (int) elements.size() - 1; ++i) {
            for (int j = elements.size() - 1; i < j; j--) {
                if(elements[j] < elements[j - 1]) {
                    std::swap(elements[j], elements[j - 1]);
                }
            }
        }
    };
};

#endif // SORT_H
