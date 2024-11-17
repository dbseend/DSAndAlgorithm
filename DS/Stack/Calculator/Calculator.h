#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../LinkedListStack/LinkedListStack.h"
#include <stdlib.h>

typedef enum {
  LEFT_PARENTHESIS = '(',
  RIGHT_PARANTHESIS = ')',
  PLUS = '+',
  MINUS = '-',
  MULTIPLY = '*',
  DVIDE = '/',
  SPACE = ' ',
  OPERAND
} SYMBOL;

int IsNumber(char Cipher);
unsigned int GetNextToken(char *Expression, char *Token, int *TYPE);
int IsPrior(char Operator1, char Operator2);
void GetPostFix(char *InfixExpression, char *PostfixExpression);
double Calculate(char *PostfixExpression);

#endif