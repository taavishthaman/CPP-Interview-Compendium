function RainwaterTrapping(height) {
  let n = height.length;
  let left = [];
  let right = [];

  left[0] = height[0];
  right[n - 1] = height[n - 1];

  for (let i = 1; i < n; i++) {
    left[i] = Math.max(left[i - 1], height[i]);
    right[n - 1 - i] = Math.max(right[n - 1 - i + 1], height[n - 1 - i]);
  }

  let total_water = 0;

  for (let i = 0; i < n; i++) {
    total_water += Math.min(left[i], right[i]) - height[i];
  }

  return total_water;
}

const height = [4, 2, 0, 3, 2, 5];
console.log(RainwaterTrapping(height));
