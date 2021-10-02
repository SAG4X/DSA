#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
const int mod = 1e9 + 7;
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
void Pollards_rho();
int n;

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << "Enter n\n";
	n = 1403;	// default value for  in case of no input
	cin >> n;

	Pollards_rho();

	return 0;
}

int f(int x) {
	return (power(x, 2) + 1 ) % n;
}

void Pollards_rho() {
	cout << "n = " << n << "\n\n";
	cout << "### POLLARDS RHO Method ###\n";
	cout << "Step-1: Choose a non-linear map function \n(taking it f(x) = x^2 + 1)\n";

	cout << "\nStep-2: Perform successive iteration k times \n";
	int x0 = 3, k = 4;
	map<int, int> X;
	X[0] = x0;
	cout << "x0 = " << x0 << "\n";
	for (int i = 1; i <= k; i++) {
		X[i] = f(X[i - 1]);
		cout << "x" << i << " = " << X[i] << "\n";
	}

	cout << "\nStep-3: Computing g = gcd(xj-xk,n)\n";
	cout << "(if g is a non-trivial factor value, it's also a non-trivial factor of n)\n";
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j <= k; j++) {
			int g = gcd(abs(X[i] - X[j]), n);
			cout << " GCD(abs(x" << i << " - x" << j << "), " << n << ") = " << g << "\n";
			if (g != 1 && g != n) {
				cout << "\n ### We got a non-trivial factor! ###\n";
				cout << g << " is a non trivial factor of " << n << "\n";
				cout << "Another factor is " << n / g << "\n";
				cout << " => " << n << " = " << g << " * " << n / g << "\n\n";
				return;
			}
		}
	}
	cout << "\n Could not find a non-trivial factor for n\n";
}