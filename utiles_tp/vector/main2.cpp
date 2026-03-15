#include <iostream>
#include <vector> 

using namespace std;
int main()
{
	vector<int> nums;
	
	nums.assign(5, 1);

	cout << "Contenido del Vector: ";
	for (int a = 0; a < nums.size(); a++)
		cout << nums[a] << " ";
	nums.push_back(2);
	int n = nums.size();
	cout << "\nUltimo elemento: " << nums[n - 1];

	nums.pop_back();

	cout << "\nContenido del Vector: ";
	for (int a = 0; a < nums.size(); a++)
		cout << nums[a] << " ";

	nums.insert(nums.begin(), 7);

	cout << "\nPrimer elemento: " << nums[0];
	
	nums.clear();
	cout << "\nSize despues de aplicar clear(): " << nums.size();			
}
