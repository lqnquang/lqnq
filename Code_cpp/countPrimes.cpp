class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        vector <bool> primes(n + 1, true);
        primes[0] = false;
        primes[1] = false;
        int i = 2;
        while (i <= sqrt(n)) {
            while (primes[i] == false)
                i++;
            for (int j = 2; j <= n / i; j++)
                primes[i * j] = false;
            i++;
        }
        int count = 0;
        for (int i = 0; i < n; i++) 
            if (primes[i] == true)
                count++;
        return count;
    }
};
