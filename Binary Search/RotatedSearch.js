function rotatedSearch(nums, target) {
  let n = nums.length;
  let lo = 0;
  let hi = n - 1;

  while (lo <= hi) {
    let mid = Math.floor((lo + hi) / 2);
    if (nums[mid] === target) {
      return mid;
    }

    if (nums[lo] <= nums[mid]) {
      if (target >= nums[lo] && target <= nums[mid]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    } else {
      if (target >= nums[mid] && target <= nums[hi]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
  }

  return -1;
}

let arr = [4, 5, 6, 7, 0, 1, 2, 3];
let key = 4;
console.log(rotatedSearch(arr, key));
