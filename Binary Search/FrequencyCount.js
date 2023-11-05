function lower_bound(arr, key) {
  let lo = 0;
  let hi = arr.length - 1;
  let res = -1;

  while (lo <= hi) {
    let mid = Math.floor((lo + hi) / 2);
    if (arr[mid] === key) {
      res = mid;
      hi = mid - 1;
    } else if (key < arr[mid]) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return res;
}

function upper_bound(arr, key) {
  let lo = 0;
  let hi = arr.length - 1;
  let res = -1;

  while (lo <= hi) {
    let mid = Math.floor((lo + hi) / 2);

    if (arr[mid] === key) {
      res = mid;
      lo = mid + 1;
    } else if (key < arr[mid]) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return res;
}

function frquency_count(arr, key) {
  let lo = lower_bound(arr, key);

  let hi = upper_bound(arr, key);
  return hi - lo + 1;
}

let arr = [0, 1, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 10];
console.log(frquency_count(arr, 1));
