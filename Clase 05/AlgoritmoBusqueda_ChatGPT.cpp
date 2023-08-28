#include <iostream>
#include <vector>
#include <algorithm>

// Función para realizar búsqueda secuencial y contar comparaciones
int sequentialSearch(const std::string& str, char target, int& comparisons) {
    int count = 0;
    for (int i = 0; i < str.size(); ++i) {
        comparisons++;
        if (str[i] == target) {
            count++;
        }
    }
    return count;
}

// Función para realizar búsqueda binaria y contar comparaciones
int binarySearch(const std::string& str, char target, int& comparisons) {
    int left = 0, right = str.size() - 1, count = 0;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (str[mid] == target) {
            count++;
            break;
        } else if (str[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> strings(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> strings[i];
    }

    for (const std::string& str : strings) {
        char uniqueChar;
        int sequentialComparisons = 0, binaryComparisons = 0;

        // Find the unique character
        for (int i = 0; i < str.size(); i += 2) {
            if (i == str.size() - 1 || str[i] != str[i + 1]) {
                uniqueChar = str[i];
                break;
            }
        }

        int sequentialCount = sequentialSearch(str, uniqueChar, sequentialComparisons);
        int binaryCount = binarySearch(str, uniqueChar, binaryComparisons);

        std::cout << uniqueChar << " " << sequentialComparisons << " " << uniqueChar << " " << binaryComparisons << std::endl;
    }

    return 0;
}
