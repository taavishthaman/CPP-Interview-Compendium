function checkUnsorted(nums, i) {
  let n = nums.length;
  if (i === 0) {
    return nums[i] > nums[i + 1];
  } else if (i === n - 1) {
    return nums[i] < nums[i - 1];
  } else {
    return nums[i] < nums[i - 1] || nums[i] > nums[i + 1];
  }
}

function subarraySort(nums) {
  let n = nums.length;
  let max_val = Number.MIN_SAFE_INTEGER;
  let min_val = Number.MAX_SAFE_INTEGER;
  for (let i = 0; i < n; i++) {
    if (checkUnsorted(nums, i)) {
      max_val = Math.max(max_val, nums[i]);
      min_val = Math.min(min_val, nums[i]);
    }
  }

  if (
    max_val === Number.MIN_SAFE_INTEGER ||
    min_val === Number.MAX_SAFE_INTEGER
  ) {
    return 0;
  }

  let left = 0;
  let right = n - 1;

  while (left < n && nums[left] <= min_val) {
    left++;
  }

  while (right >= 0 && nums[right] >= max_val) {
    right--;
  }

  return right - left + 1;
}

const nums = [2, 6, 4, 8, 10, 9, 15];
console.log(subarraySort(nums));
