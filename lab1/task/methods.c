//
// Created by Mac on 17.02.2020.
//

#include "methods.h"


double f(double x)
{
    return  x*x*x - 6*x -8 ;
}

double df(double x)
{
    return 3*x*x - 6 ;
}

double d2f(double x)
{
    return  6*x ;
}

void method1(double a ,double b ,double eps)
{
    int k=0;
    double x;
    if(f((a+b)/2)==0)
    {
        printf("X is equal %f",(a+b)/2);
    }
    while(fabs(a-b)>eps)
    {
        if(f((a+b)/2)*f(a)>0)
        {
            a=(a+b)/2;
        }
        else {
            b=(a+b)/2;
        }
        k++;
        x=(a+b)/2;

    }
    printf("Divide method        %f         %3.d\n",x,k);
}

void method2(double a ,double b,double eps)
{
    int k=0;
    double x,px;

   if( f(b)*d2f(b) > 0 )
   {
       x = a - (f(a)*(b-a)) / (f(b)-f(a)) ;
       px = a;
       while(fabs( x - px ) > eps )
       {
           px=x;
           x = px - (f(px)*(b-px))/ ( f(b) - f(px) );
           k++;
       }
   }
   else
   {
       x = b - (f(b)*(a-b)) / (f(a)-f(b)) ;
       px = b;
       while(fabs( x - px ) > eps )
       {
           px=x;
           x = px - (f(px)*(a-px))/ ( f(a) - f(px) );
           k++;
       }

   }

    printf("method chord         %lf         %3.d\n",x ,k);
}

void method3(double a ,double b ,double eps)
{
    int k=0;
    double x, px;

    px =  f(b)*d2f(b) > 0 ? b : a ;
    x = px - f(px)/df(px) ;

    while(fabs(x-px)>eps)
    {
        px=x;
        x= px - f(px)/df(px) ;
        k++;
    }



    printf("method dotychnych    %lf         %3.d\n",x ,k);
}



void method4(double a ,double b,double eps)
{
    int k=0;
    double x,px;

    px =  f(b)*d2f(b) > 0 ? b : a ;
    x= pow(6*px+8,1.0/3);

    while(fabs(x-px)>eps)
    {
     px=x;
     x= pow(6*px+8,1.0/3);
     k++;
    }

    printf("Iteration method     %lf         %3.d\n",x ,k);
}
