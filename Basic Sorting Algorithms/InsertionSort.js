function insertion_sort(arr) {
  let n = arr.length;

  for (let i = 1; i <= n - 1; i++) {
    let current = arr[i];
    let prev = i - 1;

    while (prev >= 0 && arr[prev] > current) {
      arr[prev + 1] = arr[prev];
      prev--;
    }

    arr[prev + 1] = current;
  }

  for (let num of arr) {
    console.log(num);
  }
}

let arr = [-2, 3, 4, -1, 5, -12, 6, 1, 3];
insertion_sort(arr);
