#include"header.h"

float distance(int *arr1,int *arr2,int size)
{
        int i,sum=0;
        for(i=0;i<size;i++){
                sum=sum+pow((arr1[i]-arr2[i]),2);
        }
        return sqrt(sum);
}

void swap1(float *a,float *b)
{
	float c;
	c=*a;
	*a=*b;
	*b=c;
}

void swap2(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

void sort(float *arrayDist,int *arrayMovie,int size,int kvalue)
{
	int i,j,k=0;
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(arrayDist[j]<arrayDist[i]){
				swap1(&arrayDist[j],&arrayDist[i]);
				swap2(&arrayMovie[j],&arrayMovie[i]);
			}
		}
		k++;
		if(k==kvalue)
			break;
	}
	return;
}

int maxCount(int *arr,int size)
{
   int count[5]={0};
   int i;
   int max;
   for(i=0;i<size;i++){
     count[arr[i]-1]++;
   }
   max=0;
   for(i=1;i<5;i++){
   if(count[i]>count[max])
   max=i;	
   }
   return max+1;
}

int knn(struct user *userInfo,struct movie *movieInfo,int randomUser,int kvalue,int learningSize,int testMovie)
{
   int i;
   float dist;
   int tempB;
   float *tempArrayDist=(float *)malloc(sizeof(float)*learningSize);
   int *tempArrayMovie=(int *)malloc(sizeof(int)*learningSize);
   int rating;
   for(i=0;i<learningSize;i++){
     tempB=userInfo[randomUser].movieID[i];
     dist=distance(movieInfo[testMovie-1].genres,movieInfo[tempB-1].genres,MAX_GENRES);
     tempArrayDist[i]=dist;
     tempArrayMovie[i]=userInfo[randomUser].ratings[i];
   }
   sort(tempArrayDist,tempArrayMovie,learningSize,kvalue);
   rating=maxCount(tempArrayMovie,kvalue);
   free(tempArrayDist);
   free(tempArrayMovie);
   return rating;
}
