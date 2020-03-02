#pragma once
#include <random>
#include <iostream>
#include <cmath>

int _N;
int _M;

long double randBound(long double a, long double b) {
	return (b - a) * ((long double)rand() / (long double)RAND_MAX);
}

long long fac(long long min, long long max) {
	long long result = 1;
	for (long long i = min; i <= max; i++) {
		result *= i;
	}
	return result;
}

long long fac(long long max) {
	return fac(1, max);
}

long double Ckn(long long k, long long n) {
	return (long double)fac(n) / (long double)(fac(k) * fac(n - k));
}

long double Pi(long double p, long long r, long long n) {
	long double q = 1 - p;
	//return Ckn(n, r) * powl(p, n) * powl(q, r - n);
	return (long double)Ckn(n, _N) * (long double)Ckn(r - n, _M - _N) / (long double)Ckn(r, _M);
}

void process(int N, int M, int r) {
	long long n = (long long)((long double)M * (long double)randBound(0, 1));
	long double p = (long double)N / (long double)M;

	_N = N;
	_M = M;

	long double t = 0;
	for (int k = 0; k < r; k++) {
		//t += (long double)Ckn(k, N) * (long double)Ckn(r - k, M - N) / (long double)Ckn(r, M);
		t += Pi(p, r, k);
	}

	std::cout << "if n = " << n << " in r = " << r << " then Pi: " << Pi(p, r, n) << " for N = " << N << " bad in M = " << M << std::endl;
}