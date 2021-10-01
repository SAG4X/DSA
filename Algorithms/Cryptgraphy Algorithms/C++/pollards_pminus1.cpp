#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
const int mod = 1e9 + 7;
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
void Pollards_pminus1();
int n;

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << "Enter n\n";
	n = 1403;	// default value for  in case of no input
	cin >> n;

	Pollards_pminus1();

	return 0;
}

int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}

int lcm_till(int B) {
	int ans = 2;
	for (int i = 3; i <= B; i++) {
		ans = lcm(ans, i);
	}
	return ans;
}

void Pollards_pminus1() {
	// for d > 1 if m has a prime factor p such that (p - 1) divides (n!)
	cout << "n = " << n << "\n\n";
	cout << "### POLLARDS p-1 Method ###\n";
	cout << "Step-1: Choose integer B>2\n";
	int B = 9;
	// cin >> B;
	cout << " B = " << B << "\n";

	cout << "\nStep-2: Choose k, which is a multiple of most of the numbers b<=B\n";
	int k = lcm_till(B);
	// cin >> k;
	cout << " k = " << k << "\n";

	cout << "\nStep-3: Choose a, which is a random number 2<=a<=n-2\n";
	int a = 2 + rand() % (n - 2);
	a = 2;	// for simplicity!
	// cin >> a;
	cout << " a = " << a << "\n";

	cout << "\nStep-4: Computing r, r cong to a^k modn\n";
	int r = power(a, k, n);
	cout << " r = " << r << "\n";

	cout << "\nStep-5: Computing d, d=gcd(r-1, n)\n";
	int d = gcd(r - 1, n);
	cout << " d = " << d << "\n";

	if (d == 1 || d == n)
		cout << " Could not find a non-trivial factor for n\n";
	else {
		cout << "\n### We got a non-trivial factor! ###\n";
		cout << d << " is a non trivial factor of " << n << "\n";
		cout << "Another factor is " << n / d << "\n";
		cout << " => " << n << " = " << d << " * " << n / d << "\n\n";
	}
}