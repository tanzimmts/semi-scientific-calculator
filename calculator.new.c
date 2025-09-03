#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float rad_to_deg(float rad) {
    return rad * (180.0 / M_PI);
}

#define  DEG_TO_RAD(deg)((deg)*M_PI/180)
    /* Variables */
    int M, CM, EM;
    float N1, N2, ANS;
    float N1c, N2c, denom;
    char I1, I2;
    char TR[7];
    char S;
    char L[5];
    char C1[5], C2[5];
    char input[100];
    int base;
    float A1, A2, A3, B1, B2, B3, P1, P2, P3;
    float D, D1, D2, D3, x, y, z, Dx, Dy, Dz;
    float RP, IP, X1, X2;
    char IN[5];

void EM3()
{
    printf("A= ");
    scanf("%f",&A1);
    printf("B= ");
    scanf("%f",&B1);
    printf("C= ");
    scanf("%f",&P1);

    D=B1*B1-4*A1*P1;

    if(0>D){
        RP=(-B1)/(2*A1);
        IP=(sqrt(-D))/(2*A1);

        printf("\nX1= %.2f + (%.2fi)",RP,IP);
        printf("\nX2= %.2f - (%.2fi)",RP,IP);
    }
    else{
        X1=(-B1+sqrt(D))/(2*A1);
        X2=(-B1-sqrt(D))/(2*A1);

        printf("\nX1= %.2f",X1);
        printf("\nX2= %.2f",X2);
    }
}
void EM2()
{
    printf("A1= ");
    scanf("%f",&A1);
    printf("B1= ");
    scanf("%f",&B1);
    printf("C1= ");
    scanf("%f",&P1);
    printf("D1= ");
    scanf("%f",&D1);

    printf("\nA2= ");
    scanf("%f",&A2);
    printf("B2= ");
    scanf("%f",&B2);
    printf("C2= ");
    scanf("%f",&P2);
    printf("D2= ");
    scanf("%f",&D2);

    printf("\nA3= ");
    scanf("%f",&A3);
    printf("B3= ");
    scanf("%f",&B3);
    printf("C3= ");
    scanf("%f",&P3);
    printf("D3= ");
    scanf("%f",&D3);

    D= A1*(B2*P3-B3*P2)-B1*(A2*P3-A3*P2)+P1*(A2*B3-A3*B2);

    Dx=D1*(B2*P3-B3*P2)-B1*(D2*P3-D3*P2)+P1*(D2*B3-D3*B2);
    Dy=A1*(D2*P3-D3*P2)-D1*(A2*P3-A3*P2)+P1*(A2*D3-A3*D2);
    Dz=A1*(B2*D3-B3*D2)-B1*(A2*D3-A3*D2)+D1*(A2*B3-A3*B2);

    x=Dx/D;
    y=Dy/D;
    z=Dz/D;

    printf("\nx= %.2f",x);
    printf("\ny= %.2f",y);
    printf("\nz= %.2f",z);
}
void EM1()
{
    printf("A1= ");
    scanf("%f",&A1);
    printf("B1= ");
    scanf("%f",&B1);
    printf("C1= ");
    scanf("%f",&P1);
    printf("\nA2= ");
    scanf("%f",&A2);
    printf("B2= ");
    scanf("%f",&B2);
    printf("C2= ");
    scanf("%f",&P2);

    D=A1*B2-A2*B1;

    if(D==0){
        printf("MATH ERROR");
    }
    else{
        x= (P1*B2-P2*B1)/D;
        y= (A1*P2-A2*P1)/D;

        printf("\nx= %.2f",x);
        printf("\ny= %.2f",y);
    }
}

void equationmode()
{
    printf("\nMODE: EQUATIONS");
    printf("\n1. AX+BY=C \n2. AX+BY+CZ=D \n3. AX^2+BX+C=0");
    printf("\n\n");

    scanf("%d",&EM);
    printf("\n\n");

    if(EM==1){
        EM1();
    }
    else if(EM==2){
        EM2();
    }
    else if(EM==3){
        EM3();
    }
    else{
        printf("\nSYNTAX ERROR");
    }
}

void baseNmode()
{
    printf("\nMODE: BASE-N CONVERTER\n");
    printf("\n\n");
    scanf("%s %d", input, &base);

    if (base < 2 || base > 16) {
        printf("\nSYNTAX ERROR\n");
        return;
    }

    char *endptr;
    long decimal = strtol(input, &endptr, base);

    if (*endptr != '\0') {
        printf("SYNTAX ERROR");
        return;
    }

    printf("\nDecimal     : %ld\n", decimal);
    printf("Binary      : ");
    for (int i = sizeof(long) * 8 - 1, printed = 0; i >= 0; i--) {
        int bit = (decimal >> i) & 1;
        if (bit || printed) {
            printf("%d", bit);
            printed = 1;
        }
    }
    if (!decimal) printf("0");
    printf("\n");
    printf("Octal       : %lo\n", decimal);
    printf("Hexadecimal : %lX\n", decimal);
}

void complexmode()
{
    printf("\nMODE: COMPLEX\n\n");
    scanf("%f %f%c %c (%f %f%c)",&N1,&N1c,&I1,&S,&N2,&N2c,&I2);

    if(I1=='i' && I2=='i'){

    if(S=='+'){
        printf("\nANS= %.2f + %.2fi",N1+N2,N1c+N2c);
    }
    else if(S=='-'){
        printf("\nANS= %.2f + %.2fi",N1-N2,N1c-N2c);
    }
    else if(S=='*'){
        printf("\nANS= %.2f + %.2fi",N1*N2-N1c*N2c,N1*N2c+N2*N1c);
    }
    else if(S=='/'){
        denom= N2*N2+N2c*N2c;
        if(denom==0){
            printf("\nMATH ERROR");
        }
        else{
            printf("\nANS= %.2f + %.2fi",(N1*N2+N1c*N2c)/denom,(N1*N2c-N2*N1c)/denom);
        }
    }
    }
    else{
        printf("\nMATH ERROR");
    }
}

void CM1()
{
  scanf("%s %c %s",C1,&S,C2);

        if(strcmp(C1,"e")==0){
            N1=exp(1);
        }
        else if(strcmp(C1,"pi")==0){
            N1=M_PI;
        }
        else{
            sscanf(C1,"%f",&N1);
        }

        if(strcmp(C2,"e")==0){
            N2=exp(1);
        }
        else if(strcmp(C2,"pi")==0){
            N2=M_PI;
        }
        else{
            sscanf(C2,"%f",&N2);
        }

        if(S=='+'){
            ANS= N1+N2;
            printf("\nANS= %.4f",ANS);
        }
        else if(S=='-'){
            ANS= N1-N2;
            printf("\nANS= %.4f",ANS);
        }
        else if(S=='*'){
            ANS= N1*N2;
            printf("\nANS= %.4f",ANS);
        }
        else if(S=='/'){
                if(N2==0){
                    printf("\nMATH ERROR");
                }
                else{
            ANS= N1/N2;
            printf("\nANS= %.4f",ANS);
                }
        }
        else if(S=='^'){
    printf("\nANS= %.3f",pow(N1,N2));
    }
        else{
            printf("\nSYNTAX ERROR");
        }
        return;

}
void CM2()
{
    scanf("%s %f",TR,&N1);
            float R=DEG_TO_RAD(N1);

            if(strcmp(TR,"sin")==0){
                printf("\nANS= %.4f",sin(R));
            }
            else if(strcmp(TR,"cos")==0){
                printf("\nANS= %.4f",cos(R));
            }
            else if(strcmp(TR,"tan")==0){
                printf("\nANS= %.4f",tan(R));
            }
            else{
                printf("\nSYNTAX ERROR");
            }
            return;
}
void CM3()
{
    scanf("%s %f",L,&N1);

            if(strcmp(L,"log")==0){
                printf("\nANS= %.3f",log10(N1));
            }
            else if(strcmp(L,"ln")==0){
                printf("\nANS= %.3f",log(N1));
            }
            else if(strcmp(L,"e^")==0){
                printf("\nANS= %.3f",exp(N1));
            }
            else{
                printf("\nSYNTAX ERROR");
            }
            return;
}
void CM4()
{
    scanf("%s %c %s (%f)",TR,&S,IN,&N1);

    if(S=='^' && strcmp(IN,"-1")==0){
        if(strcmp(TR,"sin")==0){
            if(N1>=-1 && N1<=1){
                printf("\nRadian= %.2f\nDegree= %.2f",asin(N1),rad_to_deg(asin(N1)));
            }
            else{
                printf("\nMATH ERROR");
            }
    }
    else if(strcmp(TR,"cos")==0){
            if(N1>=-1 && N1<=1){
                printf("\nRadian= %.2f\nDegree= %.2f",acos(N1),rad_to_deg(acos(N1)));
            }
            else{
                printf("\nMATH ERROR");
            }
    }
    else if(strcmp(TR,"tan")==0){
        printf("\nRadian= %.2f\nDegree= %.2f",atan(N1),rad_to_deg(atan(N1)));
    }
    }
    else{
        printf("\nMATH ERROR");
    }
}

void computermode()
{
    printf("\nMODE: COMPUTER\n\n1. Primary\n2. Trigonometry\n3. Logarithm\n4. Inverse Trigonometry\n\n");
        scanf("%d",&CM);
        printf("\n\n");

        if(CM==1){
                CM1();
        }
        else if(CM==2){
                CM2();
        }
        else if(CM==3){
            CM3();
        }
        else if(CM==4){
            CM4();
        }
        else{
            printf("\nSYNTAX ERROR");
        }

}

int main()
{


    printf("Interface:\n\nSelect Mode:\n1. COMPUTER\n2. COMPLEX\n3. BASE-N\n4. EQUATION\n5. MATRIX\n6. TABLE\n\n");
    scanf("%d",&M);

    if(M==1){
        computermode();
    }

    else if(M==2){
        complexmode();
    }
    else if(M==3){
        baseNmode();
    }
    else if(M==4){
        equationmode();
    }
    else if(M==5){}
    else if(M==6){}
    else{
        printf("\nSYNTAX ERROR");
    }

    return 0;
}
