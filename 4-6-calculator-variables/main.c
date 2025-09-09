#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define PEEK 1000
#define DUP 1001
#define SWAP 1002
#define CLEAR 1003
#define SIN 1004
#define COS 1005
#define TAN 1006
#define ASIN 1007
#define ACOS 1008
#define ATAN 1009
#define VARIABLE 1010
#define LAST 1011
#define UNKNOWN_CMD -1

void parse_number(int next_char, int start_index, char s[], int c);
int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

/* reverse Polish caculator */

int main() {
  int type;
  double op2;
  char s[MAXOP];
  _Bool last_was_command = 0;

  double variables[26];
  int last_variable = -1;
  double last_printed = 0.0;

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      last_was_command = 0;
      break;
    case SIN:
      push(sin(atof(s)));
      last_was_command = 0;
      break;
    case COS:
      push(cos(atof(s)));
      last_was_command = 0;
      break;
    case TAN:
      push(tan(atof(s)));
      last_was_command = 0;
      break;
    case ASIN:
      push(asin(atof(s)));
      last_was_command = 0;
      break;
    case ACOS:
      push(acos(atof(s)));
      last_was_command = 0;
      break;
    case ATAN:
      push(atan(atof(s)));
      last_was_command = 0;
      break;
    case VARIABLE:
      last_variable = s[0] - 'A';
      push(variables[last_variable]);
      last_was_command = 0;
      break;
    case LAST:
      push(last_printed);
      last_was_command = 0;
      break;
    case '+':
      push(pop() + pop());
      last_was_command = 0;
      break;
    case '*':
      push(pop() * pop());
      last_was_command = 0;
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      last_was_command = 0;
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
        push(pop() / op2);
      } else {
        printf("error: zero divisor\n");
      }
      last_was_command = 0;
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0) {
        push((int)pop() % (int)op2);
      }
      last_was_command = 0;
      break;
    case '=':
      op2 = pop();
      if (last_variable >= 0) {
        variables[last_variable] = op2;
        push(op2);
      } else {
        printf("error: no variable specified for assignment");
      }
      last_was_command = 0;
      break;
    case '\n':
      if (!last_was_command) {
        double r = pop();
        last_printed = r;
        printf("result: %.8g\n", r);
      }
      last_was_command = 0;
      break;
    case PEEK:
      if (sp > 0) {
        printf("top of stack: %.8g\n", val[sp - 1]);
      } else {
        printf("error: stack empty\n");
      }
      last_was_command = 1;
      break;
    case DUP:
      if (sp > 0) {
        val[sp] = val[sp - 1];
        printf("duplicated top of stack: %.8g\n", val[sp - 1]);
      } else {
        printf("error: stack empty\n");
      }
      last_was_command = 1;
      break;
    case SWAP:
      if (sp > 1) {
        double top = val[sp - 1];
        double below_top = val[sp - 2];

        val[sp - 2] = top;
        val[sp - 1] = below_top;

        printf("swapped top two two elements of stack: %.8g\n", val[sp - 1]);
      } else {
        printf("error: stack empty\n");
      }
      last_was_command = 1;
      break;
    case CLEAR:
      if (sp > 0) {
        sp = 0;

        printf("cleared stack\n");
      } else {
        printf("error: stack already empty\n");
      }
      last_was_command = 1;
      break;
    default:
      printf("error: unknown command %s\n", s);
      last_was_command = 0;
      break;
    }
  }

  return 0;
}

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void parse_number(int next_char, int start_index, char s[], int c) {
  int i = start_index;

  s[i] = next_char;

  while (isdigit(s[++i] = c = getch()))
    ;

  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';

  if (c != EOF) {
    ungetch(c);
  }
}

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (isupper(c)) {
    s[0] = c;
    s[1] = '\0';
    return VARIABLE;
  }

  if (isalpha(c)) {
    int i = 0;
    s[i++] = c;
    while (i < MAXOP - 1 && isalpha((s[i] = getch()))) {
      i++;
    }
    s[i] = '\0';
    if (strcmp(s, "peek") == 0) {
      return PEEK;
    } else if (strcmp(s, "dup") == 0) {
      return DUP;
    } else if (strcmp(s, "swap") == 0) {
      return SWAP;
    } else if (strcmp(s, "clear") == 0) {
      return CLEAR;
    } else if (strcmp(s, "sin") == 0) {
      int next_char = getch();
      parse_number(next_char, 0, s, c);
      return SIN;
    } else if (strcmp(s, "cos") == 0) {
      int next_char = getch();
      parse_number(next_char, 0, s, c);
      return COS;
    } else if (strcmp(s, "tan") == 0) {
      int next_char = getch();
      parse_number(next_char, 0, s, c);
      return TAN;
    } else if (strcmp(s, "asin") == 0) {
      int next_char = getch();
      parse_number(next_char, 0, s, c);
      return ASIN;
    } else if (strcmp(s, "acos") == 0) {
      int next_char = getch();
      parse_number(next_char, 0, s, c);
      return ACOS;
    } else if (strcmp(s, "atan") == 0) {
      int next_char = getch();
      parse_number(next_char, 0, s, c);
      return ATAN;
    } else if (strcmp(s, "last") == 0) {
      return LAST;
    } else {
      return UNKNOWN_CMD;
    }
  }

  if (c == '-') {
    int next_char = getch();

    if (isdigit(next_char) || next_char == '.') {
      parse_number(next_char, 1, s, c);

      return NUMBER;
    } else {
      ungetch(next_char);
      return '-';
    }
  }

  if (!isdigit(c) && c != '.') {
    return c; /* not a number */
  }

  i = 0;

  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';

  if (c != EOF) {
    ungetch(c);
  }

  return NUMBER;
}

int getch(void) /* get a (possibly pushed back) character */ {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */ {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
