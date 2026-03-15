#include <iostream> 
#include <vector> 

using namespace std;
int main()
{
	vector<double> nums;

	for (int a = 1; a <= 5; a++)
		nums.push_back(a);

	cout << "Salida de Inicio a Fin: ";

	for (auto a = nums.begin(); a != nums.end(); ++a)

		cout << *a << " ";

	cout << "\nSalida de Inicio a Fin - Inverso: ";

	for (auto a = nums.rbegin(); a != nums.rend(); ++a)

		cout << *a << " ";

	return 0;
}
