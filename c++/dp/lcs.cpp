#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string reverse_str(const string &in_str) {
  return {in_str.rbegin(), in_str.rend()};
}

size_t lcs_length(const string &a, const string &b) {
  const auto size_a = a.size();
  const auto size_b = b.size();

  vector<vector<size_t>> result(size_a + 1, vector<size_t>(size_b + 1, 0));

  const auto limit = static_cast<size_t>(-1);

  for (size_t pos_a = size_a - 1; pos_a != limit; --pos_a) {
    for (size_t pos_b = size_b - 1; pos_b != limit; --pos_b) {
      if (a[pos_a] == b[pos_b]) {
            result[pos_a][pos_b] = 1 + result[pos_a + 1][pos_b + 1];
      } else {
        result[pos_a][pos_b] = max(result[pos_a + 1][pos_b], result[pos_a][pos_b + 1]);
      }
    }
  }
  return result[0][0];
}



