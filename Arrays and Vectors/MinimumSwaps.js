function MinimumSwaps(nums) {
  let n = nums.length;

  let pNums = [];
  for (let i = 0; i < n; i++) {
    pNums.push([nums[i], i]);
  }

  pNums.sort((p1, p2) => p1[0] - p2[0]);

  let visited = nums.map((_) => false);

  let swaps = 0;

  for (let i = 0; i < n; i++) {
    if (pNums[i][0] === nums[i] || visited[i]) {
      continue;
    }

    let cycles = 0;
    let node = i;
    while (!visited[node]) {
      visited[node] = true;
      node = pNums[node][1];
      cycles++;
    }

    swaps += cycles - 1;
  }

  return swaps;
}

const nums = [5, 3, 4, 2, 1];
console.log(MinimumSwaps(nums));
