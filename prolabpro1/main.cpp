#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
char *file_path="C:\\Users\\oguzn\\OneDrive\\Masaüstü\\den.txt";
double splinex[1000];
double spliney[1000];
struct point   {
int x;
int y;   };
struct point pnt[6];
int get_size()   {
    FILE *f=fopen(file_path,"r");
//dosya
if(f!=NULL)   {
   int i=0;
   while(!feof(f))   {
      if(fgetc(f)==',')   {
          i++;   }   }
   fclose(f);
   return i;   }
else   {
    printf("File does not exist");   }   }//dosya
void readfile(char *coordinate)   {
FILE *f=fopen(file_path,"r");
int i=0;
if(f!=NULL)   {
   while(!feof(f))   {
       char c;
        c=fgetc(f);
       if(c!='{'&&c!='}')   {
          coordinate[i]=c;
        i++;   }   }
   fclose(f);   }
else   {
    printf("File does not exist");   }   }
    //dosya
void parse_coordinate(char *coor,struct point pt[],int size)   {
    char *say;
    say=strtok(coor," ,");
    pt[0].x=250+(((float)atoi(say))*10);
    say = strtok (NULL, " ,");
    pt[0].y=250-(((float)atoi(say))*10);
    for (int i = 1; i < size; i++)   {
            if((i+1)==size){
              pt[i]=pt[i-1];
            }
        else{
        say = strtok (NULL, " ,");
        pt[i].x=250+(((float)atoi(say))*10);
        say = strtok (NULL, " ,");
        pt[i].y=250-(((float)atoi(say))*10);  }
         }   }
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
        putpixel(x,y,BLUE);
        //line(x - 1, y, x + 1, y);
        //line(x, y - 1, x, y + 1);
      }
    }
}
int main()   {
    int size=get_size()/2+2;
    char coordinate[size*5];
    struct point pt[size];
    readfile(coordinate);
    //printf("%s",coordinate);
    parse_coordinate(coordinate,pt,size);
    float x,y,x2,y2;
    for(int i=0;i<size-1;i++)   {
       printf("( %d , %d )",(pt[i].x-250)/10,(250-pt[i].y)/10);   }
    printf("\n");
    float mer_x=0;
    float mer_y=0;
    float yaricap=0;
    if(size==1)   {
        printf("Cemberin merkezi=(%d %d)\nCemberin yaricapi=0(nokta)\n",(pt[0].x-250)/10,(250-pt[0].y)/10);   }
    else if(size==2)   {
    mer_x=(pt[0].x+pt[1].x)/2.0;
    mer_y=(pt[0].y+pt[1].y)/2.0;
    yaricap=sqrt(pow(pt[1].x-mer_x,2)+pow(pt[1].y-mer_y,2));
    printf("Cemberin merkezi=(%.2f %f)\nCemberin yaricapi=%.2f\n",(mer_x-250)/10,(250-mer_y)/10,yaricap/10);   }
        else   {
    float ebu=sqrt(pow(pt[1].x-pt[0].x,2)+pow(pt[1].y-pt[0].y,2));
    for(int i=0;i<size-1;i++)   {
    for(int j=i+1;j<size-1;j++)   {
        if(sqrt(pow(pt[j].x-pt[i].x,2)+pow(pt[j].y-pt[i].y,2))>ebu){
            ebu=sqrt(pow(pt[j].x-pt[i].x,2)+pow(pt[j].y-pt[i].y,2));
            x=pt[i].x;
            y=pt[i].y;
            x2=pt[j].x;
            y2=pt[j].y;   }   }   }
    printf("Iki nokta arasi en buyuk uzaklik=%.2f\nEn uzak noktalarin koordinatlari=(%.2f,%.2f)-(%.2f,%.2f)\n",ebu/10,(x-250)/10,(250-y)/10,(x2-250)/10,(250-y2)/10);
    float x3,y3,enuzakucuncuuzunluk=0;
    for(int i=0;i<size-1;i++)   {
    if(sqrt(pow(pt[i].x-x,2)+pow(pt[i].y-y,2))+sqrt(pow(pt[i].x-x2,2)+pow(pt[i].y-y2,2))>enuzakucuncuuzunluk){
        enuzakucuncuuzunluk=sqrt(pow(pt[i].x-x,2)+pow(pt[i].y-y,2))+sqrt(pow(pt[i].x-x2,2)+pow(pt[i].y-y2,2));
        x3=pt[i].x;
        y3=pt[i].y;   }   }
    printf("(%.2f,%.2f)-(%.2f,%.2f)'ya en uzak ucuncu nokta=(%.2f,%.2f)\n",(x-250)/10,(250-y)/10,(x2-250)/10,(250-y2)/10,(x3-250)/10,(250-y3)/10);
    mer_x=(x2+x)/2;
    mer_y=(y2+y)/2;
    yaricap=sqrt(pow(x-mer_x,2)+pow(y-mer_y,2));
    if((sqrt(pow(x3-mer_x,2)+pow(y3-mer_y,2)))>yaricap)   {
    float c23=0;
    float c12=0;
    float mb_norm=0;
    float ma_norm=0;
    c23=((y2+y3)/2)-(((x2+x3)/2)*((x3-x2)/(y2-y3)));
    c12=((y+y2)/2)-(((x+x2)/2)*((x-x2)/(y2-y)));
    ma_norm=((x-x2)/(y2-y));
    mb_norm=((x3-x2)/(y2-y3));
    mer_x=(c23-c12)/(ma_norm-mb_norm);
    mer_y=(ma_norm*mer_x)+c12;
    yaricap=sqrt(pow(x-mer_x,2)+pow(y-mer_y,2));
    printf("Cemberin merkezi= x:%.2f y:%.2f\nCemberin yaricapi=%.2f\n",(mer_x-250)/10,(250-mer_y)/10,yaricap/10);   }
    else   {
        printf("Cemberin merkezi= x:%.2f y:%f\nCemberin yaricapi=%.2f\n",(mer_x-250)/10,(250-mer_y)/10,yaricap/10);   }   }
        int gd= DETECT,gm;

initwindow(600,600);
settextstyle(SMALL_FONT,HORIZ_DIR,4);
char merkez[50];
sprintf(merkez,"Merkez=(%.2f,%.2f)",(mer_x-250)/10,(250-mer_y)/10);
char yaricap_[50];
sprintf(yaricap_,"Yaricap=(%.2f)",yaricap/10);
outtextxy(0,0,merkez);
outtextxy(0,10,yaricap_);
moveto(250,250);
lineto(250,0);
lineto(250,500);
moveto(250,250);
lineto(500,250);
lineto(0,250);
moveto(0,0);
outtextxy(250,250,"0");
outtextxy(500,255,"25");
outtextxy(505,245,"x");
outtextxy(235,0,"25");
outtextxy(230,500,"-25");
outtextxy(248,501,"y");
outtextxy(0,255,"-25");
outtextxy(270,255,"2");
outtextxy(290,255,"4");
outtextxy(310,255,"6");
outtextxy(330,255,"8");
outtextxy(350,255,"10");
outtextxy(370,255,"12");
outtextxy(390,255,"14");
outtextxy(410,255,"16");
outtextxy(430,255,"18");
outtextxy(450,255,"20");
outtextxy(470,255,"22");
outtextxy(234,30,"22");
outtextxy(234,50,"20");
outtextxy(235,70,"18");
outtextxy(235,90,"16");
outtextxy(235,110,"14");
outtextxy(235,130,"12");
outtextxy(235,150,"10");
outtextxy(235,170,"8");
outtextxy(235,190,"6");
outtextxy(235,210,"4");
outtextxy(235,230,"2");
outtextxy(235,270,"-2");
outtextxy(235,290,"-4");
outtextxy(235,310,"-6");
outtextxy(235,330,"-8");
outtextxy(230,350,"-10");
outtextxy(230,370,"-12");
outtextxy(230,390,"-14");
outtextxy(230,410,"-16");
outtextxy(230,430,"-18");
outtextxy(230,450,"-20");
outtextxy(230,470,"-22");
outtextxy(230,255,"-2");
outtextxy(210,255,"-4");
outtextxy(190,255,"-6");
outtextxy(170,255,"-8");
outtextxy(150,255,"-10");
outtextxy(130,255,"-12");
outtextxy(110,255,"-14");
outtextxy(90,255,"-16");
outtextxy(70,255,"-18");
outtextxy(50,255,"-20");
outtextxy(30,255,"-22");
circle(mer_x,mer_y,yaricap);
moveto(mer_x,mer_y);
lineto(x2,y2);
setcolor(9);
for(int i=0;i<size-1;i++)   {
circle(pt[i].x,pt[i].y,2);
floodfill(pt[i].x,pt[i].y,9);
char koord[50];
sprintf(koord,"(%d,%d)",(pt[i].x-250)/10,(250-pt[i].y)/10);
outtextxy(2+pt[i].x,pt[i].y-2,koord);   }
circle(mer_x,mer_y,2);
floodfill(mer_x,mer_y,9);
char merkezkoord[50];
sprintf(merkezkoord,"(%.1f,%.1f)",(mer_x-250)/10,(250-mer_y)/10);
outtextxy(mer_x-37,mer_y-10,merkezkoord);
draw(size,pt);
getch();
closegraph();

return 0;   }
