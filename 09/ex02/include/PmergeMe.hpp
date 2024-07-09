#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

class PmergeMe {
    private:
        std::list<int>   _list;
        std::vector<int> _vector;
        double           _timeList;
        double           _timeVector;

        void mergeInsertionSort(std::list<int>& lst);
        void insertionSort(std::list<int>& lst);
        void merge(std::list<int>& lst, std::list<int>& left, std::list<int>& right);

        void mergeInsertionSort(std::vector<int>& arr, int left, int right);
        void merge(std::vector<int>& arr, int left, int mid, int right);

    public:
        PmergeMe() : _timeList(0), _timeVector(0) {}
        void printData() const;
        void sort(int argc, char const* argv[]);
        void printTime(const std::string& type) const;
};

#endif
