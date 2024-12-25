ll MOD = 1000000007

vector<bool> p(MAX_N+1, true);
void sieve(int n) { 
    for (int k = 2; k * k <= n; k++) {
        if (p[k] == true) {
            for (int i = k * k; i <= n; i += k) {
                p[i] = false;
            }
        }
    }
}

ll modexp (ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return (res + p) % p;
}
 
ll modinv (ll x, ll p) {
    return modexp(x, p - 2, p);
}

ll add (ll x, ll y) {
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

ll mult (ll x, ll y) {
    return (x * 1ll * y) % MOD;
}

ll divide (ll x, ll y) {
    return mult(x, modinv(y));
}

ll gcd(ll a, ll b) { 
    if (a == 0) 
        return b; 
    if (b == 0) 
        return a; 
    if (a == b) 
        return a; 
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll fact[MAX_N];
ll choose(ll N, ll M) {
    ll ans = fact[N + M - 1] * modinv(fact[N - 1], MOD) % MOD;
    ans = ans * modinv(fact[M], MOD) % MOD;
}

// Notable Uses:

// Sieve:                 sieve(n);
// Sets an array of prime-checking up to a specified MAX_N.
// For example, sieve(5) would get us p[5] = true, but p[7] would be undefined.

// x^y (mod p):           modexp(x, y, p);
// Modular exponentiation; basically just find x^y (mod p) in time without overflow.

// Mod Inverse:           modinv(x, p);
// Modular inverse; basically just used in division about a modulo. 

// Add:                   add(x, y);
// Subtract:              add(x, -y);
// Multiply:              mult(x, y);
// Divide:                divide(x, y);
// Note that y must be relatively prime to your prime p for divide to work! You cannot do modulo division otherwise. 

// GCD:                   gcd(x, y);
// It returns the greatest common divisor of x and y. 

// Choose:                choose(x, y);
// It returns x choose y.
