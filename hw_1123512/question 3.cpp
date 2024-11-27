// 邱涵楨
// 1123512
// 113.11.28
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

// Custom struct to hold elements from the arrays
struct Element {
    int value;        // Value of the element
    int arrayIndex;   // Index of the array it belongs to
    int elementIndex; // Index within the array

    Element(int v, int aIdx, int eIdx) : value(v), arrayIndex(aIdx), elementIndex(eIdx) {}
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(const Element& a, const Element& b) {
        return a.value > b.value; // Min-heap (smallest value comes first)
    }
};

// Function to merge K sorted arrays into one sorted array
vector<int> mergeKSortedArrays(vector<int>* arrays, int* sizes, int K) {
    priority_queue<Element, vector<Element>, Compare> minPQ;

    // Insert the first element of each array into the priority queue
    for (int i = 0; i < K; ++i) {
        if (sizes[i] > 0) { // Ensure the array is non-empty
            minPQ.push(Element(arrays[i][0], i, 0));
        }
    }

    vector<int> result;

    // Process the priority queue
    while (!minPQ.empty()) {
        Element top = minPQ.top();
        minPQ.pop();

        // Add the smallest element to the result
        result.push_back(top.value);

        // Insert the next element from the same array, if any
        if (top.elementIndex + 1 < sizes[top.arrayIndex]) {
            minPQ.push(Element(arrays[top.arrayIndex][top.elementIndex + 1], top.arrayIndex, top.elementIndex + 1));
        }
    }

    return result;
}

int main() {
    int K;
    cin >> K;
    cin.ignore();

    // Dynamically allocate arrays
    vector<int>* arrays = new vector<int>[K];
    int* sizes = new int[K]; // Array to store the sizes of each array

    // Read input arrays
    for (int i = 0; i < K; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        int num;
        while (iss >> num) {
            arrays[i].push_back(num); // Populate the array
        }
        sizes[i] = arrays[i].size(); // Store the size of this array
    }

    // Merge the arrays
    vector<int> mergedArray = mergeKSortedArrays(arrays, sizes, K);

    // Print the merged array
    for (size_t i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    // Clean up dynamically allocated memory
    delete[] arrays;
    delete[] sizes;

    return 0;
}





