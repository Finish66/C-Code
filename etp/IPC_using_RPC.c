//Q3 Wrie a C program to perform IPC using RPC.

#include <stdio.h>
#include "add.h"

void main() {
    CLIENT *clnt;
    int *result, x = 3, y = 4;

    clnt = clnt_create("localhost", ADDPROG, ADDVERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(ADDPROG);
        exit(1);
    }

    result = add_1(&x, &y, clnt);
    if (result == NULL) {
        clnt_perror(clnt, "call failed");
    } else {
        printf("Result: %d\n", *result);
    }

    clnt_destroy(clnt);
}
