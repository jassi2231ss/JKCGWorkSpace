#include "common.h"
char arr[][MAX_LEN]={"user1","user2","user3","user4"};
char *swap_elements(char arr1[][MAX_LEN],int index)
{
 char temp[20];
 strcpy(temp,arr1[0]);
 strcpy(arr1[0],arr1[index]);
 strcpy(arr1[index],temp);
for(int x=0;x<4;x++)
{
  printf("%s\n",arr1[x]);
}
  return *arr1;
}

int isVowel(char x)
{
if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
{
   return EXIT_SUCCESS;
}
else
 {
   return EXIT_FAILURE;
 }
}


char *remove_vowel(char arr1[][MAX_LEN],int index)
{
char large[MAX_LEN];
int e=0;
for(int x=0;arr1[index][x]!='\0';x++)
{
if(isVowel(arr1[index][x])==1)
 {
  large[e]=arr1[index][x];
  e++;
 }
}
  large[e]='\0';
  printf("After removing vowels%s\n",large);
}


char *mystrcat(const char *str1,const char *str2)
{
int i=0,j=0;
char *result=malloc(strlen(str1)+strlen(str2)+1);
while(*str1)
{
  result[i++]=*str1++;
}
while(*str2)
 {
   result[i++]=*str2++;
 }
   result[i+j]='\0';
   return result;
}



int display()
{
  int x=0;
  for(x=0;x<4;x++)
{
  printf("%s\n",arr[x]);
}
  return EXIT_SUCCESS;
}

int main()
{
  int n;
  char a;
  printf("Enter a letter:\n");
  scanf("%c",&a);
  int e=isVowel(a);
 if(e==EXIT_SUCCESS)
 {
  printf("\nThe entered letter is a vowel\n");
}
else
{
 printf("\n The entered letter is not a vowel\n");
}
printf("The contents of the array before swapping\n");
display();
printf("Enter the index number:\n");
scanf("%d",&n);
printf("The swapped element at given index is %s\n",swap_elements(arr,n));
remove_vowel(arr,n);
return EXIT_SUCCESS;
}
