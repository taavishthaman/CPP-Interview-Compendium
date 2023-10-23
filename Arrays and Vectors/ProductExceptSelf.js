function ProductExceptSelf(nums) {
  let n = nums.length;
  const prefix = [];
  prefix[0] = nums[0];

  for (let i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] * nums[i];
  }

  let product = 1;

  for (let i = n - 1; i >= 1; i--) {
    prefix[i] = prefix[i - 1] * product;
    product *= nums[i];
  }

  prefix[0] = product;
  return prefix;
}

const arr = [1, 2, 3, 4];
console.log(ProductExceptSelf(arr));
