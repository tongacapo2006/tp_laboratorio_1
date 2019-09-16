#include <stdio.h>
#include <stdlib.h>

int factorial( int x);

int main()
{
    //long long f;

    //f = factorial(20);

    printf("%lli", factorial(1000000000));



    return 0;
}

int factorial( int x){

 int fact = 1;

 if( x > 1){
    fact = x * factorial( x-1);
 }

 return fact;
}
