let col;

function compareNumeric(arr1, arr2) {
  return Number(arr1[col]) - Number(arr2[col]);
}

function compareString(arr1, arr2) {
  if (arr1[col] < arr2[col]) return -1;
  else if (arr1[col] === arr2[col]) return 0;
  return 1;
}

function StringKeySort(arr, c, type) {
  const string_arr = arr.map((el) => el.split(" "));
  col = c - 1;
  if (type === "numeric") {
    string_arr.sort(compareNumeric);
  } else {
    string_arr.sort(compareString);
  }

  console.log(string_arr);
}

const arr = ["92 022", "82 12", "77 13"];

const res = StringKeySort(arr, 2, "numeric");
