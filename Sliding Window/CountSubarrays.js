function CountSubarrays(nums, k) {
  const m = new Map();
  let n = nums.length;
  let count = 0;
  let prefix = Array(n).fill(0);
  prefix[0] = nums[0];
  m.set(nums[0], 1);
  if (nums[0] == k) {
    count++;
  }

  for (let i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + nums[i];
    if (m.has(prefix[i] - k)) {
      count += m.get(prefix[i] - k);
    }
    if (prefix[i] === k) {
      count += 1;
    }
    m.set(prefix[i], m.get(prefix[i] + 1) || 1);
  }

  return count;
}

const arr = [1, 1, 1];
console.log(CountSubarrays(arr, 3));
