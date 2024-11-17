#include "Calculator.h"

char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

int IsNumber(char Cipher) {
  int i = 0;
  int ArrayLenght = sizeof(NUMBER);

  for (i = 0; i < ArrayLenght; i++) {
    if (Cipher == NUMBER[i]) {
      return 1;
    }
  }

  return 0;
}

unsigned int GetNextToken(char *Expression, char *Token, int *TYPE) {
  unsigned int i = 0;

  for (i = 0; 0 != Expression[i]; i++) {
    Token[i] = Expression[i];

    if (IsNumber(Token[i]) == 1) {
      *TYPE = OPERAND;

      if (IsNumber(Token[i + 1]) != 1) {
        break;
      }
    } else {
      *TYPE = Expression[i];
      break;
    }

    Token[++i] = '\0';
  }

  return i;
}

int IsPrior(char Operator1, char Operator2);

void GetPostFix(char *InfixExpression, char *PostfixExpression);

double Calculate(char *PostfixExpression);