function FindShortestPath(str) {
  let x = 0;
  let y = 0;
  const n = str.length;

  for (let i = 0; i < n; i++) {
    const ch = str[i];
    if (ch === "N") {
      y++;
    } else if (ch === "S") {
      y--;
    } else if (ch === "E") {
      x++;
    } else {
      x--;
    }
  }

  let path = "";
  if (x < 0) {
    while (x != 0) {
      path += "W";
      x++;
    }
  } else {
    while (x != 0) {
      path += "E";
      x--;
    }
  }

  if (y < 0) {
    while (y != 0) {
      path += "S";
      y++;
    }
  } else {
    while (y != 0) {
      path += "N";
      y--;
    }
  }

  return path;
}

const str = "SSEEWWNNNNSSSSWWWWEESS";
console.log(FindShortestPath(str));
