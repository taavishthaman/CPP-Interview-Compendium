function bubble_sort(arr) {
  let n = arr.length;
  for (let times = 1; times <= n - 1; times++) {
    for (let j = 0; j <= n - times - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
      }
    }
  }

  for (let num of arr) {
    console.log(num);
  }
}

let arr = [-2, 3, 4, -1, 5, -12, 6, 1, 3];
bubble_sort(arr);
