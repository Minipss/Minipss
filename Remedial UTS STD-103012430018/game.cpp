#include "game.h"


void create_stack(Stack &S) {
    S.top = -1;
}

bool stack_empty(Stack S) {
    return S.top == -1;
}

bool stack_full(Stack S) {
    return S.top == N_STACK - 1;
}

void push(Stack &S, infotype x) {
    if (!stack_full(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = "";
    if (!stack_empty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void emptyStack(Stack &S) {
    S.top = -1;
}


void manageAction(Stack &S_Aksi, Stack &S_Redo, infotype aksi) {
    infotype temp;

    if (aksi == "UNDO") {
        if (!stack_empty(S_Aksi)) {
            temp = pop(S_Aksi);
            push(S_Redo, temp);
        }
    }
    else if (aksi == "REDO") {
        if (!stack_empty(S_Redo)) {
            temp = pop(S_Redo);
            push(S_Aksi, temp);
        }
    }
    else {
        push(S_Aksi, aksi);
        emptyStack(S_Redo);
    }
}

int totalDamage(Stack &S) {
    int total = 0;
    infotype aksi;

    while (!stack_empty(S)) {
        aksi = pop(S);
        if (aksi == "ATTACK")
            total += 30;
        else if (aksi == "DEFENSE")
            total += 5;
    }
    return total;
}
