string rec(int x, int y, int z) {
  string prefix = "";

  while (x + y > z + 1) {
    if ((x + y - z) % 2 == 0) {
      prefix += s[1];
      prefix += s[0];
    } else {
      prefix += s[0];
      prefix += s[1];
    }
    x--;
    y--;
  }

  string ans = "";
  if (x + y + 1 == z || x + y == z) {
    ans += string(x + y + z, s[2]);
    int i = 1;
    while (x) {
      ans[i] = s[0];
      i += 2;
      x--;
    }
    while (y) {
      ans[i] = s[1];
      i += 2;
      y--;
    }
  } else if (x + y - 1 == z) {
    ans += string(x + y + z, s[2]);
    int i = 0;
    while (x) {
      ans[i] = s[0];
      i += 2;
      x--;
    }
    while (y) {
      ans[i] = s[1];
      i += 2;
      y--;
    }
  } else {
    ans += string(2 * (x + y) + 1, s[2]);
    int i = 1;
    while (x) {
      ans[i] = s[0];
      i += 2;
      x--;
    }
    while (y) {
      ans[i] = s[1];
      i += 2;
      y--;
    }
  }

  return prefix + ans;
}