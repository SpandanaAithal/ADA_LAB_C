#include<stdio.h>
#define max 100
double ComputeMaxValue(double w,double weight[],double value[],double ratio[],int nItems){
double cw=0;
double cv=0;
printf("\nItems considered are:");
while(cw<w){
int item=getNextItem(weight,value,ratio,nItems);
if(item==-1){
break;
}
printf("%d ",item+1);
if(cw+weight[item]<=w){
cw+=weight[item];
cv+=value[item];
ratio[item]=0;
}
else{
cv+=(ratio[item]*(w-cw));
cw+=(w-cw);
break;
}
}
return cv;
}

int getNextItem(double weight[],double value[],double ratio[],int nItems){
double highest=0;
int i;
int index=-1;
for(i=0;i<nItems;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}
}
return index;
}

int main(){
int i,nItems;
double w;
double weight[max];
double value[max];
double ratio[max];
printf("Enter the number of items:\n");
scanf("%d",&nItems);
printf("Enter the weights\n");
for(i=0;i<nItems;i++){
scanf("%lf",&weight[i]);
}
printf("Enter the value/profit\n");
for( i=0;i<nItems;i++){
scanf("%lf",&value[i]);
}
for(i=0;i<nItems;i++){
ratio[i]=value[i]/weight[i];
}
printf("Enter the capacity of the Knapsack:");
scanf("%lf",&w);
printf("\nThe maximum value in a Knapsack of capacity %.2f is: %.2f\n",w,ComputeMaxValue(w,weight,value,ratio,nItems));
return 0;
}
