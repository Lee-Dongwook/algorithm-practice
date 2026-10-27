#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <cassert>

using namespace std;

vector<int> bubble_sort(vector<int> &array) {
  bool swap_check = true;
  int size = array.size();

  for (int i = 0; (i < size) && (swap_check); i++) {
    for (int j = 0; j < size - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap_check = true;
        swap(array[j], array[j+1]);
      }
    }
  }
  return array;
}
