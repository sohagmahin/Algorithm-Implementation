// https://leetcode.com/problems/longest-consecutive-sequence/description/

function longestConsecutive(array) {
  const maps = new Map();
  let longest = 0;

  for (let num of array) {
    maps.set(num, false);
  }

  for (let num of array) {
    maps.set(num, true);
    let currentMax = 1;

    // forward move
    let nextNum = num + 1;
    while (maps.has(nextNum) && !maps.get(nextNum)) {
      maps.set(nextNum, true);
      currentMax++;
      nextNum++;
    }

    // backward move
    let prevNum = num - 1;
    while (maps.has(prevNum) && !maps.get(prevNum)) {
      maps.set(prevNum, true);
      currentMax++;
      prevNum--;
    }

    longest = Math.max(longest, currentMax);
  }
  console.log(maps);
  return longest;
}

console.log(longestConsecutive([100, 4, 200, 1, 3, 2]));
