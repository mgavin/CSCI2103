#include <bits/stdc++.h>

using namespace std;

int main() {
	string expression, value;
	stringstream sstr;
	stack<double> operands;
	map<string, function<double(double, double)>> operations;
	operations["+"] = [](double a, double b) { return a + b; };
	operations["-"] = [](double a, double b) { return a - b; };
	operations["*"] = [](double a, double b) { return a * b; };
	operations["/"] = [](double a, double b) { return a / b; };

	while (cin.good()) {
		getline(cin, expression);
		sstr << expression;
		while (sstr.good()) {
			sstr >> value;
			if (operations.find(value) != end(operations)) {
					double v2 = operands.top(); operands.pop();
					double v1 = operands.top(); operands.pop();
					operands.push(operations[value](v1, v2));
			}
			else if (value == "=") {
				cout << operands.top() << endl; operands.pop();
				sstr.setstate(ios_base::eofbit); // Windows line endings
			}
			else {
				double d;
				sscanf(value.data(), "%lf", &d);
				operands.push(d);
			}
		}
		sstr.clear();
	}
}
