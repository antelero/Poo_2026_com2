#include <iostream> 
#include <vector> 
using namespace std;
int main() {
	vector<int> vector1;
	cout << "Vector con informacion? " << endl;
	if (vector1.empty() == false)
		cout << "Vector no Vacio"<<endl;
	else
		cout << "Vector Vacio"<<endl;
	cout << "Vector size: " << vector1.size()<< endl;
	cout << "Vector capacity: " << vector1.capacity() << endl;
	cout << "Maximo size de vector: " << vector1.max_size()<< endl;
	cout << "Agrego 10 elementos: " << endl;	
	for (int x = 1; x <= 10; x++)
		vector1.push_back(x);
	cout << "Vector size: " << vector1.size()<< endl;
	cout << "Vector capacity: " << vector1.capacity() << endl;
	vector1.resize(5);
	cout << "Vector size despues de resizing: " << vector1.size() << endl;
	for (auto a = vector1.begin(); a != vector1.end(); ++a)
		cout << *a << " ";

	cout <<endl<< "Vector capacity: " << vector1.capacity() << endl;
	cout << "Agrego 12 elementos: " << endl;
	for (int x = 1; x <= 12; x++)
		vector1.push_back(x);
	cout << "Vector size: " << vector1.size()<< endl;
	cout << "Vector capacity: " << vector1.capacity() << endl;
	cout << "Vector con informacion? " << endl;
	if (vector1.empty() == false)
		cout << "Vector no Vacio"<<endl;
	else
		cout << "Vector Vacio"<<endl;
	return 0;
}
