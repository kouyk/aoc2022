#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string buffer;
  std::getline(std::cin, buffer);

  auto find_start = [&buffer](const int length) {
    int pos = length;
  NEXT:
    for (int i = pos - length; i + 1 < pos; ++i) {
      for (int j = pos - 1; j > i; --j) {
        if (buffer[i] == buffer[j]) {
          pos = i + length + 1;
          goto NEXT;
        }
      }
    }
    return pos;
  };
  std::cout << find_start(4) << '\n' << find_start(14) << '\n';

  return 0;
}
