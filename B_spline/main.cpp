#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
double splinex[1000];
double spliney[1000];
struct point{
int x;
int y;
};
struct point pnt[6];
int get_size(){
    FILE *f=fopen("C:\\Users\\oguzn\\OneDrive\\Masaüstü\\den.txt","r");
//dosya
if(f!=NULL){
   int i=0;
   while(!feof(f)){

       if(fgetc(f)==','){
          i++;
       }
   }
   fclose(f);
   return i;
}
else{
    printf("File does not exist");
}
}// dosya
void readfile(char *coordinate){
FILE *f=fopen("C:\\Users\\oguzn\\OneDrive\\Masaüstü\\den.txt","r");
int i=0;
if(f!=NULL){
   while(!feof(f)){
       char c;
        c=fgetc(f);
       if(c!='{'&&c!='}'){
          coordinate[i]=c;
        i++;
       }
   }
   fclose(f);
}
else{
    printf("File does not exist");
}
}
//dosya
void parse_coordinate(char *coor,struct point pt[],int size){
    char *say;
    say=strtok(coor," ,");
    pt[0].x=(float)atoi(say);
    say = strtok (NULL, " ,");
    pt[0].y=(float)atoi(say);
    for (int i = 1; i < size; i++) {
        say = strtok (NULL, " ,");
        pt[i].x=(float)atoi(say);
        say = strtok (NULL, " ,");
        pt[i].y=(float)atoi(say);
    }
}
void bsp(struct point p1,struct point p2,struct point p3,struct point p4,int divisions){
            double *a = new double[5];
            double *b = new double[5];
            a[0] = (-p1.x + 3 * p2.x - 3 * p3.x + p4.x) / 6.0;
            a[1] = (3 * p1.x - 6 * p2.x + 3 * p3.x) / 6.0;
            a[2] = (-3 * p1.x + 3 * p3.x) / 6.0;
            a[3] = (p1.x + 4 * p2.x + p3.x) / 6.0;
            b[0] = (-p1.y + 3 * p2.y - 3 * p3.y + p4.y) / 6.0;
            b[1] = (3 * p1.y - 6 * p2.y + 3 * p3.y) / 6.0;
            b[2] = (-3 * p1.y + 3 * p3.y) / 6.0;
            b[3] = (p1.y + 4 * p2.y + p3.y) / 6.0;
            splinex[0] = a[3];
            spliney[0] = b[3];
            int i;
            for (i = 1; i <= divisions - 1; i++)
            {
             float  t = (float)i / (float)divisions;
             splinex[i] =  (a[2] + t * (a[1] + t * a[0]))*t+a[3]  ;
             spliney[i] =    (b[2] + t * (b[1] + t * b[0]))*t+b[3] ;
            }
}
void draw(int size,struct point *pt){


    pnt[0].x=0;pnt[0].y=0;pnt[1].x=0;pnt[1].y=0;pnt[2]=pt[0];pnt[3]=pt[1];
    int x;
    int y;
    for(int i=2;i<size;i++){
      pnt[0]=pnt[1];pnt[1]=pnt[2];pnt[2]=pnt[3];pnt[3]=pt[i];
      //printf("%d %d %d %d\n",pnt[0].x,pnt[1].x,pnt[2].x,pnt[3].x);
      double temp=sqrt(pow(pnt[2].x - pnt[1].x, 2)+pow(pnt[2].y - pnt[1].y, 2));
      int interpol=(int)temp;
      bsp(pnt[0],pnt[1],pnt[2],pnt[3],interpol);
      for(int j=0;j<=interpol-1;j++){
        x=splinex[j];
        y=spliney[j];
        line(x - 1, y, x + 1, y);
        line(x, y - 1, x, y + 1);
      }
    }
}
int main()
{   int size=get_size()/2+1;//dosya
printf("%d",size);
    //printf("%d ",size);
    char coordinate[size*5];
    struct point pt[size];
    readfile(coordinate);
    //printf("%s",coordinate);
    //printf("%d ",size);
    //printf("%d ",pt[6].x);
    parse_coordinate(coordinate,pt,size);
    for(int i=0;i<size;i++){
       printf("( %d , %d )",pt[i].x,pt[i].y);
    }
    /*char cor[50];
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    for(int i=0;i<size;i++){
       putpixel(pt[i].x,pt[i].y,YELLOW);
       sprintf(cor,"%d (%d,%d)",i+1,pt[i].x,pt[i].y);
       outtextxy(pt[i].x,pt[i].y-10,cor);
    }
    draw(size,pt);
    getch();
    closegraph();*/
}
