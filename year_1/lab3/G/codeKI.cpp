#include<string>
#include <iostream>
#include <fstream>
 
using namespace std;

ifstream fin("palindrome.in");
ofstream fout("palindromeKI.out");

const int l = 2002;
int d[l][l];
char s1[l], s2[l], out[l];
 
int Max (int a, int b)
{
    if (a > b)
       return a;
   else
       return b;
}
 
int length(int n)
{
for (int i = n; i >= 0; i--)
   for (int j = n; j >= 0; j--)
       {
           if ((s1[i] == '\0') || (s2[j] == '\0'))
               d[i][j] = 0;
           else
           {
               if (s1[i] != s2[j])
                   d[i][j] = Max (d[i+1][j], d[i][j+1]);
               else
                   d[i][j] = d[i+1][j+1] + 1 ;
           }
       }
       return d[0][0];
}
 
void gen_place(int n,int i,int j,int k)
{
   while (k < n)
   {
       if (d[i][j+1] != d[i][j])
        {
           if (d[i+1][j] == d[i][j])
               i++;
           else
           {
              out[k] = s1[i];
              k++;
              i++;
              j++;
           }
        }

       else
           j++;
       
   }
 
}
 
int main()
{
   int n, place;
   string str;
   fin>>str;
   n=str.size()+1;
   for(int i=0;i<n-1;i++)
       s1[i]=str[i];
   s1[n]='\0';

   for (int i = 0; i < n; i++)
       s2[n-i-2] = s1[i];

   s2[n-1] = s1[n-1];

   place = length(n);

   for (int i = 0; i < n; i++)
   gen_place(place,0,0,0);

   fout<<place<<endl;
   fout<<out;

   return 0;
} 