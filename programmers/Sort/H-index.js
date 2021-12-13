function solution(citations) {
  var answer = citations
    .sort((a, b) => {
      return b - a;
    })
    .reduce((prev, el, idx) => {
      if (el >= idx + 1 && prev < el) {
        return idx + 1;
      }
      return prev;
    }, 0);
  return answer;
}
