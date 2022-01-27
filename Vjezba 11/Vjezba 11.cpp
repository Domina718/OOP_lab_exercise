#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class NoFileFoundException : public exception{
	virtual const char* what() const throw() {
		return "No file found!";
	}
};

bool largerThan(int n) {
	return n > 500;
}

bool lessThan (int n) { 
	return n < 300; 
}


int main()
{
	ifstream file("numbers.txt");
	vector<int> numbersFromFile;
	try {
		if (!file.is_open())
			throw NoFileFoundException();
	}
	catch (exception& ex){
		cout << ex.what() << endl;
		exit(0);
	}
	if (file.is_open()) {
		copy(istream_iterator<int>(file), istream_iterator<int>(), back_inserter(numbersFromFile));

	}
	else {
		
	}

	int cnt = count_if(numbersFromFile.begin(), numbersFromFile.end(), largerThan);
	cout << "Counter = " << cnt << endl;
	cout <<"Max element is " << *max_element(numbersFromFile.begin(), numbersFromFile.end()) << endl;
	cout <<"Min element is " << *min_element(numbersFromFile.begin(), numbersFromFile.end()) << endl;
	vector<int>::iterator it;
	it = remove_if(numbersFromFile.begin(), numbersFromFile.end(), lessThan);
	
	for (vector<int>::iterator it2 = numbersFromFile.begin(); it2 != it; ++it2)
		cout << *it2 << endl;

	cout << "\n\n\n\n\n\n" << endl << endl;

	sort(numbersFromFile.begin(), numbersFromFile.end());
	reverse(numbersFromFile.begin(), numbersFromFile.end());

	
	file.close();
	return 0;
}