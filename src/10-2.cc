#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  long cycle = 0, X = 1;
  auto updateScreen = [&cycle, &X]() {
    if (cycle % 40 == 0 && cycle != 0) std::cout << '\n';
    std::cout << (X >= -1 && X <= 40
                          && (cycle % 40 == X - 1 || cycle % 40 == X
                              || cycle % 40 == X + 1)
                      ? '#'
                      : '.');
  };
  while (std::getline(std::cin, line)) {
    updateScreen();
    ++cycle;
    if (line[0] != 'a') continue;
    updateScreen();
    ++cycle;
    X += std::strtol(line.c_str() + 4, nullptr, 10);
  }
  return 0;
}
