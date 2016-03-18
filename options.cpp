#include <stdio.h>
#include<iostream>
#include <fstream>
#include <math.h>
#include<time.h>
#include <stdlib.h>
#include <string.h>

double find(double prob[2000],double z[2000]);


int main()
{

	double so,k,rtn,dev,rf,zr,price,payoff,sum=0,value=0,dt=1,ns,nd,T;
	int i=1,j=1;

	/*printf("Please enter the underlying value of stock\n");
	scanf("%f",&so);
	printf("Please enter the strike Price\n");
	scanf("%f",&k);
	printf("Please enter the annualized average return\n");
	scanf("%f",&rtn);
	printf("Please enter volatility of stock\n");
	scanf("%f",&dev);
	printf("Please enter the annualized risk free rate\n");
	scanf("%f",&rf);
	printf("Please enter the number of days till maturity\n");
	scanf("%d",&T);
	printf("Please enter the number of manto Carlo Simulation\n");
	scanf("%d",&ns);
	printf("Please enter the number of divisions\n");
	scanf("%d",&nd);*/

	so=7215.7;
	k=7400;
	rtn= (-0.204461523);
	dev=0.40317714;
	rf=.0883;
	T=15;
	ns=100;
	nd=15;
	float shout=7300;

	dt= (T/(nd*365));
	printf("dt is %lf\n",dt);
	double z[2000];
	FILE *ff;
	ff=fopen("Zvalue.txt","r");
	 if (ff == NULL)
    {
        printf("Error Reading File\n");
        exit (0);
    }
    for (i = 1; i < 2001; i++)
    {
    fscanf(ff, "%lf,", &z[i] );

    }

    /*for (i = 1; i <2001; i++)
    {
           printf("Number is: %lf\n\n", z[i]);
        }
*/
    fclose(ff);


	double prob[2000];
	FILE *fe;
	fe=fopen("Prob.txt","r");
	 if (fe == NULL)
    {
        printf("Error Reading File\n");
        exit (0);
    }
    for (i = 1; i < 2001; i++)
    {
        fscanf(fe, "%lf,", &prob[i] );

    }

  /*  for (i = 1; i <2001; i++)
    {
           printf("Number is: %lf\n\n", prob[i]);
        }
*/
    fclose(fe);

	for(i=1; i< ns+1 ;i++)
	{
		price=so;
		for(j=1;j<=nd;j++)
		{
			zr=find(prob,z);
			printf("the value of z is %lf\n",zr);
			price=price*pow(2.718,(rf-(pow(dev,2)/2))*dt+(dev*zr*pow(dt,.5)));
			printf("the price is %lf\n",price);
		}
		
		float a=shout-k;
		float b=price-k;
		float c= 0;
		
		if (a>b && a>c)
		{
			payoff=shout-k;
		}
		
		if (b>a && b>c)
		
		{
			payoff=price-k;
		}
		
		if(c>a && c>b) 
		{
		payoff=0;
	    }

	    sum=sum+payoff;
	}
	value=(sum/ns)*pow(2.718,-rf*T/360);
	printf("The Value of payoff is %lf\n",value);
}

double find(double prob[2000],double z[2000])
{
        double val,p=0;
        int i=0;
        /*srand ( time(NULL) );*/
		p= (double) rand()/RAND_MAX;
		printf("the probality by rand is %lf\n",p);
		for(i=1 ; i<2001 ; i++)
		{
			if (p>prob[i])
			val= z[i];
			else break;


		}
		return val;
	}
