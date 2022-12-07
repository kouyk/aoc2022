#include <cassert>
#include <limits>
#include <iostream>
#include <vector>

struct Directory {
  explicit Directory(size_t parent) : parent(parent), size(0) {}
  size_t parent;
  size_t size;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  std::getline(std::cin, line);
  assert(line == "$ cd /");

  std::vector<Directory> directories;
  directories.emplace_back(std::numeric_limits<size_t>::max());

  size_t curr = 0;
  while (std::getline(std::cin, line)) {
    switch (line[0]) {
      case '$': {
        if (line[2] == 'l') continue;

        auto dir = std::string_view(line).substr(5);
        if (dir == "..") {
          auto parent = directories[curr].parent;
          directories[parent].size += directories[curr].size;
          curr = parent;
          continue;
        }
        directories.emplace_back(curr);
        curr = directories.size() - 1;
        continue;
      }
      case 'd': continue;
      default: directories[curr].size += std::stoul(line);
    }
  }
  auto parent = directories[curr].parent;
  while (parent != std::numeric_limits<size_t>::max()) {
    directories[parent].size += directories[curr].size;
    curr = parent;
    parent = directories[curr].parent;
  }
  size_t total = 0;
  for (const auto &dir : directories) {
    if (dir.size > 100000) continue;
    total += dir.size;
  }
  std::cout << total << '\n';

  size_t space_needed = 30000000 - (70000000 - directories.front().size);
  size_t extra = std::numeric_limits<size_t>::max();
  size_t to_free;
  for (const auto &dir : directories) {
    if (dir.size < space_needed) continue;
    if (dir.size - space_needed < extra) {
      extra = dir.size - space_needed;
      to_free = dir.size;
    }
  }
  std::cout << to_free << '\n';

  return 0;
}
