#include <iostream>
#include <array>
using namespace std;

const int n = 8;

bool isSafe(int x, int y, const array<array<int, n>, n> &sol) {
  return (x < n && x >= 0 && y < n && y >=0 && sol[x][y] == -1);
}

bool backtracking(int x, int y, int mov, array<array<int, n>, n> &sol,
                  const array<int, n> &xmov, array<int, n> &ymov) {
  int k = 0, xNext = 0, yNext = 0;

  if (mov == n * n) {
    return true;
  }

  for (k = 0; k < n; k++) {
    xNext = x + xmov[k];
    yNext = y + ymov[k];

    if (isSafe(xNext, yNext, sol)) {
      sol[xNext][yNext] = mov;

      if (backtracking(xNext, yNext, mov + 1, sol, xmov, ymov) == true) {
        return true;
      } else {
        sol[xNext][yNext] = -1;
      }
    }
  }
  return false;
}

int main() {
  array<array<int, n>, n> sol = {0};

  int i = 0, j = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        sol[i][j] = -1;
    }
  }

  array<int, n> xmov = {2, 1, -1, -2, -2, -1, 1, 2};
  array<int, n> ymov = {1, 2, 2, 1, -1, -2, -2, -1};

  sol[0][0] = 0;

  bool flag = backtracking(0, 0, 1, sol, xmov, ymov);

  if (flag == false) {
    cout << "Error\n";
  } else {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        cout << sol[i][j] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
