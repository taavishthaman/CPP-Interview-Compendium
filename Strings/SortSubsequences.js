function findSubsets(s, o, op) {
  if (s.length === 0) {
    op.push(o);
    return;
  }

  let ch = s[0];
  let ros = s.substr(1);

  findSubsets(ros, o, op);
  findSubsets(ros, o + ch, op);
}

function compare(s1, s2) {
  if (s1.length === s2.length) {
    if (s1 < s2) {
      return -1;
    } else if (s1 === s2) {
      return 0;
    } else {
      return 1;
    }
  }

  return s1.length - s2.length;
}

function SortSubsequences(str) {
  const op = [];
  findSubsets(str, "", op);
  op.sort(compare);

  for (let i = 0; i < op.length; i++) {
    console.log(op[i]);
  }
}

SortSubsequences("abc");
