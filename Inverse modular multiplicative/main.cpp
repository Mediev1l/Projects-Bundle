#include <iostream>
#include <vector>

int invmod(int n, int a)
{
	std::vector<int> s{ 0,1 }, x{ 1 }, t{ 0,1 }, r{ n,a }, q( 2 );
	int i = 1;

	do {
		int tempQ{};
		int tempR{};
		int tempS{};

		tempQ = r[i - 1] / r[i];
		q.push_back(tempQ);

		tempR = r[i - 1] - (q[i + 1] * r[i]);
		r.push_back(tempR);

		if (r[i + 1] == 0) 	break;

		tempS = s[i - 1] - (q[i + 1] * s[i]);
		s.push_back(tempS);
	} while (r[i++] != 0);

	if (r[i] == 1 && s[i] > 0) 	return s[i];
	else if (r[i] == 1 && s[i] < 0) return s[i] + n;
	else if (r[i] == 0 && r[i - 1] != 1) return -1;

	return -1;
}

int main() 
{
	std::cout << invmod(1234, 4321) << '\n';
	return 0;
}
