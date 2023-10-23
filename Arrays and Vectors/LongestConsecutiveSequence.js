const LongestConsecutiveSequence = (nums) => {
  let n = nums.length;
  let s = new Set(nums);
  let longest = 0;

  for (let i = 0; i < n; i++) {
    let num = nums[i];
    if (!s.has(num - 1)) {
      let length = 0;
      while (s.has(num)) {
        length++;
        num++;
      }

      longest = Math.max(longest, length);
    }
  }

  return longest;
};

const arr = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1];

console.log(LongestConsecutiveSequence(arr));
