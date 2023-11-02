#include <stdio.h>
#include <stdlib.h>

float determinant(float t[][2]);

int main()
{
    float coeffs[2][2] = {{0,0},{0,0}};
    float cst[2] = {0,0};
    float det = 0, detx = 0, dety = 0;
    float x,y;
    int i,j;
    
    for(i=0;i<2;i++)
    {
		for(j=0;j<2;j++)
		{
			printf("Saisie du coefficient [%d][%d] : ", i, j);
			scanf("%f", &coeffs[i][j]);
		}
	}
	
	for(i=0;i<2;i++)
	{
		printf("Saisie de la constante [%d] : ", i);
		scanf("%f", &cst[i]);
	}
    
    printf("\nRésolution du système :\n");
    printf("%f * X + %f * Y = %f\n", coeffs[0][0], coeffs[0][1], cst[0]);
    printf("%f * X + %f * Y = %f\n\n", coeffs[1][0], coeffs[1][1], cst[1]);

    det = determinant(coeffs);

    if( det != 0)
    {
        float Mx[2][2] = {{cst[0],coeffs[0][1]},{cst[1],coeffs[1][1]}};
        float My[2][2] = {{coeffs[0][0],cst[0]},{coeffs[1][0],cst[1]}};
        detx = determinant(Mx);
        dety = determinant(My);
        x = detx/det;
        y = dety/det;
        printf("\nx = %f\ny = %f\n", x, y);
    }
    
    else
    {
        float Mx[2][2] = {{cst[0],coeffs[0][1]},{cst[1],coeffs[1][1]}};
        detx = determinant(Mx);
        if (detx == 0)
        {
            printf("\nIl y a une infinité de solutions\n");
        }
        else
        {
            printf("\nIl n'y a pas de solution\n");
        }
    }

    return 0;
}

float determinant(float coeffs[][2])
{
    return (coeffs[0][0] * coeffs[1][1] - coeffs[0][1] * coeffs[1][0]);
}
