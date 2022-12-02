#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  line.reserve(3);
  int total_score = 0;

  while (std::getline(std::cin, line)) {
    // score for the shape selected
    total_score += line[2] - 'X' + 1;
    // score for outcome                              vvv --> make modulo +ve
    total_score += ((line[2] - 'X') + ('B' - line[0]) + 3) % 3 * 3;
  }
  std::cout << total_score << std::endl;
  return 0;
}
