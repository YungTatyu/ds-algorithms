#pragma once

#include "stack.h"

int is_balanced_min(CStack *st, const char *exp);

int is_balanced(CStack *st, const char *exp);

/**
 * Function to convert an infix expression to a postfix expression
 *
 * This function takes a mathematical expression written in infix notation
 * and converts it to postfix notation using the Shunting Yard algorithm.
 *
 * @param infix A string representing the infix expression (e.g., "a+b*(c^d-e)")
 * @return A dynamically allocated string containing the postfix expression
 *         (e.g., "abcd^e-*+")
 *         Returns NULL if memory allocation fails.
 *
 * Example:
 * Input:  "a+b*c"
 * Output: "abc*+"
 */

char *convert(const char *infix);

/**
 * Function to define precedence of operators
 *
 * @param op The operator character
 * @return The precedence level of the operator
 */
int precedence(char op);

int is_operator(char ch);
