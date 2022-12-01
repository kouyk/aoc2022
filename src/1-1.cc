#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  int max_total = 0, total = 0;
  while (std::getline(std::cin, line)) {
    if (line.empty()) {
      max_total = std::max(max_total, total);
      total = 0;
      continue;
    }
    int calories = std::stoi(line);
    total += calories;
  }
  std::cout << max_total << std::endl;
  return 0;
}
