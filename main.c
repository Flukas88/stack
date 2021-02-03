#include "list.h"

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Please provide operations to parse\n");
		exit(0);
	}

	char *token;
    double op1,op2;
    token = strtok(argv[1], " ");

    while( token != NULL ) {
        #ifdef DEBUG
        printf("Looking at %s\n", token);
        #endif
        if (is_valid_int(token) == true) {
            push(atoi(token));
        } else {
            if (strstr(token, "+") != NULL) {
                op1 = pop();
                op2 = pop();
                push(op1 + op2);
                #ifdef DEBUG
                printf("Pushing %f + %f = %f\n", op2, op1, (op1 + op2));
                #endif
            } else if (strstr(token, "-") != NULL) {
                op1 = pop();
                op2 = pop();
                push(op2 - op1);
                #ifdef DEBUG
                printf("Pushing %f - %f = %f\n", op2, op1, (op2 - op1));
                #endif
            } else if (strstr(token, "x") != NULL) {
                op1 = pop();
                op2 = pop();
                push(op1 * op2);
                #ifdef DEBUG
                printf("Pushing %f x %f = %f\n", op2, op1, (op1 * op2));
                #endif
            } else if (strstr(token, "*") != NULL) {
                op1 = pop();
                op2 = pop();
                push(op1 * op2);
                #ifdef DEBUG
                printf("Pushing %f * %f = %f\n", op2, op1, (op1 * op2));
                #endif
            }  else if (strstr(token, "/") != NULL) {
                op1 = pop();
                op2 = pop();
                #ifdef DEBUG
                printf("Pushing %f / %f = %f\n", op2, op1, (op2 / op1));
                #endif
                if ((op1 == 0.0) || (op2 == 0.0) ) { printf("Division by 0 is not possible! \n"); } else {
                    push((op2 / op1));
                }
        }

        }
        token = strtok(NULL, " ");
    }

    double res = pop();
    printf("Res = %f", res);
    return 0;
}