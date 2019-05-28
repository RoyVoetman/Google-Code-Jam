#include <iostream>

using namespace std;

int main() {

    int case_amount;

    /* Ask the amount of test cases (T) */
    cin >> case_amount;

    /* For each test case */
    for (int t = 0; t < case_amount; t++) {

        int shield, swap_amount = 0;
        string program;

        cin >> shield >> program;

        while (true) {
            int shield_damage = 0, shoot_amount = 0, shoot_power = 1;

            for (int i = 0; i < program.length(); ++i) {

                if (program[i] == 'S') {

                    shoot_amount++;

                    shield_damage = shield_damage + shoot_power;

                } else {
                    shoot_power = shoot_power * 2;
                }

            }

            if (shield_damage <= shield) {
                cout << "Case #" << t + 1 << ": " << swap_amount << '\n';
                break;
            } else if (shoot_amount > shield) {
                cout << "Case #" << t + 1 << ": IMPOSSIBLE" << '\n';
                break;
            } else {

                bool last_shoot = false;

                /* program in reverse */
                for (long x = program.length() - 1; x >= 0; x--) {
                    if (program[x] == 'S') {
                        last_shoot = true;
                    } else if (last_shoot && program[x] == 'C') {
                        program[x] = program[x + 1];
                        program[x + 1] = 'C';

                        swap_amount++;

                        break;
                    }
                }
            }

        }
    }

    return 0;
}