#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class CustomSet;

int Partition(vector<int>&, int, int);
void QuickSort(vector<int>&, int, int);
bool FoundBefore(vector<int>&, int, int);
void print(vector<int>&);
vector<int> Unite(vector<int>, vector<int>);
vector<int> Intersection(vector<int>, vector<int>);
vector<int> without(vector<int>, vector<int>);
int EnterInt(string);
void ReadFile(string, CustomSet&, CustomSet&, CustomSet&);
void Definition(CustomSet*);

class CustomSet {
    vector<int> set;
	int leftUniversum = -10;
	int rightUniversum = 10;

	void Sort();
public:
	CustomSet();
	void Define();
	void Define(vector<int>);
	void DefineRandom();
	void DefineCondition(int);
    void Print();
	void SetUniversum(int, int);
	vector<int> Intersect(CustomSet);
	vector<int> Union(CustomSet);
	vector<int> Without(CustomSet);
	vector<int> Difference(CustomSet);
	vector<int> Complement();

};

void CustomSet::DefineCondition(int num) {
	system("cls");
	this->set.clear();
	int number, n = numeric_limits<int>::infinity();
	for (int i = leftUniversum; i <= rightUniversum; ++i) {
		if (num == 1) { //even
			system("cls");
			if (abs(i) % 2 == 0) set.push_back(i);
			cout << "Current set: "; print(this->set);
		}
		if (num == 2) { //odd
			system("cls");
			if (abs(i) % 2 == 1) set.push_back(i);
			cout << "Current set: "; print(this->set);
		}
		if (num == 3) { //negative
			system("cls");
			if (i < 0) set.push_back(i);
			cout << "Current set: "; print(this->set);
		}
		if (num == 4) {//multiplicity
			system("cls");
			if ((n == numeric_limits<int>::infinity())||(n==0)) n = EnterInt("Enter n: ");
			else if (i % n == 0) set.push_back(i);
			cout << "Current set: "; print(this->set);
		}
	}
	
}

void CustomSet::DefineRandom() {
	srand(time(NULL));
	this->set.clear();
		int size = EnterInt("Enter the size of a set: ");
	while (size > abs(rightUniversum - leftUniversum) + 1) {
		if (size != numeric_limits<int>::infinity()) {
			cout << "\tUnavailable size. Max size is " << abs(rightUniversum - leftUniversum) + 1 << "\n";
		}
		size = EnterInt("Enter the size of a set: ");
		system("pause");
		system("cls");
	}
	for (int i = 0; i < size; ++i) {
		system("cls");
		int number = rand() % abs(rightUniversum - leftUniversum + 1) + leftUniversum;
		while (FoundBefore(set, i, number)) {
			number = rand() % abs(rightUniversum - leftUniversum + 1) + leftUniversum;
		}
		set.push_back(number);
		cout << "Current set: "; print(this->set);
	}
	
}

void CustomSet::Define(vector<int> v) {
	this->set = v;
}

void CustomSet::Define() {
	system("cls");
	this->set.clear();
	int size, number;
	size = EnterInt("Enter the size of a set: ");
	while (size > abs(rightUniversum - leftUniversum) + 1) {
		if (size != numeric_limits<int>::infinity()) {
			cout << "\tUnavailable size. Max size is " << abs(rightUniversum - leftUniversum) + 1 << "\n";
		}
		size = EnterInt("Enter the size of a set: ");
		system("pause");
		system("cls");
	}
	for (int i = 0; i < size; ++i) {
		system("cls");
		cout << "Current set: "; print(this->set);
		number = EnterInt("Enter element: ");
		while (FoundBefore(set, i, number) || (number<leftUniversum) || (number > rightUniversum)) {
			cout << "\tPlease, enter a unique element in universum boundaries\n";
			number = EnterInt("Enter element: ");
		}
		set.push_back(number);
	}
}

void CustomSet::SetUniversum(int leftUniversum, int rightUniversum) {
	if (leftUniversum > rightUniversum) swap(leftUniversum, rightUniversum) ;
	this->leftUniversum = leftUniversum;
	this->rightUniversum = rightUniversum;
	this->Sort();
	if ((this->set[0] < leftUniversum) || (this->set[set.size() - 1] > rightUniversum)) {
		cout << "Previous set is out of the universum. Please, redefine it\n";
		system("pause");
		this->Define();
		this->Sort();
	}
}
 
vector<int> CustomSet::Complement() {
	vector<int> UNIVERSUM;
	for (int i = leftUniversum; i <= rightUniversum; ++i) {
		UNIVERSUM.push_back(i);
	}
	return without(UNIVERSUM, this->set);
}

vector<int> CustomSet::Difference(CustomSet other) {
	vector<int> first = this->Without(other);
	vector<int> second = other.Without(*this);
	cout << "first without second: "; print(first); 
	cout << "second without first: "; print(second);
	cout << "\nresult: ";
	return Unite(first, second);
}

vector<int> CustomSet::Without(CustomSet other) {
	return without(this->set, other.set);
}

vector<int> CustomSet::Intersect(CustomSet other) {
	return Intersection(this->set, other.set);
}

vector<int> CustomSet::Union(CustomSet other) {
	return Unite(this->set, other.set);
	}

CustomSet::CustomSet() {}

void CustomSet::Print() {
	print(set);
}

void CustomSet::Sort() {
    QuickSort(set, 0, set.size()-1);
}

int Partition(vector<int>& v, int start, int end) {
	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		if (v[i] < v[pivot]) {
			swap(v[i], v[j]);
			++j;
		}
	}
	swap(v[j], v[pivot]);
	return j;

}

void QuickSort(vector<int>& v, int start, int end) {
	if (start < end) {
		int p = Partition(v, start, end);
		QuickSort(v, start, p - 1);
		QuickSort(v, p + 1, end);
	}

}

bool FoundBefore(vector<int>& v, int index, int elem) {
	if (index == 0) return false;
	for (int i = 0; i < index; ++i) {
		if (elem == v[i]) return true;
	}
	return false;
}

void print(vector<int>& v) {
	if (v.size() == 0) {
		cout << "\nEmpty set\n";
		return;
	}
	for (auto elem : v) {
		cout << elem << "  ";
	}
	cout << "\n";
}

vector<int> Unite(vector<int> that, vector<int> other) {
	vector<int> result;
	for (auto elem : that) {
		result.push_back(elem);
	}
	for (int j = 0; j < other.size(); ++j) {
		if (!FoundBefore(that, that.size(), other[j])) {
			result.push_back(other[j]);
		}
	}
	QuickSort(result, 0, result.size() - 1);
	return result;
}

vector<int> Intersection(vector<int> that, vector<int> other) {
	vector<int> result;
	for (int i = 0; i < that.size(); ++i) {
		for (int j = 0; j < other.size(); ++j) {
			if ((that[i] == other[j]) && (!FoundBefore(result, result.size(), that[i]))) {
				result.push_back(that[i]);
			}
		}
	}
	QuickSort(result, 0, result.size() - 1);
	return result;
}

vector<int> without(vector<int> that, vector<int> other) {
	vector<int> result, temp = Intersection(that, other);
	for (int i = 0; i < that.size(); ++i) {
		result.push_back(that[i]);

		for (int j = 0; j < temp.size(); ++j) {
			if ((that[i] == temp[j])) {
				if (i >= result.size()) {
					result.pop_back();
					continue;
				}
				result.erase(result.begin() + i);
			}
		}
	}

	QuickSort(result, 0, result.size() - 1);
	return result;
}

int EnterInt(string msg = "") {
	cout << msg;
	int a;
	cin >> a;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\tEnter an integer number, please\n";
		return numeric_limits<int>::infinity();
	}
	else return a;
}

void ReadFile(string path, CustomSet& a, CustomSet &b, CustomSet& c) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) cout << "Error" << endl;
	else {
		int number, size;
		vector<int> array;
		fin >> size; 
		for (int i = 0; i < size; ++i) {
			fin >> number;
			array.push_back(number);
		}
		a.Define(array);
		array.clear();
		fin >> size;
		for (int i = 0; i < size; ++i) {
			fin >> number;
			array.push_back(number);
		}
		b.Define(array);
		array.clear();
		fin >> size;
		for (int i = 0; i < size; ++i) {
			fin >> number;
			array.push_back(number);
		}
		c.Define(array);
		array.clear();
		cout << "Universum [-10, 10]\n";
		cout << "SET A: ";  a.Print();
		cout << "SET B: ";  b.Print();
		cout << "SET C: ";  c.Print();
	}
	fin.close();
	return;
}

void Definition(CustomSet *a) {
	cout << "1. Enter by hand\n";
	cout << "2. Enter randomly\n";
	cout << "3. Even numbers\n";
	cout << "4. Odd numbers\n";
	cout << "5. Negative numbers\n";
	cout << "6. Multiplicity of n\n";
	int m = EnterInt("\nYour choice: ");
	switch (m) {
	case 1: {
		a->Define();
		break;
	}
	case 2: {
		a->DefineRandom();
		break;
	}
	case 3: {
		a->DefineCondition(1);
		break;
	}
	case 4: {
		a->DefineCondition(2);
		break;
	}
	case 5: {
		a->DefineCondition(3);
		break;
	}
	case 6: {
		a->DefineCondition(4);
		break;
	}
	default: {
		cout << "Choose from list\n";
	}
	}
}