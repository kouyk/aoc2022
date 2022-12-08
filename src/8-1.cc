#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<std::string> rows;
  rows.emplace_back();
  std::getline(std::cin, rows.back());
  const int n = (int) rows.front().length();
  rows.resize(n);
  for (size_t i = 1; i < rows.size(); ++i) { std::getline(std::cin, rows[i]); }

  std::vector<std::vector<unsigned char>> counts(rows.size());
  for (auto &row : counts) { row.resize(n, 0); }
  char highest;
  for (int i = 0; i < rows.size(); ++i) {
    highest = '0' - 1;
    for (int j = 0; j < rows[i].size(); ++j) {
      if (rows[i][j] > highest) {
        highest = rows[i][j];
        ++counts[i][j];
      }
    }
    highest = '0' - 1;
    for (int j = n - 1; j >= 0; --j) {
      if (rows[i][j] > highest) {
        highest = rows[i][j];
        ++counts[i][j];
      }
    }
  }
  for (int i = 0; i < rows.size(); ++i) {
    highest = '0' - 1;
    for (int j = 0; j < rows[i].size(); ++j) {
      if (rows[j][i] > highest) {
        highest = rows[j][i];
        ++counts[j][i];
      }
    }
    highest = '0' - 1;
    for (int j = n - 1; j >= 0; --j) {
      if (rows[j][i] > highest) {
        highest = rows[j][i];
        ++counts[j][i];
      }
    }
  }
  size_t total = 0;
  for (const auto &row : counts) {
    auto num = std::ranges::count_if(row, [](const auto &c) { return c > 0; });
    total += num;
  }
  std::cout << total << '\n';
  return 0;
}
