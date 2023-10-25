const ArePermutations = (s, t) => {
  if (s.length !== t.length) {
    return false;
  }
  let n = s.length;
  const f_arr = [];
  for (let i = 0; i < 26; i++) {
    f_arr.push(0);
  }

  for (let i = 0; i < n; i++) {
    let ch = s[i].charCodeAt() - 97;
    f_arr[ch]++;
  }

  for (let i = 0; i < n; i++) {
    let ch = t[i].charCodeAt() - 97;
    f_arr[ch]--;
  }

  for (let i = 0; i < 26; i++) {
    if (f_arr[i] !== 0) {
      return false;
    }
  }

  return true;
};

const s = "rat";
const t = "car";
console.log(ArePermutations(s, t));
