#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  long cycle = 1, X = 1, signal_sum = 0;
  auto updateSum = [&cycle, &X, &signal_sum]() {
    signal_sum += cycle * X;
  };
  while (std::getline(std::cin, line)) {
    ++cycle;
    if ((cycle - 20) % 40 == 0) { updateSum(); }
    if (line[0] != 'a') continue;
    ++cycle;
    X += std::strtol(line.c_str() + 4, nullptr, 10);
    if ((cycle - 20) % 40 == 0) { updateSum(); }
  }
  std::cout << signal_sum << std::endl;
  return 0;
}
