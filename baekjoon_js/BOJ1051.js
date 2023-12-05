// @BOJ ------------------------------------------
const fs = require('fs');
const stdin = fs.readFileSync('/dev/stdin').toString().split('\n');

const input = (() => {
  let line = 0;
  const input = () => stdin[line++];
  input.num = () => input().split(' ').map(Number);
  input.rows = l => Array(l).fill().map(input);
  input.rows.num = l => Array(l).fill().map(input.num);
  return input;
})();

// solved
const solved = () => {
  const [n, m] = input.num();
  const arr = input.rows(n).map(el => el.split(''));

  let start = 0,
    width = 0,
    result = 1;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      start = arr[i][j];
      for (let k = j+1; k < m; k++) {
        width = k - j + 1;

        if ( i + width - 1 < n &&
          start === arr[i][k] &&
          start === arr[i+k-j][j] &&
          start === arr[i+k-j][k]) {
            result = Math.max(result, width * width);
          }
      }
    }
  }

  console.log(result);
}
solved();