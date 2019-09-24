#include<iostream>
int N;
int main()
{
	std::cin >> N; N /= 10;
	std::cout << N + 2 * (N / 5) + (N % 5) / 3; 
	return 0;
}
