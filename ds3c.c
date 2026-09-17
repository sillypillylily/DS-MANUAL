#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an element into the stack
void push(char c)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

// Function to pop an element from the stack
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Function to view the top element
char peek()
{
    if (top == -1)
        return -1;
    else
        return stack[top];
}

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char *infix)
{
    char postfix[MAX];
    int i = 0, k = 0;
    char symbol;

    while (infix[i] != '\0')
    {
        symbol = infix[i];

        // If operand, add it to postfix
        if (isalnum(symbol))
        {
            postfix[k++] = symbol;
        }

        // If opening bracket, push it
        else if (symbol == '(')
        {
            push(symbol);
        }

        // If closing bracket, pop until '('
        else if (symbol == ')')
        {
            while (peek() != '(')
            {
                postfix[k++] = pop();
            }

            pop();   // Remove '('
        }

        // If operator
        else
        {
            while (top != -1 &&
                   precedence(peek()) >= precedence(symbol))
            {
                postfix[k++] = pop();
            }

            push(symbol);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[k++] = pop();
    }

    // End the postfix string
    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

// Main function
int main()
{
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}