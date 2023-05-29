#pragma once

#include <iostream>
#include <string>

static int mainMenu_UI() {
	cout << endl;
	cout << " *****************************************************" << endl;
	cout << " *                                                   *" << endl;
	cout << " *         2023 QS World University Rankings         *" << endl;
	cout << " *         ---------------------------------         *" << endl;
	cout << " *                                                   *" << endl;
	cout << " *              1 - Sign In as Admin                 *" << endl;
	cout << " *              2 - Sign In as User                  *" << endl;
	cout << " *              3 - Account Registration             *" << endl;
	cout << " *              4 - Continue as Guest                *" << endl;
	cout << " *              5 - Exit System                      *" << endl;
	cout << " *                                                   *" << endl;
	cout << " *****************************************************" << endl;
	cout << endl;

	int mainInput = 0;
	cout << "Select an Operation Number: ";
	cin >> mainInput;

	return mainInput;
}