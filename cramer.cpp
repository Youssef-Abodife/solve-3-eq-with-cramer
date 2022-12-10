
#include <bits/stdc++.h>
using namespace std;


double determinantOfMatrix(double mat[3][3])
{
	double ans;
	ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
		- mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
		+ mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
	return ans;
}


void findSolution(double coeff[3][4])
{
	
	double d[3][3] = {
		{ coeff[0][0], coeff[0][1], coeff[0][2] },
		{ coeff[1][0], coeff[1][1], coeff[1][2] },
		{ coeff[2][0], coeff[2][1], coeff[2][2] },
	};
	
	double d1[3][3] = {
		{ coeff[0][3], coeff[0][1], coeff[0][2] },
		{ coeff[1][3], coeff[1][1], coeff[1][2] },
		{ coeff[2][3], coeff[2][1], coeff[2][2] },
	};
	
	double d2[3][3] = {
		{ coeff[0][0], coeff[0][3], coeff[0][2] },
		{ coeff[1][0], coeff[1][3], coeff[1][2] },
		{ coeff[2][0], coeff[2][3], coeff[2][2] },
	};

	double d3[3][3] = {
		{ coeff[0][0], coeff[0][1], coeff[0][3] },
		{ coeff[1][0], coeff[1][1], coeff[1][3] },
		{ coeff[2][0], coeff[2][1], coeff[2][3] },
	};


	double D = determinantOfMatrix(d);
	double D1 = determinantOfMatrix(d1);
	double D2 = determinantOfMatrix(d2);
	double D3 = determinantOfMatrix(d3);

	if (D != 0) {
	
		double x = D1 / D;
		double y = D2 / D;
		double z = D3 / D; 
		cout <<"Value of x is :"<< x<<endl;
		cout <<"Value of y is :"<< y<<endl;
		cout << "Value of z is :"<< z<<endl;
	}

	else {
		if (D1 == 0 && D2 == 0 && D3 == 0)
			cout <<"Infinite solutions\n";
		else if (D1 != 0 || D2 != 0 || D3 != 0)
			cout<<"No solutions\n";
	}
}

int main()
{


	double coeff[3][4];
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<4;j++)
		cin>> coeff[i][j];
			
	 } 


	findSolution(coeff);
	return 0;
}

