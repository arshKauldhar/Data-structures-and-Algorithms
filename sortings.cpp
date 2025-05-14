// // #include <iostream>
// // #include <vector>

// // using namespace std;

// // // Function to swap two elements in an array
// // void swap(int& a, int& b) {
// //     int temp = a;
// //     a = b;
// //     b = temp;
// // }

// // // Function to display an array
// // void displayArray(const vector<int>& arr) {
// //     for (int num : arr) {
// //         cout << num << " ";
// //     }
// //     cout << endl;
// // }

// // // Bubble Sort
// // void bubbleSort(vector<int>& arr, int& comparisons, int& swaps) {
// //     int n = arr.size();
// //     for (int i = 0; i < n - 1; ++i) {
// //         for (int j = 0; j < n - i - 1; ++j) {
// //             comparisons++;
// //             if (arr[j] > arr[j + 1]) {
// //                 swaps++;
// //                 swap(arr[j], arr[j + 1]);
// //             }
// //         }
// //     }
// // }

// // // Insertion Sort
// // void insertionSort(vector<int>& arr, int& comparisons, int& swaps) {
// //     int n = arr.size();
// //     for (int i = 1; i < n; ++i) {
// //         int key = arr[i];
// //         int j = i - 1;

// //         while (j >= 0 && arr[j] > key) {
// //             comparisons++;
// //             swaps++;
// //             arr[j + 1] = arr[j];
// //             j--;
// //         }
// //         arr[j + 1] = key;
// //     }
// // }

// // // Selection Sort
// // void selectionSort(vector<int>& arr, int& comparisons, int& swaps) {
// //     int n = arr.size();
// //     for (int i = 0; i < n - 1; ++i) {
// //         int minIndex = i;
// //         for (int j = i + 1; j < n; ++j) {
// //             comparisons++;
// //             if (arr[j] < arr[minIndex]) {
// //                 minIndex = j;
// //             }
// //         }
// //         swaps++;
// //         swap(arr[i], arr[minIndex]);
// //     }
// // }

// // // Quick Sort
// // int partition(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
// //     int pivot = arr[high];
// //     int i = low - 1;

// //     for (int j = low; j < high; ++j) {
// //         comparisons++;
// //         if (arr[j] <= pivot) {
// //             i++;
// //             swaps++;
// //             swap(arr[i], arr[j]);
// //         }
// //     }

// //     swaps++;
// //     swap(arr[i + 1], arr[high]);
// //     return i + 1;
// // }

// // void quickSort(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
// //     if (low < high) {
// //         int pi = partition(arr, low, high, comparisons, swaps);
// //         quickSort(arr, low, pi - 1, comparisons, swaps);
// //         quickSort(arr, pi + 1, high, comparisons, swaps);
// //     }
// // }

// // // Merge Sort
// // void merge(vector<int>& arr, int left, int mid, int right, int& comparisons, int& swaps) {
// //     int n1 = mid - left + 1;
// //     int n2 = right - mid;

// //     vector<int> leftArr(n1);
// //     vector<int> rightArr(n2);

// //     for (int i = 0; i < n1; ++i) {
// //         leftArr[i] = arr[left + i];
// //     }
// //     for (int j = 0; j < n2; ++j) {
// //         rightArr[j] = arr[mid + 1 + j];
// //     }

// //     int i = 0;
// //     int j = 0;
// //     int k = left;

// //     while (i < n1 && j < n2) {
// //         comparisons++;
// //         if (leftArr[i] <= rightArr[j]) {
// //             swaps++;
// //             arr[k] = leftArr[i];
// //             i++;
// //         } else {
// //             swaps++;
// //             arr[k] = rightArr[j];
// //             j++;
// //         }
// //         k++;
// //     }

// //     while (i < n1) {
// //         swaps++;
// //         arr[k] = leftArr[i];
// //         i++;
// //         k++;
// //     }

// //     while (j < n2) {
// //         swaps++;
// //         arr[k] = rightArr[j];
// //         j++;
// //         k++;
// //     }
// // }

// // void mergeSort(vector<int>& arr, int left, int right, int& comparisons, int& swaps) {
// //     if (left < right) {
// //         int mid = left + (right - left) / 2;
// //         mergeSort(arr, left, mid, comparisons, swaps);
// //         mergeSort(arr, mid + 1, right, comparisons, swaps);
// //         merge(arr, left, mid, right, comparisons, swaps);
// //     }
// // }

// // int main() {
// //     vector<int> arr = {12, 11, 13, 5, 6, 7};

// //     cout << "Original Array: ";
// //     displayArray(arr);

// //     // Bubble Sort
// //     vector<int> bubbleArr = arr;
// //     int bubbleComparisons = 0, bubbleSwaps = 0;
// //     bubbleSort(bubbleArr, bubbleComparisons, bubbleSwaps);
// //     cout << "\nBubble Sort:\n";
// //     cout << "Sorted Array: ";
// //     displayArray(bubbleArr);
// //     cout << "Comparisons: " << bubbleComparisons << ", Swaps: " << bubbleSwaps << endl;

// //     // Insertion Sort
// //     vector<int> insertionArr = arr;
// //     int insertionComparisons = 0, insertionSwaps = 0;
// //     insertionSort(insertionArr, insertionComparisons, insertionSwaps);
// //     cout << "\nInsertion Sort:\n";
// //     cout << "Sorted Array: ";
// //     displayArray(insertionArr);
// //     cout << "Comparisons: " << insertionComparisons << ", Swaps: " << insertionSwaps << endl;

// //     // Selection Sort
// //     vector<int> selectionArr = arr;
// //     int selectionComparisons = 0, selectionSwaps = 0;
// //     selectionSort(selectionArr, selectionComparisons, selectionSwaps);
// //     cout << "\nSelection Sort:\n";
// //     cout << "Sorted Array: ";
// //     displayArray(selectionArr);
// //     cout << "Comparisons: " << selectionComparisons << ", Swaps: " << selectionSwaps << endl;

// //     // Quick Sort
// //     vector<int> quickArr = arr;
// //     int quickComparisons = 0, quickSwaps = 0;
// //     quickSort(quickArr, 0, quickArr.size() - 1, quickComparisons, quickSwaps);
// //     cout << "\nQuick Sort:\n";
// //     cout << "Sorted Array: ";
// //     displayArray(quickArr);
// //     cout << "Comparisons: " << quickComparisons << ", Swaps: " << quickSwaps << endl;

// //     // Merge Sort
// //     vector<int> mergeArr = arr;
// //     int mergeComparisons = 0, mergeSwaps = 0;
// //     mergeSort(mergeArr, 0, mergeArr.size() - 1, mergeComparisons, mergeSwaps);
// //     cout << "\nMerge Sort:\n";
// //     cout << "Sorted Array: ";
// //     displayArray(mergeArr);
// //     cout << "Comparisons: " << mergeComparisons << ", Swaps: " << mergeSwaps << endl;

// //     return 0;
// // }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int minDistance(const string &word1, const string &word2) {
//     int m = word1.length();
//     int n = word2.length();

//     // Create a 2D vector to store the distances
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//     // Initialize the matrix
//     for (int i = 0; i <= m; ++i) {
//         for (int j = 0; j <= n; ++j) {
//             if (i == 0) {
//                 dp[i][j] = j;
//             } else if (j == 0) {
//                 dp[i][j] = i;
//             } else if (word1[i - 1] == word2[j - 1]) {
//                 dp[i][j] = dp[i - 1][j - 1];
//             } else {
//                 dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
//             }
//         }
//     }

//     // The bottom-right cell contains the edit distance
//     return dp[m][n];
// }

// int main() {
//     string word1, word2;

//     // Input two strings
//     cout << "Enter the first string: ";
//     cin >> word1;
//     cout << "Enter the second string: ";
//     cin >> word2;

//     // Compute and output the edit distance
//     int distance = minDistance(word1, word2);
//     cout << "The edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << distance << endl;

//     return 0;
// }


#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1, s2;
  cout << "Enter the first string: ";
  cin >> s1;
  cout << "Enter the second string: ";
  cin >> s2;

  int n1 = s1.length();
  int n2 = s2.length();

  int dp[n1 + 1][n2 + 1];

  for (int i = 0; i <= n1; i++) {
    for (int j = 0; j <= n2; j++) {
      if (i == 0) {
        dp[i][j] = j;
      } else if (j == 0) {
        dp[i][j] = i;
      } else if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
      }
    }
  }

  cout << "The edit distance between the two strings is: " << dp[n1][n2] << endl;

  return 0;
}

