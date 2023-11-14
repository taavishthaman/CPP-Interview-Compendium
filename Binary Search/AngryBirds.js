function canPlace(nests, B, mid) {
  let prev_loc = nests[0];
  let birds = 1;

  for (let i = 1; i < nests.length; i++) {
    let cur_loc = nests[i];
    if (cur_loc - prev_loc >= mid) {
      prev_loc = cur_loc;
      birds++;

      if (birds === B) {
        return true;
      }
    }
  }

  return false;
}

function AngryBirds(nests, B) {
  //Sort the nests
  let n = nests.length;
  nests.sort((a, b) => a - b);

  let lo = 0;
  let hi = nests[n - 1];
  let res = 0;

  while (lo <= hi) {
    let mid = Math.floor((lo + hi) / 2);

    const success = canPlace(nests, B, mid);
    if (success) {
      res = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  return res;
}

const nests = [1, 2, 4, 8, 9];
const B = 3;
console.log(AngryBirds(nests, B));
