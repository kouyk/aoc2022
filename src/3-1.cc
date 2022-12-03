#include <iostream>
#include <string_view>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  int sum = 0;
  while (std::getline(std::cin, line)) {
    auto first_half = std::string_view(line).substr(0, line.size() / 2);
    auto second_half = std::string_view(line).substr(line.size() / 2);
    auto pos = second_half.find_first_of(first_half);
    char c = second_half[pos];
    sum += c > 'Z' ? c - 'a' + 1 : c - 'A' + 27;
  }
  std::cout << sum << std::endl;
  return 0;
}
