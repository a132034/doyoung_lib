#include	"basic.h"

void __stdcall DY_DFT_1D(double* real, double* imagine, const int length, const int direction )
{
	register int i, j, k;
	int N = length;

	double* tr = new double[sizeof(double)*N];
	double* ti = new double[sizeof(double)*N];

	memcpy(tr, real, sizeof(double)*N);
	memcpy(ti, imagine, sizeof(double)*N);

	double re, im, temp;
	double cosine, sine;

	for (k = 1; k <= N; ++k)
	{
		re = 0.0;
		im = 0.0;
		for (j = 1; j <= N; ++j)
		{
			temp = 2 * direction*PI*(j - 1)*(k - 1) / (N);
			cosine = cos(temp);
			sine = sin(temp);
			re += (tr[j - 1] * cosine + ti[j - 1] * sine);
			im += (ti[j - 1] * cosine - tr[j - 1] * sine);
		}
		real[k - 1] = re;
		imagine[k - 1] = im;
	}

	if (direction == -1) // IDFT
	{
		for (i = 0; i < N; i++)
		{
			real[i] /= (double)N;
			imagine[i] /= (double)N;
		}
	}
	
	if (tr != NULL){
		delete[] tr;
		tr = NULL;
	}
	if (ti != NULL){
		delete[] ti;
		ti = NULL;
	}
}

void __stdcall DY_DCT_1D(double* dst, double*  src, const int length, const int direction)
{
	register int k, n;
	int N = length;
	double dct = 0.0;
	double temp = 0.0;
	double omega = 0.0;
	double *_dst, *_src;
	_dst = dst;
	_src = src;
	for (k = 1; k <= N; ++k) // °á°ú Loop
	{
		dct = 0.0;
		for (n = 1; n <= N; ++n) // sigma
		{
			if (direction == 1)
			{
				if (k == 1)
					omega = 1.0 / sqrt((double)N);
				else // 2 <= k <= N
				{
					omega = 2.0 / N;
					omega = sqrt(omega);
				}
				temp = (PI * (2.0 * n - 1) * (k - 1)) / (2 * N);
			}
			else 
			{
				if (n == 1)
					omega = 1.0 / sqrt((double)N);
				else // 2 <= k <= N
				{
					omega = 2.0 / N;
					omega = sqrt(omega);
				}
				temp = (PI * (2.0 * k - 1) * (n - 1)) / (2 * N);
			}
			dct += omega * _src[n - 1] * cos(temp);
		}
		_dst[k - 1] = dct;
	}
}