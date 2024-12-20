#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../LinkedListStack/LinkedListStack.h"
#include <stdlib.h>

typedef enum {
  LEFT_PARENTHESIS = '(',
  RIGHT_PARENTHESIS = ')',
  PLUS = '+',
  MINUS = '-',
  MULTIPLY = '*',
  DIVIDE = '/',
  SPACE = ' ',
  OPERAND
} SYMBOL;

int IsNumber(char Cipher);
unsigned int GetNextToken(char *Expression, char *Token, int *TYPE);
int GetPriority(char Operator, int InsStack);
int IsPrior(char Operator1, char Operator2);
void GetPostfix(char *InfixExpression, char *PostfixExpression);
double Calculate(char *PostfixExpression);

#endif