function housing(arr, target) {
  let n = arr.length;
  let i = 0;
  let j = 0;
  let cs = 0;
  while (j < n) {
    cs += arr[j];
    j++;

    while (cs > target) {
      cs -= arr[i];
      i++;
    }

    if (cs == target) {
      console.log(i, j - 1);
    }
  }
}

const arr = [1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2];
housing(arr, 8);
