
#include <stdio.h>
#include <stdlib.h>

struct point{
int x;
int y;
};
int get_size(){
    FILE *f=fopen("C:\\Users\\oguzn\\OneDrive\\Masaüstü\\den.txt","r");

if(f!=NULL){
   int i=0;
   while(!feof(f)){

       if(fgetc(f)!='{'&&fgetc(f)!='}'&&fgetc(f)!=','){
          i++;
       }
   }
   fclose(f);
   return i;
}
else{
    printf("File does not exist");
}
}
void readfile(struct point *pt){
FILE *f=fopen("C:\\Users\\oguzn\\OneDrive\\Masaüstü\\den.txt","r");
int i=0;
if(f!=NULL){
   while(!feof(f)){
       char c;
        c=fgetc(f);
       if(c!='{'&&c!='}'&&c!=','){
          if(i%2==0){
            pt[i/2].x=c-'0';
            i++;
          }
          else{
            pt[i/2].y=c-'0';
            i++;
          }
       }
   }
   fclose(f);
}
else{
    printf("File does not exist");
}
}
int main()
{   int size=get_size();
    struct point *pt=malloc(sizeof(struct point)*(size/2));
    readfile(pt);
    for(int i=0;i<size/2;i++){
       printf("( %d , %d )",pt[i].x,pt[i].y);
    }


    return 0;
}
