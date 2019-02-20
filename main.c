#include <stdio.h>
#include <stdlib.h>
//MODULATOR = 2^31 - 1
#define MODULATOR 2147483647
#define MULTIP 1103515245
#define INCREMENT 12345
unsigned int seed = 0;                      //functia rand
int rand()
{
    seed = (MULTIP * seed + INCREMENT) % MODULATOR;
    return seed;
}
long long int cerinta1(int long long **a,int i,int j,long long suma)
{
    int k;

    if((i==0)&&(j==0))
                    return suma;    //cazul in care a azjuns in varf
        else
            if ((i==0)&&(j>0))
                {
                    for(k=j-1;k>0;k--)
                        suma=suma+a[i][k];  //cazul in care doar merge la stanga
                    return suma;
                }
                else
                  if ((j==0)&&(i>0))
                    {
                        for(k=i-1;k>0;k--)
                            suma=suma+a[k][j];  //cazul in care doar mai poate urca
                        return suma;
                    }
                    else
                        if(a[i-1][j]<=a[i][j-1])
                            {
                                suma=suma+a[i-1][j];
                                i--;                //cazul de mijloc cand trebuie sa aleaga stanga sau sus
                              cerinta1(a,i,j,suma);
                            }
                            else
                            {
                                 suma=suma+a[i][j-1];
                                j--;
                                cerinta1(a,i,j,suma);
                            }
}
void cerinta2(int long long **a,int long long **b,int r,int c)
{
    if(b[r][c+1]<=b[r+1][c])
        b[r][c]=b[r][c+1]+a[r][c];
        else                            //calculeaza matricea de costuri
            b[r][c]=b[r+1][c]+a[r][c];
    if(r-1>=0) cerinta2(a,b,r-1,c);         //am apelat recursiv pana cand completeaza o coloana
}
int cerinta3(int long long **a,int poz,int v[],int n,long long *suma)
{
    int i,j,k;

    i=n-1;
    j=n-1;
    *suma=a[i][i];

    while((i>0)&&(j>0))
        {
            if(v[poz]==1) i--;  //cazul in care alege conform functiei rand daca merge in sus sau la stanga
                else j--;
            *suma=*suma+a[i][j];
            poz++;
        }
    if((i>0)&&(j==0))
        for(k=i-1;k>=0;k--)             //cazul in care doar poate urca
            *suma=*suma+a[k][j];
    if((j>0)&&(i==0))
        for(k=j-1;k>=0;k--)             //cazul in care doar poate merge spre stanga
            *suma=*suma+a[i][k];
    return(poz);    //returnez pozitia la care raname pentru a sti de unde sa plece urmatoarea incercare
}
void main(int argc,char* argv[])
{
    FILE *date,*rezultate;
    int C1,C2,C3,C4,n,i,j,inc_max,inc_fac=0,r,c,v[25],poz=0;
    long long **a,**b,suma,curent,max_ad;

    if((date=fopen(argv[1],"r"))==NULL);
    if((rezultate=fopen(argv[2],"w"))==NULL);

    fscanf(date,"%d %d %d %d",&C1,&C2,&C3,&C4);
    fscanf(date,"%d",&n);                          //scanez din fisier datele de intrare
    fscanf(date,"%lld",&max_ad);

    a=(long long**)malloc(n*sizeof(long long*));
  	for(i=0;i<n;i++)                                //aloc spatiu pentru matricea initiala
        a[i]=(long long*)malloc(n*sizeof(long long));

    b=(long long**)malloc(n*sizeof(long long*));
  	for(i=0;i<n;i++)                                //aloc spatiu pentru matricea de costuri
        b[i]=(long long*)malloc(n*sizeof(long long));

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            fscanf(date,"%lld",&a[i][j]);           //bag in matricea initiala elementele
    fscanf(date,"%d",&inc_max);

    suma=a[n-1][n-1];
    suma=cerinta1(a,n-1,n-1,suma)+a[0][0];  //prima cerinta
    if(C1==1) fprintf(rezultate,"%lld",suma);

    if(C2==1)
        {
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    b[i][j]=0;
            curent=a[n-1][n-1];
            b[n-1][n-1]=a[n-1][n-1];
            for(i=n-2;i>=0;i--)
                {
                    b[i][n-1]=curent+a[i][n-1];
                    curent=curent+a[i][n-1];        //calculez si bag in matricea de costuri sumele de pe exterior
                }
            curent=a[n-1][n-1];
            for(j=n-2;j>=0;j--)
                {
                    b[n-1][j]=curent+a[n-1][j];
                    curent=curent+a[n-1][j];
                }
            for(i=n-2;i>=0;i--)
                cerinta2(a,b,n-2,i);            //apelez functia pentru toate coloanele
            fprintf(rezultate,"\n%lld",b[0][0]);
        }

    if(C3==1)
        {
            for(i=0;i<25;i++) v[i]=(rand()%2);  //am bagat intr-un vector elementele generate de rand

            while(inc_fac<inc_max)
                {
                    poz=cerinta3(a,poz,v,n,&suma);  //cat timp nu epoizam numarul de incercari apelez
                    inc_fac++;                      //functia de la pozitia la care am ramas
                    if(suma<=max_ad)
                        {
                            fprintf(rezultate,"\n%d",inc_fac);
                            break;                              //daca gaseste un drum sigur se opreste
                        }                                       //si afisaza numarul de incercari facute
                }
            if(inc_fac==inc_max) fprintf(rezultate,"\n0"); //daca nu afisaza 0

        }
    for(i=0;i<n;i++)
        free(a[i]);         //eliberez memoria
     for(i=0;i<n;i++)
        free(b[i]);
fclose(date);
fclose(rezultate);
}
