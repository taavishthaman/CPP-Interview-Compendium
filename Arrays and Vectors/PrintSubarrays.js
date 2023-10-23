const printSubarrays = (arr) => {
  let n = arr.length;

  for (let i = 0; i < n - 1; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = i; k < j; k++) {
        process.stdout.write(`${arr[k]},`);
      }
      console.log();
    }
  }
};

const arr = [5, 8, 10, 12, 16, 21, 31, 55];
printSubarrays(arr);
