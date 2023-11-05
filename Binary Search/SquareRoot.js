function squareRoot(N, P) {
  let lo = 0;
  let hi = N;
  let res = 0;

  while (lo <= hi) {
    let mid = Math.floor((lo + hi) / 2);
    if (mid * mid === N) {
      return mid;
    } else if (mid * mid < N) {
      res = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  let factor = 0.1;
  for (let i = 0; i < P; i++) {
    let count = 1;
    while (res * res < N && count < 10) {
      res += factor;
      count++;
    }

    if (res * res === N) {
      return res;
    }

    res -= factor;

    factor /= 10;
  }

  return res;
}

console.log(squareRoot(10, 3));
