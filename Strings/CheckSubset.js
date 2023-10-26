function checkSubset(s, t) {
  let i = t.length - 1;
  let j = s.length - 1;

  while (i >= 0 && j >= 0) {
    if (t[i] === s[j]) {
      i--;
      j--;
    } else {
      i--;
    }
  }

  if (j === -1) {
    return true;
  }
  return false;
}

const s = "axc";
const t = "ahbgdc";
console.log(checkSubset(s, t));
