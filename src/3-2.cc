#include <cstring>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  int sum = 0, index = 0;
  int64_t common = ~0;
  while (std::getline(std::cin, line)) {
    int64_t bitset = 0;
    for (auto c : line) { bitset |= 1LL << (c > 'Z' ? c - 'a' : c - 'A' + 26); }
    common &= bitset;
    ++index;
    if (index == 3) {
      sum += ffsll(common);
      index = 0, common = ~0;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
