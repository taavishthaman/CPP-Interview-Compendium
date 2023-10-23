function reversePart(arr, i, j) {
  let n = j - i + 1;

  let nmid = i + Math.floor(n / 2);

  //Loop will run from i to nmid
  let count = 0;
  for (let k = i; k < nmid; k++) {
    [arr[k], arr[j - count]] = [arr[j - count], arr[k]];
    count++;
  }
}

function KReverse(arr, k) {
  let n = arr.length;
  k = k % n;
  reversePart(arr, 0, n - 1);
  reversePart(arr, 0, k - 1);
  reversePart(arr, k + 1, n - 1);
}

KReverse(arr, k);
