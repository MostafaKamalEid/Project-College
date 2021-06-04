#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>



// the number of terms you can add
const int n = 20;
typedef struct Poly
{
	// hard code 
	int power[n];
	int coef[n];
} Poly;



// takes Nominator and Dominator and prints the Long Division ==> Result and Remainder
void LongDivision(Poly Nom, Poly Dom)
{
	// initilizer 
	Poly Remainder = Nom;
	Poly Subtract = Dom;
	Poly Division_Result, divisor;
	int Index_Highest_Dom_Power = 0;;

	// check the higest power in Dominator > highest power in Nominator  if true break;
	if (Nom.coef[0] == 0 && Dom.coef[0] != 0) 
	{ 
		printf("Division Can`t Done");
		return;
	}
	;

	for (int i = 0; Dom.coef[i] == 0; i++)
	{
		Index_Highest_Dom_Power = i + 1;
	}

	// check the power of Nom of the 
	for (int i = 0, j = 0; Nom.power[i] >= Dom.power[Index_Highest_Dom_Power]; i++, j++)
	{
		// hard code
		int zeros[n] = { 0 };
		// divisor that will be used in multiplication and Subtractor 
		divisor.power[0] = Nom.power[i] - Dom.power[Index_Highest_Dom_Power];

		// for first iterate it will be compared to Nom but later on the remainder of first iteration in Subtract
		if (i == 0)
		{
			divisor.coef[0] = Nom.coef[i] / Dom.coef[Index_Highest_Dom_Power];
			Division_Result.coef[j] = Nom.coef[i] / Dom.coef[Index_Highest_Dom_Power];

		}
		else
		{
			divisor.coef[0] = Subtract.coef[i] / Dom.coef[Index_Highest_Dom_Power];
			Division_Result.coef[j] = divisor.coef[0] / Dom.coef[Index_Highest_Dom_Power];


		}

		Division_Result.power[j] = Nom.power[i] - Dom.power[Index_Highest_Dom_Power];



		//	Subtract.coef  = divisor.coef[0] * Dom.coef
		// hard code size
		for (int z = 0; z < n; z++)
		{
			// coff multiplyer
			Subtract.coef[z] = divisor.coef[0] * Dom.coef[z];

		}
		// power multiplyer(shifting) which is can then be subtracted since we done both coef and power
		for (int z = 0; z < n; z++)
		{
			if (z + divisor.power[0] < n)
			{
				zeros[z] = Subtract.coef[z + divisor.power[0]];
			}
			else
			{
				break;
			}

		}


		for (int z = 0; z < n; z++)
		{
			if (i == 0)
			{
				Subtract.coef[z] = Nom.coef[z] - zeros[z];
			}
			else
			{
				Subtract.coef[z] = Remainder.coef[z] - zeros[z];
			}

		}
		Remainder = Subtract;

	}
	printf("Division Result = ");
	for (int i = 0; i < n - (Nom.power[0] - Division_Result.power[0]); i++)
	{
		if (Division_Result.coef[i] == 0) continue;
		printf("%dX^%d  ", Division_Result.coef[i], Division_Result.power[i]);
	}
	printf("\nRemainder = ");

	for (int i = 0; i < n; i++)
	{
		if (Remainder.coef[i] == 0) continue;
		printf("%dX^%d ", Remainder.coef[i], Remainder.power[i]);
		if(i<=n-2) printf(" + ");
	}
	printf("/ ");

	for (int i = 0; i < n; i++)
	{
		if (Dom.coef[i] == 0) continue;
		printf("%dX^%d ", Dom.coef[i], Dom.power[i]);
		if (i <= n - 2) printf(" + ");
	}

	printf("\n");
}

void GetPower(Poly* Nom , Poly* Dom)
{
	for (int i = 0; i < n; i++)
	{
		Nom->power[i] = n - (i + 1);
		Dom->power[i] = n - (i + 1);
	}

}

void GetInputs(Poly* Nom, Poly* Dom) 
{
	int Heigest_power_Nominator = 0;
	int Heigest_power_Dominator = 0;

	printf("Enter the Heigest power of Nominator : ");
	fscanf_s(stdin, "%d", &Heigest_power_Nominator);
	printf("\n");
	printf("Enter the Heigest power of Dominator : ");
	fscanf_s(stdin, "%d", &Heigest_power_Dominator);
	printf("\n");


	// Get the Coefs of  nominator  
	printf("Enter the Coef of Nominator : ");
	for (int i = 0; i <= Heigest_power_Nominator; i++)
	{
		fscanf_s(stdin, "%d", &Nom->coef[n - (i + 1)]);
		if (i == Heigest_power_Nominator) break;



	}
	printf("\n");
	// Get the Coefs of  nominator  

	printf("Enter the Coef of Dominator : ");
	for (int i = 0; i <= Heigest_power_Dominator; i++)
	{
		fscanf_s(stdin, "%d", &Dom->coef[n - (i + 1)]);
		if (i == Heigest_power_Nominator) break;


	}
	printf("\n");
}

void main()
{
	// consider the power order by the highest for both nom and Dom
	// as 2D array but with name to ease thinking 
	Poly Nom = { {0}, {0} };
	Poly Dom = { {0},{0} };
	GetPower(&Nom, &Dom);
	GetInputs(&Nom, &Dom);

	LongDivision(Nom, Dom);


}