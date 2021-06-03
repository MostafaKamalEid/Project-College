#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <string.h>

typedef struct Poly
{
	// hard code 
	int power[4];
	int coef[4];
} Poly;

void main()
{
	// consider the power order by the highest for both nom and Dom
	// as 2D array but with name to ease thinking 
	Poly Nom = { {3,2,1,0}, {1,-12,38,-17} }; // x**3 - 12 X**2 + 38x -17 
	Poly Nom_Copy = Nom; // x**3 - 12 X**2 + 38x -17 
	Poly Dom = { {3,2,1,0},{0,0,1,-7} }; // x - 7
	// hard code array replaced it by loops copy
	Poly Dom_Copy = Dom;


	Poly Division_Result,Remainder, divisor;
	int Index_Highest_Dom_Power;

	// check the higest power in Dominator > highest power in Nominator  if true break;
	if (Nom.coef[0] == 0 && Dom.coef[0] != 0 ) return;

	for (int i = 0; Dom.coef[i] == 0; i++)
	{
		Index_Highest_Dom_Power = i+1;
	}
	
	// check the power of Nom of the 
	for (int i = 0 , j = 0; Nom.power[i] >= Dom.power[Index_Highest_Dom_Power]  ; i++,j++)
	{
		// hard code
		int zeros[4] = {0};
		// divisor that will be used in multiplication and Subtractor 
		divisor.power[0] = Nom.power[i] - Dom.power[Index_Highest_Dom_Power];

		// for first iterate it will be compared to Nom but later on the remainder of first iteration in Dom_Copy
		if (i == 0)
		{
			divisor.coef[0] = Nom.coef[i] / Dom.coef[Index_Highest_Dom_Power];
			Division_Result.coef[j] = Nom.coef[i] / Dom.coef[Index_Highest_Dom_Power];

		}			
		else
		{
			divisor.coef[0] = Dom_Copy.coef[i] / Dom.coef[Index_Highest_Dom_Power];
			Division_Result.coef[j] = divisor.coef[0] / Dom.coef[Index_Highest_Dom_Power];


		}

		Division_Result.power[j] = Nom.power[i] - Dom.power[Index_Highest_Dom_Power];

		
		
        //	Dom_Copy.coef  = divisor.coef[0] * Dom.coef
		// hard code size
		for (int z = 0; z < 4; z++)
		{
			// coff multiplyer
			Dom_Copy.coef[z] = divisor.coef[0] * Dom.coef[z];
	
		}
		// {3,2,1,0} {0,0,1,-7} index = i to index = i + divisor.power[0]
			// {3,2,1,0} {1,-7,0,0}
			// {1,-12,38,-17}-{1,-7,0,0}
		//	divisor.power[0] = 1
		// z is hard code
		// power multiplyer(shifting) which is can then be subtracted since we done both coef and power
		for (int z = 0; z < 4; z++)
		{
			if (z + divisor.power[0] < 4) 
			{
				zeros[z] = Dom_Copy.coef[z + divisor.power[0]];
			}
			else
			{
				break;
			}

		}


		for (int z = 0; z < 4; z++)
		{
			if (i == 0) 
			{
				Dom_Copy.coef[z] = Nom.coef[z] - zeros[z];
			}
			else
			{
				Dom_Copy.coef[z] = Nom_Copy.coef[z] - zeros[z];
			}

		}
		Nom_Copy = Dom_Copy;

	}
	for (int i = 0; i < 4-(Nom.power[0]-Division_Result.power[0]); i++)
	{
		printf("%dX*%d \t", Division_Result.coef[i], Division_Result.power[i]);
	}
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%dX*%d \t", Nom_Copy.coef[i], Nom_Copy.power[i]);
	}
	printf("\n");


}