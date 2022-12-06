#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

namespace sr = std::ranges;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  std::getline(std::cin, line);
  auto num_stack = (line.length() + 1) / 4;
  std::vector<std::string> stacks(num_stack);
  do {
    for (int i = 0; i < num_stack; ++i) {
      auto idx = i * 4 + 1;
      if (isupper(line[idx])) stacks[i] += line[idx];
    }
    std::getline(std::cin, line);
  } while (line.front() != ' ');
  std::cin.ignore();
  sr::for_each(stacks, sr::reverse);

  sr::for_each(stacks, [](const auto &s) { std::cout << s << '\n'; });
  while (std::getline(std::cin, line)) {
    int num_move, src, dst;
    sscanf(line.c_str(), "move %d from %d to %d", &num_move, &src, &dst);
    --src, --dst;
    std::cout << "move " << num_move << " from " << src << " to " << dst
              << '\n';
    stacks[dst].append(stacks[src].end() - num_move, stacks[src].end());
    stacks[src].erase(stacks[src].end() - num_move, stacks[src].end());
    sr::for_each(stacks, [](const auto &s) { std::cout << s << '\n'; });
  }
  for (auto &str : stacks) {
    if (!str.empty()) {
      std::cout << str.back();
    }
  }
  std::cout << '\n';
  return 0;
}
