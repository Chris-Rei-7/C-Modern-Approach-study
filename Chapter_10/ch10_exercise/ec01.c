#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // 为了使用 exit()

#define STACK_SIZE 100

// -----------------------------------------
// 1. 栈的底层实现 (数据类型已从 int 改为 char)
// -----------------------------------------
char contents[STACK_SIZE];
int top = 0;

void stack_overflow(void) {
    printf("Stack overflow\n");
    exit(EXIT_FAILURE); // 立即终止程序
}

void stack_underflow(void) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE); 
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

// 压入字符
void push(char ch) {
    if (is_full()) {
        stack_overflow();
    } else {
        contents[top++] = ch;
    }
}

// 弹出字符
char pop(void) {
    if (is_empty()) {
        stack_underflow();
        return '\0'; 
    } else {
        return contents[--top];
    }
}

// -----------------------------------------
// 2. 主逻辑：括号匹配检查
// -----------------------------------------
int main(void) {
    char ch, popped_ch;
    bool is_nested_properly = true; // 标志位：假设一开始是匹配的

    printf("Enter parentheses and/or braces: ");

    // 逐个字符读取，直到用户按下回车键
    while ((ch = getchar()) != '\n') {
        
        // 规则 1：遇到左括号，统统压入栈中等候
        if (ch == '(' || ch == '{') {
            push(ch);
        }
        // 规则 2：遇到右括号，准备出栈比对
        else if (ch == ')' || ch == '}') {
            
            // 【防崩溃关键】：在 pop 之前先查一下栈是不是已经空了
            // 如果栈是空的，说明来了一个右括号，但没有左括号等它，直接判定失败
            if (is_empty()) {
                is_nested_properly = false;
                break; // 已经发现错误，没必要继续往后看了，跳出循环
            }

            // 弹出栈顶最近的那个左括号
            popped_ch = pop();

            // 规则 3：检查弹出的左括号和当前的右括号是不是“原配”
            if ((ch == ')' && popped_ch != '(') || 
                (ch == '}' && popped_ch != '{')) {
                is_nested_properly = false;
                break; // 种类不匹配（比如把 } 和 ( 凑一起了），跳出循环
            }
        }
    }

    // 终极审判：必须满足两个条件才算完全正确嵌套：
    // 1. 中间没出过任何差错 (is_nested_properly 仍然为 true)
    // 2. 栈必须被清空了 (如果栈不为空，说明还有左括号孤单地留在里面)
    if (is_nested_properly && is_empty()) {
        printf("Parentheses/braces are nested properly\n");
    } else {
        printf("Parentheses/braces are NOT nested properly\n");
    }

    return 0;
}