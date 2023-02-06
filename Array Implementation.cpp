/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int SparseMatrix[4][5] =
	{
		{0 , 0 , 3 , 0 , 4 },
		{0 , 0 , 5 , 7 , 0 },
		{0 , 0 , 0 , 0 , 0 },
		{0 , 2 , 6 , 0 , 0 }
	};
	int Size = 0;
	for (int I = 0; I < 4; I++)
		for (int J = 0; J< 5; J++)
			if (SparseMatrix[I][J] != 0)
				Size++;
	int Compact_Matrix[3][Size];
	int K= 0;
	for (int I = 0; I < 4; I++)
		for (int J = 0; J < 5;J++)
			if (SparseMatrix[I][J] != 0)
			{
				Compact_Matrix[0][K] = I;
				Compact_Matrix[1][K] = J;
				Compact_Matrix[2][K] = SparseMatrix[I][J];
				K++;
			}
	for (int I=0; I<3; I++)
	{
		for (int J=0; J<Size; J++)
			cout <<" "<< Compact_Matrix[I][J];
		cout <<"\n";
	}
	return 0;
}
