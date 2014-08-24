#include	"basic.h"

int main()
{
#pragma region test_code_DFT
	double real[10] = { 1, 20, 30, 22, 17, 0, 33, 21, 4, 10 };
	double img[10] = { 0, };
	cout << "real : ";
	for (int i = 0; i < 10; ++i)
		cout << real[i] << ", ";

	cout << endl;

	cout << "imagin : ";
	for (int i = 0; i < 10; ++i)
		cout << img[i] << ", ";

	cout << endl;

	DY_DFT_1D(real, img, 10, FORWARD);
	//DFT_1D(real, img, 10, FORWARD);

	cout << "DFT DONE" << endl;
	cout << "real : ";
	for (int i = 0; i < 10; ++i){
		cout << real[i] << ", ";
	}
	cout << endl;

	cout << "imagin : ";
	for (int i = 0; i < 10; ++i)
		cout << img[i] << ", ";

	cout << endl;

	DY_DFT_1D(real, img, 10, BACKWARD);
	//DFT_1D(real, img, 10, BACKWARD);

	cout << "IDFT DONE" << endl;
	cout << "real : ";
	for (int i = 0; i < 10; ++i)
		cout << real[i] << ", ";

	cout << endl;

	cout << "imagin : ";
	for (int i = 0; i < 10; ++i)
		cout << img[i] << ", ";

	cout << endl;
#pragma endregion


	return 0;
}