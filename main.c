#include "list.h"


int main(int arc, char **argv) {
    char *token;
    double op1,op2;
    int cnt = 0;
    token = strtok(argv[1], " ");

    while( token != NULL ) {
        printf("Looking at %s\n", token);
        if (is_valid_int(token) == true) {
            push(atoi(token));
        } else {
            if (strstr(token, "+") != NULL) {
                op1 = pop();
                op2 = pop();
                push(op1 + op2);
                printf("Round %f Pushing %f + %f = %f\n", cnt, op1, op2, (op1 + op2));

            } else if (strstr(token, "-") != NULL) {
                op1 = pop();
                op2 = pop();
                push(op2 - op1);
                printf("Round %f Pushing %f - %f = %f\n", cnt, op1, op2, (op2 - op1));

            } else if (strstr(token, "x") != NULL) {
                op1 = pop();
                op2 = pop();
                push(op1 * op2);
                printf("Round %f Pushing %f x %f = %f\n", cnt, op1, op2, (op1 * op2));
            } else if (strstr(token, "/") != NULL) {
                op1 = pop();
                op2 = pop();
                printf("Round %f Pushing %f / %f = %f\n", cnt, op1, op2, (op2 / op1));
                if ((op1 == 0.0) || (op2 == 0.0) ) { printf("Division by 0 is not possible! \n"); } else {
                    push((op2 / op1));
                }
        }

        }
        cnt++;
        token = strtok(NULL, " ");
    }

    double res = pop();
    printf("Res = %f", res);
    return 0;
}