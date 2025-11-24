#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  long long tt = 1;
  scanf("%lld", &tt);
  while (tt--) {
    long long n;
    scanf("%lld", &n);
    long long *a = (long long *)malloc(n * sizeof(long long));
    for (long long i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }
    if (n % 2 != 0) {
      printf("NO\n");
    } else {
      bool flag = true;
      long long x = n / 2;
      for (long long i = 0; i < n; i++) {
        if (a[i] == -1 && a[(i + x) % n] == -1) {
          a[i] = 1;
          a[(i + x) % n] = 1;
        } else if (a[i] != -1 && a[(i + x) % n] == -1) {
          a[(i + x) % n] = a[i];
        } else if (a[i] != -1 && a[(i + x) % n] != -1 &&
                   (a[i] != a[(i + x) % n])) {
          flag = false;
          break;
        }
      }

      if (flag) {
        printf("YES\n");
        for (long long i = 0; i < n; i++) {
          printf("%lld%c", a[i], (i == n - 1) ? '\n' : ' ');
        }
      } else {
        printf("NO\n");
      }
    }
    free(a);
  }

  return 0;
}
