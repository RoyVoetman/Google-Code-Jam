#include <iostream>

using namespace std;

int main() {
    int T, K;
    string S;


    /* ask for the amount of test cases */
    cin >> T;
    cin >> ws; // stream out any whitespace

    for(int i = 0; i < T; i++) {
        /* ask a pancake row + flipper size */
        cin >> S >> K;

        int steps = 0;
        bool possible = true;
        int pancake_amount = S.length();
        bool pancakes[ pancake_amount ];

        /* generate boolean array of pancakes */
        for(int j = 0; j < pancake_amount; j++)
            pancakes[j] = (S[j] == '+');

        /* Flip pancakes when a 'blank size' found */
        for(int j = 0; j <= pancake_amount - K; j++) {

            /* when current pancake is 'blank size' flip 'K' pancakes from left to right */
            if(!pancakes[j]) {
                for(int x = 0; x < K; x++) {
                    pancakes[j + x] = !pancakes[j + x];
                }
                steps++;
            }

        }

        /* check if all pancakes are happy size */
        for(int j = 0; j < pancake_amount; j++) {
            if( pancakes[j] != pancakes[0] ) {
                possible = false;
                break;
            }
        }

        /* print cases result */
        if(possible) cout << "Case #" << i+1 << ": " << steps;
        else cout << "Case #" << i+1 << ": IMPOSSIBLE";

        cout << endl;

    }


    return 0;
}