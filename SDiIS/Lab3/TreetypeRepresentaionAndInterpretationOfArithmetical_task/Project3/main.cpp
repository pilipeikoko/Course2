#include "Line_error.h"
#include "Math_error.h"
#include "Initialization_error.h"
#include "Assign_expression.h"
#include "Math_expression.h"



int main() noexcept(false) {

	Math_expression math_expression;
	Assign_expression assign_expression;
	string line;
	while (1) {
		getline(cin, line);
		try {
			if (!assign_expression.is_assgignment(line)) {
				line = assign_expression.assign_variables(line);
				cout << math_expression.compute_value(line) << endl;
				assign_expression.memory_clear();
			}
			else
				assign_expression.put_variables_into_kb(line);
		}
		catch (Line_error error) {
			cerr << error.get_message();
		}
		catch (Initizalization_error error) {
			cerr << error.get_message();
		}
		catch (Math_error error) {
			cerr << error.get_message();
		}
	}
}