#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main()
{
 clrscr();
 char str[200],str2[200];
 cout<<"enter any string:";
 gets(str);
 for(i=0;str[i]!='\0';i++)
 {
  if(str[i]=='a')
	str2[i]='e';
  else if(str[i]=='e')
	str2[i]='i';
  else if(str[i]=='i')
	str2[i]='o';
  else if(str[i]=='o')
	str2[i]='u';
  else if(str[i]=='u')
	str2[i]='a';
  else if(str[i]=='b')
	str2[i]='z'
  else if(str[i]=='c')
	str2[i]='b';
  else if(str[i]=='d')
	str2[i]='c';
  else if(str[i]=='f')
	str2[i]='d';
  else	 if(str[i]=='g')
	str2[i]='f';
  else	 if(str[i]=='h')
	str2[i]='g';
  else	 if(str[i]=='j')
	str2[i]='h';
  else	 if(str[i]=='k')
	str2[i]='j';
  else	 if(str[i]=='l')
	str2[i]='k';
  else	 if(str[i]=='m')
	str2[i]='l';
  else	 if(str[i]=='n')
	str2[i]='m';

  else	 if(str[i]=='p')
	str2[i]='n';
  else	 if(str[i]=='q')
	str2[i]='p';
  else	 if(str[i]=='r')
	str2[i]='q';
  else	 if(str[i]=='s')
	str2[i]='r';
  else	 if(str[i]=='t')
	str2[i]='s';
  else	 if(str[i]=='v')
	str2[i]='t';
  else	 if(str[i]=='w')
	str2[i]='v';
  else	 if(str[i]=='x')
	str2[i]='w';
  else	 if(str[i]=='y')
	str2[i]='x';
  else	 if(str[i]=='z')
	str2[i]='y';
  else	 if(str[i]=='A')
	str2[i]='E';
  else	 if(str[i]=='B')
	str2[i]='Z';
  else	 if(str[i]=='C')
	str2[i]='B';
  else	 if(str[i]=='D')
	str2[i]='C';
  else	 if(str[i]=='F')
	str2[i]='D';
  else	 if(str[i]=='G')
	str2[i]='F';
  else	 if(str[i]=='H')
	str2[i]='G';
  else	 if(str[i]=='J')
	str2[i]='H';
  else	 if(str[i]=='K')
	str2[i]='J';
  else	 if(str[i]=='L')
	str2[i]='K';
  else	 if(str[i]=='M')
	str2[i]='L';
  else	 if(str[i]=='N')
	str2[i]='M';
  else	 if(str[i]=='P')
	str2[i]='N';
  else	 if(str[i]=='Q')
	str2[i]='P';
  else	 if(str[i]=='R')
	str2[i]='Q';
  else	 if(str[i]=='S')
	str2[i]='R';
  else	 if(str[i]=='T')
	str2[i]='S';
  else	 if(str[i]=='V')
	str2[i]='T';
  else	 if(str[i]=='W')
	str2[i]='V';
  else	 if(str[i]=='X')
	str2[i]='W';
  else	 if(str[i]=='Y')
	str2[i]='X';
  else	 if(str[i]=='Z')
	str2[i]='Y';
  else	 if(str[i]=='E')
	str2[i]='I';
  else	 if(str[i]=='I')
	str2[i]='O';
  else	 if(str[i]=='O')
	str2[i]='U';
  else	if(str[i]=='U')
	str2[i]='A';
 }
 cout<<"the encrypted string is:";
 puts(str2);
 getch();
}
