#include <cstdio>

int main() {

  int l1, l2, r1, r2;
  int num_pairs = 0;
  while (scanf("%d-%d,%d-%d", &l1, &r1, &l2, &r2) != EOF) {
    if (l1 >= l2 && r1 <= r2 || l2 >= l1 && r2 <= r1) { ++num_pairs; }
  }
  printf("%d\n", num_pairs);
  return 0;
}
