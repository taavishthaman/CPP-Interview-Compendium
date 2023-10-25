function CountDigitsAndSpaces(str) {
  let spaces = 0;
  let chars = 0;
  let nums = 0;

  let n = str.length;

  for (let i = 0; i < n; i++) {
    if (str[i] === " ") {
      spaces++;
    } else if (
      (str[i] >= "a" && str[i] <= "z") ||
      (str[i] >= "A" && str[i] <= "Z")
    ) {
      chars++;
    } else if (str[i] >= "0" && str[i] <= "9") {
      nums++;
    }
  }

  return {
    nums,
    chars,
    spaces,
  };
}

console.log(CountDigitsAndSpaces("A Hello World 69 and 420"));
