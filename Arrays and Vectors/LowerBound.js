const LowerBound = (arr, target) => {
  let n = arr.length;

  let lo = 0;
  let hi = n - 1;
  let lower_bound = -1;

  while (lo <= hi) {
    let mid = Math.floor((lo + hi) / 2);

    if (arr[mid] === target) {
      return arr[mid];
    } else if (target < arr[mid]) {
      hi = mid - 1;
    } else {
      lower_bound = arr[mid];
      lo = mid + 1;
    }
  }

  return lower_bound;
};

const arr = [1, 2, 4, 5, 6];
console.log(LowerBound(arr, 0));
