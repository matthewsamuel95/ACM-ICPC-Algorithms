/* Balanced Parantheses */

function isBalanced(expr) {
  var s = [];
  for (var i = 0; i < expr.length; i++) {
    var ch = expr.charAt(i);
    if (ch == '(' || ch == '{' || ch == '[')
      s.push(ch);
    else if (ch == ')' || ch == '}' || ch == ']') {
      if (ch == ')' && top(s) == '(')
        s.pop();
      else if (ch == '}' && top(s) == '{')
        s.pop();
      else if (ch == ']' && top(s) == '[')
        s.pop();
      else
        return false;
    }
  }

  return s.length == 0;
}

// Finding the Top of the Stack s.
// For empty stack Top is -1
function top(s) {
  var len = s.length
  return len > 0 ? s[len - 1] : -1;
}

var expressions = [
  "{[()]}",
  "{[(])}",
  "{{[[(())]]}}",
  "]{[()]()}",
  "{[()])(}"
];
expressions.forEach(function(e) {
  var areBalanced = isBalanced(e);
  if (areBalanced)
    console.log(e + " is Balanced");
  else
    console.log(e + " is Not Balanced");
});