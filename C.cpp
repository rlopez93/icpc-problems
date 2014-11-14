#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <numeric>
using namespace std;
typedef unsigned long long ull;

ull submod(const vector<unsigned> &number, vector<ull> &cons) 
{
	auto sz = number.size();

	for (decltype(sz) x = 1u; x <= sz; ++x) {
		auto sum = 0u;
		auto cnt = 0ull;

		auto start = sz - x;

		for (auto i = start; i < sz; ++i) {
			sum += number[i];

			if (sum % 3 == 0) {
				++cnt;

				if (i < sz - 1) {
					cnt += cons[i + 1];
				}

				cons[start] = cnt;
				break;
			}
		}
	}

	return accumulate(cons.begin(), cons.end(), 0ull);
}

bool isDigit(char c)
{
	return isdigit(c);
}

bool isAlph(char c)
{
	return isalpha(c);
}

int main()
{
	vector<vector<unsigned>> numbers;
	string st;

	while(cin >> st) {

		auto endIt = st.end(),
			nextDigitIt = st.begin(),
			nextAlphaIt = st.begin();

		while (nextDigitIt != endIt && nextAlphaIt != endIt) {
			nextDigitIt = find_if(nextAlphaIt, endIt, isDigit);
			nextAlphaIt = find_if(nextDigitIt, endIt, isAlph);

			if (nextDigitIt != endIt) {
				string numstr(nextDigitIt, nextAlphaIt);
				vector<unsigned> numvec;

				for (auto ch : numstr) {
					numvec.push_back(static_cast<unsigned>(ch - '0'));
				}

				numbers.push_back(numvec);
			}
		}

		auto cnt = 0ull;

		for (const auto &vi : numbers) {
			vector<ull> cons(vi.size(), 0ull);
			cnt += submod(vi, cons);
		}

		numbers.clear();

		cout << cnt << endl;
	}

	return 0;
}
