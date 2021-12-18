#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<string> v;
	v.push_back("12");
	v.push_back("1234");
	v.push_back("56344535");

	cout << v[0] << endl;
	cout << v[1].substr(0, v[1].size()) << endl;
	if (v[0] == v[1].substr(0, v[0].size()))
		cout << "ji" << endl;

	for (int i = 0; i < v.size(); i++) {

	}
}