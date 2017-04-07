#include <bits/stdc++.h>

using namespace std;

double f[1234567];
char foo[1234567];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, h;
    scanf("%d %d", &h, &n);
    double ans = 0.0;
    while (n--) {
      scanf("%s", foo);
      stringstream ss;
      for (int j = 0; foo[j]; j++) {
        if (foo[j] == '-') {
          ss << " -";
        } else {
          ss << (('0' <= foo[j] && foo[j] <= '9') ? foo[j] : ' ');
        }
      }
      int x, y, z;
      ss >> x >> y;
      if (!(ss >> z)) {
        z = 0;
      }
      for (int i = 0; i <= x * y; i++) {
        f[i] = 0.0;
      }
      f[0] = 1.0;
      for (int i = 0; i < x; i++) {
        for (int j = i * y; j >= 0; j--) {
          for (int k = 1; k <= y; k++) {
            f[j + k] += f[j] / y;
          }
          f[j] = 0.0;
        }
      }
      double cur = 0.0;
      for (int i = 0; i <= x * y; i++) {
        if (i + z >= h) {
          cur += f[i];
        }
      }
      ans = max(ans, cur);
    }
    printf("%.6f\n", ans);
  }
  return 0;
}
