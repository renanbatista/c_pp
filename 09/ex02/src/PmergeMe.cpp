#include "PmergeMe.hpp"

#include <limits>
#include <stdexcept>

// Sorts the input based on the command line arguments using the appropriate container (list or
// vector).
void PmergeMe::sort(int argc, char const* argv[])
{
    for (int i = 1; i < argc; ++i) {
        char* end;
        long  val = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || val <= 0 || val > INT_MAX) {
            throw std::runtime_error("Invalid integer input. Please use positive integers only.");
        }
        _list.push_back(static_cast<int>(val));
        _vector.push_back(static_cast<int>(val));
    }
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    clock_t startTime = clock();
    mergeInsertionSort(_list);
    _timeList = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;

    startTime = clock();
    mergeInsertionSort(_vector, 0, _vector.size() - 1);
    _timeVector = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
}

// Applies a merge-insertion sort algorithm to a vector, which uses insertion sort for small
// segments.
void PmergeMe::mergeInsertionSort(std::vector<int>& vectorData, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
        return;

    if (endIndex - startIndex + 1 <= 10) {
        for (int i = startIndex + 1; i <= endIndex; ++i) {
            int currentValue = vectorData[i];
            int j = i - 1;
            while (j >= startIndex && vectorData[j] > currentValue) {
                vectorData[j + 1] = vectorData[j];
                j--;
            }
            vectorData[j + 1] = currentValue;
        }
    }
    else {
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        mergeInsertionSort(vectorData, startIndex, midIndex);
        mergeInsertionSort(vectorData, midIndex + 1, endIndex);
        merge(vectorData, startIndex, midIndex, endIndex);
    }
}

// Prints the processing time for the sorted container.
void PmergeMe::printTime(const std::string& containerType) const
{
    double time = (containerType == "list") ? _timeList : _timeVector;
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::" << containerType << " : " << std::fixed
              << std::setprecision(5) << time * 1000000 << " us" << std::endl;
}

// Applies a merge-insertion sort algorithm to a list, which uses insertion sort for small segments.
void PmergeMe::mergeInsertionSort(std::list<int>& listData)
{
    if (listData.size() <= 1)
        return;
    if (listData.size() <= 10) {
        insertionSort(listData);
    }
    else {
        std::list<int>           left, right;
        std::list<int>::iterator it = listData.begin();
        std::advance(it, listData.size() / 2);
        left.splice(left.begin(), listData, listData.begin(), it);
        right.splice(right.begin(), listData, it, listData.end());

        mergeInsertionSort(left);
        mergeInsertionSort(right);
        merge(listData, left, right);
    }
}

// Implements insertion sort for the list, used for small segments in merge-insertion sort.
void PmergeMe::insertionSort(std::list<int>& dataList)
{
    if (dataList.empty())
        return;

    for (std::list<int>::iterator it = ++dataList.begin(); it != dataList.end();
         /* increment inside */) {
        int                      currentValue = *it;
        std::list<int>::iterator position = it;
        std::list<int>::iterator prev = position;
        --prev;

        // Move the element to its correct position
        while (position != dataList.begin() && *prev > currentValue) {
            *position = *prev;  // Shift the element right
            position = prev;
            --prev;
        }

        // Insert the element at the correct position
        *position = currentValue;

        // Move iterator to the next element
        it = position;
        ++it;
    }
}

// Merges two halves of a list into a single sorted list.
void PmergeMe::merge(std::list<int>& resultList, std::list<int>& leftList,
                     std::list<int>& rightList)
{
    resultList.clear();
    std::list<int>::iterator leftIt = leftList.begin();
    std::list<int>::iterator rightIt = rightList.begin();

    while (leftIt != leftList.end() && rightIt != rightList.end()) {
        if (*leftIt <= *rightIt) {
            resultList.push_back(*leftIt++);
        }
        else {
            resultList.push_back(*rightIt++);
        }
    }

    resultList.insert(resultList.end(), leftIt, leftList.end());
    resultList.insert(resultList.end(), rightIt, rightList.end());
}

// Merges two sorted segments of a vector into one sorted segment.
void PmergeMe::merge(std::vector<int>& vectorData, int leftStart, int middleIndex, int rightEnd)
{
    int              numLeft = middleIndex - leftStart + 1;
    int              numRight = rightEnd - middleIndex;
    std::vector<int> left(numLeft), right(numRight);

    for (int i = 0; i < numLeft; ++i)
        left[i] = vectorData[leftStart + i];
    for (int i = 0; i < numRight; ++i)
        right[i] = vectorData[middleIndex + 1 + i];

    int i = 0, j = 0, k = leftStart;
    while (i < numLeft && j < numRight) {
        if (left[i] <= right[j]) {
            vectorData[k++] = left[i++];
        }
        else {
            vectorData[k++] = right[j++];
        }
    }

    while (i < numLeft) {
        vectorData[k++] = left[i++];
    }
    while (j < numRight) {
        vectorData[k++] = right[j++];
    }
}

void PmergeMe::printData() const
{
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    printTime("list");
    printTime("vector");
}