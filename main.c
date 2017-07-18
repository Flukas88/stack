#include "list.h"


int main() {
    char exp[] = " 5 1 2 + 4 x + 3 - 2 x";
    char *token;
    int op1,op2, cnt = 0;
    token = strtok(exp, " ");

    while( token != NULL ) {
        printf("Looking at %s\n", token);
        if (is_valid_int(token) == true) {
            push(atoi(token));
        } else {
            if (strstr(token, "+") != NULL) {
                op1 = pop();
                op2 = pop();
                push((char) op1 + op2);
                printf("Round %d Pushing %d + %d = %d\n", cnt, op1, op2, (op1 + op2));

            } else if (strstr(token, "-") != NULL) {
                op1 = pop();
                op2 = pop();
                push((char) op2 - op1);
                printf("Round %d Pushing %d - %d = %d\n", cnt, op1, op2, (op2 - op1));

            } else if (strstr(token, "x") != NULL) {
                op1 = pop();
                op2 = pop();
                push((char) op1 * op2);
                printf("Round %d Pushing %d x %d = %d\n", cnt, op1, op2, (op1 * op2));
            } else if (strstr(token, "/") != NULL) {
                op1 = pop();
                op2 = pop();
                if ((op1 == 0) || (op2 == 0) ) { printf("Division by 0 is not possible! \n"); }
                push((char) op1 / op2);
            }

        }
        cnt++;
        token = strtok(NULL, " ");
    }

    int res = pop();
    printf("Res = %d", res);
    return 0;
}