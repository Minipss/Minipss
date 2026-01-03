#include <iostream>
#include "game.h"
using namespace std;

int main() {
    Stack S_Aksi, S_Redo;
    string aksi;

    create_stack(S_Aksi);
    create_stack(S_Redo);

    cout << "Masukkan aksi pemain (ATTACK / DEFENSE / UNDO / REDO)\n";
    cout << "Ketik STOP untuk selesai\n\n";

    while (true) {
        cout << "Aksi: ";
        cin >> aksi;

        if (aksi == "STOP")
            break;

        manageAction(S_Aksi, S_Redo, aksi);
    }

    cout << "\nTotal Damage = " << totalDamage(S_Aksi) << endl;
    return 0;
}
