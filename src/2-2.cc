#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  line.reserve(3);
  int total_score = 0;

  while (std::getline(std::cin, line)) {
    // score for the shape selected                   vvv --> make modulo +ve
    total_score += ((line[0] - 'A') + (line[2] - 'Y') + 3) % 3 + 1;
    // score for outcome
    total_score += (line[2] - 'X') * 3;
  }
  std::cout << total_score << std::endl;
  return 0;
}
