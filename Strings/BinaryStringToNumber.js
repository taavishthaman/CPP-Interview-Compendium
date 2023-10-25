function BinaryToNumber(str) {
  let res = 0;
  let n = str.length;
  let p = 0;

  for (let i = n - 1; i >= 0; i--) {
    res += Math.pow(2, p) * +str[i];
    p++;
  }

  return res;
}

console.log(BinaryToNumber("1000"));
