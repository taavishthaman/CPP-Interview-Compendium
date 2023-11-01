function MaxSubstring(str) {
  const m = new Map();
  let i = 0;
  let j = 0;
  let n = str.length;
  let len = 0;
  let max_len = 0;
  let start = -1;

  while (j < n) {
    let ch = str[j];

    if (m.has(ch) && m.get(ch) >= i) {
      i = m.get(ch) + 1;
      len = j - i;
    }

    m.set(ch, j);
    j++;
    len++;

    if (len > max_len) {
      max_len = len;
      start = i;
    }
  }

  return max_len;
}

const str = "pwwkew";

console.log(MaxSubstring(str));
