#include <array>
#include <iostream>
#include <ranges>
#include <set>
#include <string>

static const int NUM_KNOTS = 2; // 2 for part 1, 10 for part 2

struct Position {
  int x{};
  int y{};
  Position operator-(const Position &other) const {
    return {x - other.x, y - other.y};
  }
  auto operator<=>(const Position &) const = default;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;
  std::array<Position, NUM_KNOTS> knots;
  auto &head = knots.front(), &tail = knots.back();
  std::set<Position> visited;
  visited.emplace(tail);
  while (std::getline(std::cin, line)) {
    const auto steps = std::stoi(line.substr(2));
    const int direction = line[0] == 'U' || line[0] == 'R' ? 1 : -1;
    auto &head_axis =
        line[0] == 'R' || line[0] == 'L' ? head.x : head.y;
    for (int i : std::views::iota(0, steps)) {
      head_axis += direction;
      for (int j : std::views::iota(1, NUM_KNOTS)) {
        const auto [x, y] = knots[j-1] - knots[j];
        if (abs(x) != 2 && abs(y) != 2) continue;
        if (x != 0) knots[j].x += x / abs(x);
        if (y != 0) knots[j].y += y / abs(y);
      }
      visited.emplace(tail);
    }
  }
  std::cout << visited.size() << '\n';
  return 0;
}
