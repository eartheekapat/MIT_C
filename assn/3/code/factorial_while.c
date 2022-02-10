int factorial(int n) {
    int i, ret = 1;
    while (i <= n) {
        ret *= i;
        i++;
    }
    return ret;
}