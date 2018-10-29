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


/*
a few things =>
    I know it doesn't handle the cosmetic things, but that's okay :)
    why the header? (bits/stdc++.h)
        Well it just includes every standard library
    what is that line map<string, function<double(double, double)>> operations;?
        The map is like a dictionary, which takes the first template argument as the key and the second template argument as the value. So, I'm mapping a string (the operation) to a std::function which is templated to be written as std::function<return_type(arg1_type, arg2_type,...)>, and I define the operations underneath it with lambdas. I'm not sure how that std::function syntax works... it may be a macro? even though it looks like a function pointer syntax [return_type (*func_name)(args...);].. it doesn't as well.
    why => sstr.setstate(ios_base::eofbit); // Windows line endings
        So line endings on windows are CRLF or \r\n, and that \r after a "=" at the end of a line makes the sstr say that it's not eof yet -_-... so yeah. Knowing that "=" is the final operation, I can safely set sstr to a bad state.
    why => sscanf(value.data(), "%lf", &d);
        sscanf is a C library function (string scanf), which is simpler than putting the value back on the sstr and rereading it into a double

can you improve it?
*/
