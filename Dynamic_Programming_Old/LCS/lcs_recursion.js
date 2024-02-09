function lcs(a, b, i, j) {
  if (a[i] === undefined || b[j] === undefined) {
    return 0;
  } else if (a[i] === b[j]) {
    return 1 + lcs(a, b, i + 1, j + 1);
  } else {
    return Math.max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
  }
}

console.log(lcs("kaium", "aium", 0, 0));
// a = "kaium";
// console.log(a[5]=== undefined);
