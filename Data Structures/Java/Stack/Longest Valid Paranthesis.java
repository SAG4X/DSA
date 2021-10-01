
class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') stack.push(i);
            else if (c == ')') {
                if (stack.size() > 1 && s.charAt(stack.peek()) == '(') stack.pop();
                else stack.push(i);
            }
        }
        int res = 0, last = s.length();
        while (!stack.isEmpty()) {
            int curr = stack.pop();
            res = Math.max(last-curr-1, res);
            last = curr;
        }
        return res;
    }
}
