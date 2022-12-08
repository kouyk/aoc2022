#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <ranges>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<std::string> rows;
  rows.emplace_back();
  std::getline(std::cin, rows.front());
  const int n = (int) rows.front().length();
  rows.resize(n);
  for (size_t i = 1; i < rows.size(); ++i) { std::getline(std::cin, rows[i]); }

  std::vector<std::vector<int>> score(rows.size());
  for (auto &row : score) { row.resize(n, 1); }
  std::array<int, 10> last_seen{};
  const auto INT_MAX = std::numeric_limits<int>::max();
  for (int i = 0; i < rows.size(); ++i) {
    std::ranges::fill(last_seen, -1);
    for (int j = 0; j < rows[i].size(); ++j) {
      if (score[i][j] != 0) {
        const auto blocking = *std::ranges::max_element(
            last_seen.begin() + (rows[i][j] - '0'), last_seen.end());
        score[i][j] *= (blocking == -1) ? j : j - blocking;
      }
      last_seen[rows[i][j] - '0'] = j;
    }
    std::ranges::fill(last_seen, INT_MAX);
    for (int j = n - 1; j >= 0; --j) {
      if (score[i][j] != 0) {
        const auto blocking = *std::ranges::min_element(
            last_seen.begin() + (rows[i][j] - '0'), last_seen.end());
        score[i][j] *= (blocking == INT_MAX) ? n - 1 - j : blocking - j;
      }
      last_seen[rows[i][j] - '0'] = j;
    }
  }
  for (int i = 0; i < rows.size(); ++i) {
    std::ranges::fill(last_seen, -1);
    for (int j = 0; j < rows[i].size(); ++j) {
      if (score[j][i] != 0) {
        const auto blocking = *std::ranges::max_element(
            last_seen.begin() + (rows[j][i] - '0'), last_seen.end());
        score[j][i] *= (blocking == -1) ? j : j - blocking;
      }
      last_seen[rows[j][i] - '0'] = j;
    }
    std::ranges::fill(last_seen, INT_MAX);
    for (int j = n - 1; j >= 0; --j) {
      if (score[j][i] != 0) {
        const auto blocking = *std::ranges::min_element(
            last_seen.begin() + (rows[j][i] - '0'), last_seen.end());
        score[j][i] *= (blocking == INT_MAX) ? n - 1 - j : blocking - j;
      }
      last_seen[rows[j][i] - '0'] = j;
    }
  }
  int highest_score = 0;
  for (const auto &row : score) {
    highest_score = std::max(highest_score, std::ranges::max(row));
  }
  std::cout << highest_score << '\n';
  return 0;
}
