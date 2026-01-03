#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>

using namespace std;

const int N_STACK = 2025;

typedef string infotype;

struct Stack {
    infotype info[N_STACK];
    int top;
};

void create_stack(Stack &S);
bool stack_empty(Stack S);
bool stack_full(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void emptyStack(Stack &S);

void manageAction(Stack &S_Aksi, Stack &S_Redo, infotype aksi);
int totalDamage(Stack &S);

#endif // GAME_H_INCLUDED
