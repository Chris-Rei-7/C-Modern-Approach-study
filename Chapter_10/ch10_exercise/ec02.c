#include <stdio.h>
#include <stdlib.h>  // 为了使用 exit()
#include <stdbool.h>

#define STACK_SIZE 100

// -----------------------------------------
// 1. 栈的底层实现 (用于存储整数)
// -----------------------------------------
int contents[STACK_SIZE];
int top = 0;

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

// 压栈操作
void push(int i) {
    if (is_full()) {
        // 题目要求：栈溢出时提示太复杂并终止
        printf("Expression is too complex\n");
        exit(EXIT_FAILURE);
    } else {
        contents[top++] = i;
    }
}

// 出栈操作
int pop(void) {
    if (is_empty()) {
        // 题目要求：栈空时说明操作数不够，终止程序
        printf("Not enough operands in expression\n");
        exit(EXIT_FAILURE);
    } else {
        return contents[--top];
    }
}

// -----------------------------------------
// 2. 主逻辑：逆波兰表达式求值
// -----------------------------------------
int main(void) {
    char ch;
    int op1, op2; // 用于暂存从栈里弹出的两个操作数

    // 外层循环：不断提示用户输入新的表达式
    while (1) {
        printf("Enter an RPN expression: ");

        // 内层循环：逐个读取字符，直到遇到 '=' 或者退出指令
        while (1) {
            scanf(" %c", &ch); // 注意 %c 前面的空格，它能自动忽略空格和换行符

            // 规则 1：如果是数字 (0-9)，把它从字符转换为整数并压入栈
            if (ch >= '0' && ch <= '9') {
                push(ch - '0'); // '5' - '0' 会得到整数 5
            } 
            // 规则 2：如果是运算符，弹出两个数字计算后，把结果压回栈
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                // ⚠️ 极其重要的细节：先弹出的是右操作数，后弹出的是左操作数！
                // 对于减法和除法，顺序绝对不能错！
                op2 = pop(); 
                op1 = pop(); 

                switch (ch) {
                    case '+': push(op1 + op2); break;
                    case '-': push(op1 - op2); break;
                    case '*': push(op1 * op2); break;
                    case '/': push(op1 / op2); break;
                }
            } 
            // 规则 3：如果遇到 '='，说明表达式结束，打印结果并准备下一轮
            else if (ch == '=') {
                printf("Value of expression: %d\n", pop());
                make_empty(); // 清空栈，为下一条表达式做准备
                break;        // 跳出内层循环，重新打印 "Enter an RPN expression:"
            } 
            // 规则 4：如果输入的既不是数字、运算符也不是等号（比如字母 'q'）
            else {
                return 0; // 正常结束整个程序
            }
        }
    }
    return 0;
}