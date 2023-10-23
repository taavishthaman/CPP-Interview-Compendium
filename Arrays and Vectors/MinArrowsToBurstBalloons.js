function minArrows(points) {
  points.sort((p1, p2) => p1[1] - p2[1]);

  let n = points.length;
  let arrows = 1;
  let end = points[0][1];

  for (let i = 1; i < n; i++) {
    if (points[i][0] > end) {
      arrows++;
      end = points[i][1];
    }
  }

  return arrows;
}

const arr1 = [
  [10, 16],
  [2, 8],
  [1, 6],
  [7, 12],
];

const arr2 = [
  [1, 2],
  [3, 4],
  [5, 6],
  [7, 8],
];

console.log(minArrows(arr1));
console.log(minArrows(arr2));
