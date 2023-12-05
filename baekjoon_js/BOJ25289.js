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

// Solution -----------------------------------
 
const solution = function () {
  const n = +input();
  const letters = input();
  console.log(letters.repeat(n));
};
 
solution();