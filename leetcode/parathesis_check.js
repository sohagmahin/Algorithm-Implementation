// https://leetcode.com/problems/valid-parentheses/?envType=problem-list-v2&envId=oizxjoit

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  let stack = [];
  let charaters = s.split("");

  for (let i of charaters) {
    if (stack.length === 0) {
      stack.push(i);
    } else {
      let value = stack[stack.length - 1];
      if (
        (value === "(" && i === ")") ||
        (value === "{" && i === "}") ||
        (value === "[" && i === "]")
      ) {
        stack.pop();
      } else {
        stack.push(i);
      }
    }
  }

  if (stack.length === 0) {
    return true;
  } else {
    return false;
  }
};
