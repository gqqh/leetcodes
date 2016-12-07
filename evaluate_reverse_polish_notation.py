#-*- coding:utf8 -*-
"""
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
"""

class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        if len(tokens) < 1:
            return -1
        datas = []
        for i in tokens:
            if i in "+-*/":
                op2 = datas.pop()
                op1 = datas.pop()
                if i == '/':
                    if int(op1) / int(op2) < 0 and int(op1) % int(op2) != 0:
                        datas.append(int(op1)/int(op2) + 1)
                    else:
                        datas.append(int(op1)/int(op2))
                else:
                    datas.append(eval(str(op1) + i + str(op2)))
            else:
                datas.append(i)

        return int(datas[0])


if __name__ == "__main__":
    test = Solution()
    #print test.evalRPN(["2", "1", "+", "3", "*"])
    #print test.evalRPN(["3", "-3", "/"])
    print test.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])
