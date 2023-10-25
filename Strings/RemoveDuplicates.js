function RemoveDuplicates(str) {
  let str_arr = [];
  let n = str.length;

  for (let i = 0; i < n; i++) {
    str_arr.push(str[i]);
  }

  //Sort the string
  str_arr.sort((a, b) => a.charCodeAt(0) - b.charCodeAt(0));

  let op = "";
  let i = 0;
  for (i = 0; i < n - 1; i++) {
    if (str_arr[i] != str_arr[i + 1]) {
      op += str_arr[i];
    }
  }

  op += str_arr[i];

  return op;
}

const res = RemoveDuplicates("acccbdbdxbdbdddd");
console.log(res);
