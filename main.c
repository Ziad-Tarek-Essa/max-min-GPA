#include <stdio.h>
#include <stdlib.h>

struct student {
int id;
char name[30];
float gpa;
char grade;
};
int main()
{
    struct student st[100];
    FILE * fptr;
    struct student max,min;
    int i=0;
    int j;
    fptr=fopen("student_file.txt", "r");
    if (fptr != NULL) {
        while (!feof(fptr)) {
         fscanf(fptr,"%d,%[^,],%f",&st[i].id,st[i].name,&st[i].gpa);
          fscanf(fptr, "\n");
            i++;
        }
     fclose(fptr);
      for(j=0;j<i;j++)
      {
          if(st[j].gpa<=4 && st[j].gpa>=3.5)
            st[j].grade='A';
          else if(st[j].gpa<3.5 && st[j].gpa>=3)
            st[j].grade='B';
          else if(st[j].gpa<3 && st[j].gpa>=2.5)
             st[j].grade='C';
          else if(st[j].gpa<=2.5 && st[j].gpa>=2)
             st[j].grade='D';
          else if(st[j].gpa<2)
             st[j].grade='F';
      }
      max=st[0];
      for(j=1;j<i;j++)
      {
        if(st[j].gpa>max.gpa)
        max=st[j];
      }
      min=st[0];
      for(j=1;j<i;j++)
      {
          if(st[j].gpa<min.gpa)
            min=st[j];
      }

      printf("STUDENT ID \t STUDENT NAME \t GPA \t GRADE \n");
       for(j=0;j<i;j++){
        printf("%d       \t %s  \t %.3f \t %c  \n",st[j].id,st[j].name,st[j].gpa,st[j].grade);}




       float average,x=0;
       for(j=0;j<i;j++){
        x=st[j].gpa+=x;

       }
       average=(x*1.0)/i;

        printf("\nThe Minimum=%.3f",min.gpa);
        printf("\nThe Maximum=%.3f",max.gpa);
        printf("\nThe Average=%.3f\n\n",average);
    }
    else
        printf("Null");
    return 0;
}
