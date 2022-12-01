#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  int total = 0;
  std::vector<int> top_three;
  top_three.reserve(3);
  while (std::getline(std::cin, line)) {
    if (!line.empty()) {
      int calories = std::stoi(line);
      total += calories;
      continue;
    }
    if (top_three.size() < 3) {
      top_three.emplace_back(total);
    } else if (total > top_three[0]) {
      std::ranges::pop_heap(top_three, std::greater<>());
      top_three.back() = total;
    }
    std::ranges::push_heap(top_three, std::greater<>());
    total = 0;
  }
  std::cout << std::reduce(top_three.begin(), top_three.end()) << std::endl;
  return 0;
}
