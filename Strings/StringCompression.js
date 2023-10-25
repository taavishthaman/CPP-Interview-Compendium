function StringCompression(chars) {
  let n = chars.length;
  let count = 1;
  let k = 0;
  let i = 0;
  for (i = 0; i < n - 1; i++) {
    if (chars[i] !== chars[i + 1]) {
      let ch = chars[i];
      if (count === 1) {
        chars[k] = ch;
        k++;
      } else {
        chars[k] = ch;
        k++;
        let count_str = String(count);
        for (let j = 0; j < count_str.length; j++) {
          chars[k] = count_str[j];
          k++;
        }
      }
      count = 1;
    } else {
      count++;
    }
  }

  let ch = chars[i];
  if (count === 1) {
    chars[k] = ch;
    k++;
  } else {
    chars[k] = ch;
    k++;
    let count_str = String(count);
    for (let j = 0; j < count_str.length; j++) {
      chars[k] = count_str[j];
      k++;
    }
  }
  return k;
}

const length = StringCompression(["a", "a", "b", "b", "c", "c", "c"]);
console.log(length);
