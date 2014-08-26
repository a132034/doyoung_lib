// test code (main func)
// last modified : 26 / 08 / 2014
// DFT done
// DCT done
// CLIP done


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
#pragma region test_code_DCT
	double dctin[15] = { 2, 55, 7, 99, 8, 43, 20, 4, 66, 7, 8, 4, 54, 10, 13 };
	double dctout[15] = { 0, };
	double idctout[15] = { 0, };

	cout << "Signal ";
	for (int i = 0; i < 15; ++i)
		cout << dctin[i] << ", ";
	cout << endl;

	DY_DCT_1D(dctout, dctin, 15);

	cout << "DCT" << endl;
	cout << "Signal ";
	for (int i = 0; i < 15; ++i)
		cout << dctout[i] << ", ";
	cout << endl;

	DY_DCT_1D(idctout, dctout, 15, BACKWARD);

	cout << "IDCT" << endl;
	cout << "Signal ";
	for (int i = 0; i < 15; ++i)
		cout << idctout[i] << ", ";
	cout << endl;
#pragma endregion
#pragma region  CLIP
	double clipT[10] = { 0.2, -11, 1000, 33.22, 4.5, 99.95, 258.18, 33.94, -22.55, -321.52 };

	cout << "befor clipT" << endl;
	for (int i = 0; i < 10; ++i)
		cout <<clipT[i] << ", ";
	cout << endl;

	cout << "After clipT" << endl;
	for (int i = 0; i < 10; ++i)
		cout << clip(clipT[i], 255, 0) << ", ";
	cout << endl;


#pragma endregion
	return 0;
}