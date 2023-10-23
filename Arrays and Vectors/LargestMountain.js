const LargestMountain = (nums) => {
  let n = nums.length;
  if (n < 3) {
    return 0;
  }
  let largest = 0;

  for (let i = 1; i < n; ) {
    if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
      let length = 1;

      let j = i;

      while (j > 0 && nums[j] > nums[j - 1]) {
        j--;
        length++;
      }

      j = i;

      while (j < n - 1 && nums[j] > nums[j + 1]) {
        j++;
        length++;
      }

      largest = Math.max(largest, length);
      i = j;
    } else {
      i++;
    }
  }

  return largest;
};

const arr = [2, 1, 4, 7, 3, 2, 5];
console.log(LargestMountain(arr));
