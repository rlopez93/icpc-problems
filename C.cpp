#include <map>
#include <cassert>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;

ull submod(const vector<int> &number, vector<ull> &cons) 
{
	auto sz = number.size();
	uint start;
	
	int sum = 0;
	ull cnt = 0;

	for (uint x = 1u; x <= sz; ++x) {
		sum = 0;
		cnt = 0;
		start = sz - x;

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
	vector<vector<int>> numbers;
	vector<ull> cons;
	string st;

	while(cin >> st) {

		auto endIt = st.end(), nextDigitIt = st.begin(), nextAlphaIt = st.begin();	

		while (nextDigitIt != endIt && nextAlphaIt != endIt) {
			nextDigitIt = find_if(nextAlphaIt, endIt, isDigit);	
			nextAlphaIt = find_if(nextDigitIt, endIt, isAlph);

			if (nextDigitIt != endIt) {
				string numstr(nextDigitIt, nextAlphaIt);
				vector<int> numvec;

				for (const auto &ch : numstr) {
					numvec.push_back((ch - '0') % 3);
				}

				numbers.push_back(numvec);
			}
		}

		ull cnt = 0;

		for (const auto &vi : numbers) {
			vector<ull> cons(vi.size(), 0ull);
			cnt += submod(vi, cons);
		}

		numbers.clear();

		cout << cnt << endl;
	}

	return 0;
}
