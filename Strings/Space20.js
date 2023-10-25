const space20 = function (arr) {
  let n = arr.length;
  let count_spaces = 0;

  for (let i = 0; i < n; i++) {
    if (arr[i] == " ") {
      count_spaces++;
    }
  }

  let length = n + 2 * count_spaces;

  for (let i = n - 1; i >= 0; i--) {
    const ch = arr[i];
    if (ch === " ") {
      arr[length - 1] = "0";
      arr[length - 2] = "2";
      arr[length - 3] = "%";

      length -= 3;
    } else {
      arr[length - 1] = ch;
      length--;
    }
  }

  return arr.join("");
};

const str = "Hello World! How are you?";
const res = space20(str.split(""));
console.log(res);
