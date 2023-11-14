function selection_sort(arr) {
  let n = arr.length;

  for (let pos = 0; pos <= n - 2; pos++) {
    let min_pos = pos;
    for (let j = pos + 1; j <= n - 1; j++) {
      if (arr[j] < arr[min_pos]) {
        min_pos = j;
      }
    }

    [arr[pos], arr[min_pos]] = [arr[min_pos], arr[pos]];
  }

  for (let i = 0; i < n; i++) {
    console.log(arr[i]);
  }
}

let arr = [-2, 3, 4, -1, 5, -12, 6, 1, 3];
selection_sort(arr);
