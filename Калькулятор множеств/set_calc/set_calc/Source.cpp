#include <iostream>
#include "CustomSet.h"
using namespace std;

void menu(const int num, CustomSet& a, CustomSet& b, CustomSet& c) {
	srand(time(NULL));
	switch (num) {
	case 1: {
		int left = EnterInt("LEFT boundary: ");
		int right = EnterInt("RIGHT boundary: ");
		a.SetUniversum(left, right);
		b.SetUniversum(left, right);
		c.SetUniversum(left, right);
		break;
	}
	case 2: {
		cout << "SET A:\n";
		Definition(&a);
		cout << "SET B:\n";
		Definition(&b);
		cout << "SET C:\n";
		Definition(&c);
		break;
	}
	case 3: {
		vector<int> res;
		cout << "1. Intersect A and B\n";
		cout << "2. Intersect B and C\n";
		cout << "3. Intersect A and C\n";
		int m = EnterInt("\nYour choice: ");
		switch (m) {
		case 1: {
			res = a.Intersect(b);
			print(res);
			break;
		}
		case 2: {
			res = c.Intersect(b);
			print(res);
			break;
		}
		case 3: {
			res = a.Intersect(c);
			print(res);
			break;
		}
		default: {
			cout << "Choose from the list\n";
			break;
		}
		}
		break;
	}
	case 4: {
		vector<int> res;
		cout << "1. Unite A and B\n";
		cout << "2. Unite B and C\n";
		cout << "3. Unite A and C\n";
		int m = EnterInt("\nYour choice: ");
		switch (m) {
		case 1: {
			res = a.Union(b);
			print(res);
			break;
		}
		case 2: {
			res = c.Union(b);
			print(res);
			break;
		}
		case 3: {
			res = a.Union(c);
			print(res);
			break;
		}
		default: {
			cout << "Choose from the list\n";
			break;
		}
		}

		break;
	}
	case 5: {
		vector<int> res;
		cout << "1. A\\B\n";
		cout << "2. A\\C\n";
		cout << "3. B\\A\n";
		cout << "4. B\\C\n";
		cout << "5. C\\A\n";
		cout << "6. C\\B\n";
		int m = EnterInt("\nYour choice: ");
		switch (m) {
		case 1: {
			res = a.Without(b);
			print(res);
			break;
		}
		case 2: {
			res = a.Without(c);
			print(res);
			break;
		}
		case 3: {
			res = b.Without(a);
			print(res);
			break;
		}
		case 4: {
			res = b.Without(c);
			print(res);
			break;
		}
		case 5: {
			res = c.Without(a);
			print(res);
			break;
		}
		case 6: {
			res = c.Without(b);
			print(res);
			break;
		}
		default: {
			cout << "Choose from the list\n";
			break;
		}
		}
		break;
	}
	case 6: {
		vector<int> res;
		cout << "1. Difference of A and B\n";
		cout << "2. Difference of B and C\n";
		cout << "3. Difference of A and C\n";
		int m = EnterInt("\nYour choice: ");
		switch (m) {
		case 1: {
			res = a.Difference(b);
			print(res);
			break;
		}
		case 2: {
			res = b.Difference(c);
			print(res);
			break;
		}
		case 3: {
			res = a.Difference(c);
			print(res);
			break;
		}
		default: {
			cout << "Choose from the list\n";
			break;
		}
		}
		break;
	}
	case 7: {
		vector<int> res;
		cout << "1. -A\n";
		cout << "2. -B\n";
		cout << "3. -C\n";
		int m = EnterInt("\nYour choice: ");
		switch (m) {
		case 1: {
			res = a.Complement();
			print(res);
			break;
		}
		case 2: {
			res = b.Complement();
			print(res);
			break;
		}
		case 3: {
			res = c.Complement();
			print(res);
			break;
		}
		default: {
			cout << "Choose from the list\n";
			break;
		}
		}
		break;
	}
	default: {
		cout << "Choose from the list\n";
		break;
	}
	}
}

int main() {
	string path = "myFile.txt";
	CustomSet a; 
	CustomSet b; 
	CustomSet c; 
	ReadFile(path, a, b, c);
	while (true) {
		system("pause");
		system("cls");
		cout << "SET A: ";  a.Print();
		cout << "SET B: ";  b.Print();
		cout << "SET C: ";  c.Print();
		cout << "\n1. Define universum\n";
		cout << "2. Set sets :]\n";
		cout << "3. Intersect two sets\n";
		cout << "4. Unite two sets\n";
		cout << "5. Difference of two sets\n";
		cout << "6. Symmetrical dfference of two sets\n";
		cout << "7. Complement of one set\n";
		int num = EnterInt("\nYour choice: ");
		menu(num, a, b, c);
	}

	return 0;
}