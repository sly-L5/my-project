#include <iostream>
#include <vector>
#include <cmath>

void printSortedByAbsoluteValue(const std::vector<int>& arr) {
    int n = arr.size();
    int right = 0;


    while (right < n && arr[right] < 0) {
        right++;
    }

    int left = right - 1;


    std::vector<int> result;
    result.reserve(n);


    while (left >= 0 && right < n) {
        if (std::abs(arr[left]) <= std::abs(arr[right])) {
            result.push_back(arr[left]);
            left--;
        } else {
            result.push_back(arr[right]);
            right++;
        }
    }


    while (left >= 0) {
        result.push_back(arr[left]);
        left--;
    }


    while (right < n) {
        result.push_back(arr[right]);
        right++;
    }


    for (int i = 0; i < n; ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {-100, -50, -5, 1, 10, 15};
    printSortedByAbsoluteValue(arr);
    return 0;
}