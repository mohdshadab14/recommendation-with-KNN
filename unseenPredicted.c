#include"header.h"

void unseenPredictions(struct user *userInfo,struct movie *movieInfo,int randomUser,int kvalue)
{
  int i,j,rating,max;
  int learning=learning=(userInfo[randomUser].index+1)*75/100;
  int *predictedRatings=(int *)malloc(sizeof(int)*MAX_MOVIES);
  for(i=0;i<MAX_MOVIES;i++){
    predictedRatings[i]=0;
  }	
  for(i=0;i<learning;i++){
    predictedRatings[userInfo[randomUser].movieID[i]-1]=-1;
  }
  for(i=learning;i<userInfo[randomUser].index;i++){
    predictedRatings[userInfo[randomUser].movieID[i]-1]=userInfo[randomUser].ratings[i];
  }	
  for(i=0;i<MAX_MOVIES;i++){
    if(predictedRatings[i]==0){
      rating=knn(userInfo,movieInfo,randomUser,kvalue,learning,i+1);
      predictedRatings[i]=rating;
    }
  }
  for(i=0;i<10;i++){
    max=0;
    for(j=0;j<MAX_MOVIES;j++){
    if(predictedRatings[max]<predictedRatings[j])
      max=j;
    }
    printf("Suggested movie is %d with predicted rating as %d\n",max+1,predictedRatings[max]);
    predictedRatings[max]=-1;
  }
  return;
}
