#include <iostream>

template <class T>
T* merge(const T* a, size_t sa, const T* b, size_t sb, T* c) {
    if (!c) {
      throw std::invalid_argument("merge: output buffer c is null");
    }
    if (!a && sa != 0) {
      throw std::invalid_argument("merge: a is null but sa != 0");
    }
    if (!b && sb != 0) {
      throw std::invalid_argument("merge: b is null but sb != 0");
    }
    size_t i = 0, j = 0, k = 0;
    while (i < sa && j < sb) {
        if (a[i] <= b[j]) { //operator<=(const T&, const T&)
          c[k++] = a[i++]; //T::operator=(const T&)
        } else {
          c[k++] = b[j++];
        }
    }
    while (i < sa) {
      c[k++] = a[i++];
    }
    while (j < sb) {
      c[k++] = b[j++];
    }
    return c;
}

int main() {
  int a[] = {1, 3, 5, 5, 10};
  int b[] = {2, 5, 6, 11};
  const size_t sa = sizeof(a) / sizeof(a[0]);
  const size_t sb = sizeof(b) / sizeof(b[0]);
  int c[sa + sb];
  merge(a, sa, b, sb, c);
  for (std::size_t i = 0; i < sa + sb; ++i) {
    std::cout << c[i];
    if (i + 1 < sa + sb) {
      std::cout << ' ';
    }
  }
  std::cout << '\n';
}
