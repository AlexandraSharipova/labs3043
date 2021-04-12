double fabsl(double x) {
    if (x >= 0)
        return x;
    else return x * (-1);
}
double count_pi(double a) {
    double S1 = 0, S2 = 0, i = 0, pi;
    do {
        i++;
        S1 = S2 + 1.0 / (2.0 * i - 1.0);
        i++;
        S2 = S1 - 1.0 / (2.0 * i - 1.0);
    } while (fabsl(S1 - S2) >= a);
    pi = 2.0 * (S1 + S2);
    return pi;
}
int main() {
    double r = 0.1, p;
    double pi[6] = { 3.1578643578, 3.1417811372, 3.1415946416, 3.1415926735, 3.1415926537, 3.1415926535 };
    int a = 0, b = 6, answ;
    while (a < b) {
        p = count_pi(r);
        if (fabsl(p - pi[a]) < r)
            answ = 0;
        else answ = 1;
        r = r / 10.0;
        a++;
        if (answ == 1)
            break;
    }
    return answ;
}
