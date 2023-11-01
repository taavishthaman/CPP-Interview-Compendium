function StringWindow(s, t) {
  if (s.length < t.length) {
    return "";
  }
  const FP = Array(256).fill(0);
  const FS = Array(256).fill(0);

  for (let i = 0; i < t.length; i++) {
    FP[t[i].charCodeAt(0)]++;
  }

  let cnt = 0;
  let start = 0;
  let min_window_len = Number.MAX_SAFE_INTEGER;
  let window_start = -1;
  for (let i = 0; i < s.length; i++) {
    const ch = s[i].charCodeAt(0);

    FS[ch]++;

    if (FP[ch] != 0 && FS[ch] <= FP[ch]) {
      cnt++;
    }

    if (cnt === t.length) {
      while (
        FP[s[start].charCodeAt(0)] === 0 ||
        FS[s[start].charCodeAt(0)] > FP[s[start].charCodeAt(0)]
      ) {
        FS[s[start].charCodeAt(0)]--;
        start++;
      }

      let window_len = i - start + 1;

      if (window_len < min_window_len) {
        min_window_len = window_len;
        window_start = start;
      }
    }
  }

  if (window_start === -1) {
    return "";
  }

  return s.substr(window_start, min_window_len);
}

const s = "ADOBECODEBANC";
const t = "ABC";
console.log(StringWindow(s, t));
