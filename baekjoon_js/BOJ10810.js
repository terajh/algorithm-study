const fs = require('fs');
const stdin = fs.readFileSync('./input.txt').toString().split('\n');
// const stdin = fs.readFileSync('/dev/stdin').toString().split('\n');

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
    console.log(input.rows.num(m).reduce((arr, cur) => {
        const [from, to, num] = cur;
        for (let i = from; i <= to; i++) {
            arr[i] = num;
        }
        return arr;
    }, Array(n+1).fill(0)).slice(1).join(' '));
};
solved();
