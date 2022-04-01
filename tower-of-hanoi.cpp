#include <iostream>
#include <vector>
int cnt = 0;
std::vector<int> v;
void f(int n, int curr, int dest) {

  if (n > 0 && n == 1) {
    v.push_back(curr);
    v.push_back(dest);
    // std::cout << curr << " " << dest << "\n";
    cnt++;
    return;
  }
  int spare;
  if (curr == 1 && dest == 2)
    spare = 3;
  if (curr == 1 && dest == 3)
    spare = 2;
  if (curr == 2 && dest == 1)
    spare = 3;
  if (curr == 2 && dest == 3)
    spare = 1;
  if (curr == 3 && dest == 1)
    spare = 2;
  if (curr == 3 && dest == 2)
    spare = 1;

  f(n - 1, curr, spare);
  v.push_back(curr);
  v.push_back(dest);
  // std::cout << curr << " " << dest << "\n";
  cnt++;

  f(n - 1, spare, dest);
}

int main() {
  int n;
  std::cin >> n;
  f(n, 1, 3);
  std::cout << cnt;
  for (auto beg = v.begin(); beg != v.end(); beg++) {
    if ((beg - v.begin()) % 2 == 0)
      std::cout << "\n";
    std::cout << *beg << " ";
  }
}
