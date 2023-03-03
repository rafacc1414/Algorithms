#include <iostream>
#include <vector>
#include <chrono>
#include "search.h"
#include "sort.h"

/* Random numbers to find */
std::vector<int> numbers = { 99,55,6,2,8,2,1,5,7,-8,-5,9,-2,-8,-100,100,155,155,155,-9};

/* Number to search in the tests */
int searched_number = 5;

template <class T>
void print_vector(std::vector <T> elements)
{
    std::cout << "[ ";
    for (auto &i : elements) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test_linear_search ()
{

    std::cout << "Test Linear Search" << std::endl;

    search searcher;

    auto start = std::chrono::high_resolution_clock::now();
    int result = searcher.linear_search(numbers, searched_number);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    if (result) {
        std::cout << "The number " << searched_number << " has been found" << std::endl;
    } else {
        std::cout << "Number "<< searched_number << " not found" << std::endl;
    }
    std::cout << "Execution Time: " << duration.count() << "ns" << std:: endl;
    std::cout << std::endl;
}

void test_binary_search ()
{

    std::cout << "Test Binary Search" << std::endl;

    search searcher;

    auto start = std::chrono::high_resolution_clock::now();
    int result = searcher.binarySearch(numbers, searched_number);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    if (result) {
        std::cout << "The number " << searched_number << " has been found" << std::endl;
    } else {
        std::cout << "Number "<< searched_number << " not found" << std::endl;
    }

    std::cout << "Execution Time: " << duration.count() << "ns" << std:: endl;
    std::cout << std::endl;
}

void test_buble_sort ()
{

    std::cout << "Test Buble Sort" << std::endl;

    std::vector <int> numbers_buble = numbers;
    sort sorter;
    auto start = std::chrono::high_resolution_clock::now();
    sorter.buble_sort(numbers_buble);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    print_vector(numbers_buble);
    std::cout << "Execution Time: " << duration.count() << "ns" << std:: endl;
    std::cout << std::endl;
}

int main()
{

      /* Generate random numbers */
//    for (int i = 0; i < 100000; ++i) {
//        numbers.push_back(std::rand() % 10000);
//    }

    std::cout << "List of numbers to work with: " << std::endl;
    print_vector(numbers);
    std::cout << std::endl;

    test_linear_search();
    test_binary_search();
    test_buble_sort();

    return 0;
}
