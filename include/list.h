#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>
#include <stdbool.h>

#ifndef size
#define size 25
#endif

struct stack {
    double s[size];
    int top;
} st;

bool stfull() {
    if (st.top >= size - 1)
        return true;
    else
        return false;
}

void push(double item) {
    st.top++;
    st.s[st.top] = item;
}

bool stempty() {
    if (st.top == -1)
        return true;
    else
        return false;
}

double pop() {
    char item;
    item = st.s[st.top];
    st.top--;
    return (item);
}

void display() {
    int i;
    if (stempty())
        printf("\nStack Is Empty!");
    else {
        for (i = st.top; i >= 0; i--)
            printf("\n%f", st.s[i]);
    }
}


bool is_valid_int(const char *str)
{
    // Handle negative numbers.
    //
    if (*str == '-')
        ++str;

    // Handle empty string or just "-".
    //
    if (!*str)
        return false;

    // Check for non-digit chars in the rest of the string.
    //
    while (*str)
    {
        if (!isdigit(*str))
            return false;
        else
            ++str;
    }

    return true;
}
