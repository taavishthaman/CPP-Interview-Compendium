function partition(arr, s, e) {
  let i = s - 1;
  let pivot = arr[e];

  for (let j = s; j <= e - 1; j++) {
    if (arr[j] < pivot) {
      [arr[i + 1], arr[j]] = [arr[j], arr[i + 1]];
      i++;
    }
  }

  [arr[i + 1], arr[e]] = [arr[e], arr[i + 1]];
  return i + 1;
}

function quick_sort(arr, s, e) {
  if (s >= e) {
    return;
  }

  let p = partition(arr, s, e);
  quick_sort(arr, s, p - 1);
  quick_sort(arr, p + 1, e);
}

let arr = [-2, 3, 4, -1, 5, -12, 6, 1, 3];
quick_sort(arr, 0, arr.length - 1);

for (let num of arr) {
  console.log(num);
}
