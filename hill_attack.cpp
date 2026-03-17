#include "hill_attack.h"
#include <iostream>

namespace hill_attack {

int mod26(int x) {
    x %= 26;
    if (x < 0) x += 26;
    return x;
}

int inv(int a) {
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1)
            return i;
    return 1;
}

void known_plain_attack(const std::string &p,
                        const std::string &c) {

    int p1 = p[0]-'A', p2 = p[1]-'A';
    int p3 = p[2]-'A', p4 = p[3]-'A';

    int c1 = c[0]-'A', c2 = c[1]-'A';
    int c3 = c[2]-'A', c4 = c[3]-'A';

    int det = mod26(p1*p4 - p2*p3);
    int detInv = inv(det);

    int k11 = mod26((c1*p4 - c2*p3) * detInv);
    int k12 = mod26((c2*p1 - c1*p2) * detInv);
    int k21 = mod26((c3*p4 - c4*p3) * detInv);
    int k22 = mod26((c4*p1 - c3*p2) * detInv);

    std::cout << "\n[Hill Known Plaintext Attack]\n";
    std::cout << "Recovered Matrix:\n";
    std::cout << k11<<" "<<k12<<"\n"<<k21<<" "<<k22<<"\n";
}

}
