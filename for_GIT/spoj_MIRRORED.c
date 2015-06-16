#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>

char arr[1000][2];
int main(){
    long int i;
    long int n=0;
    while(1){
        scanf(" %c",&arr[i][0]);
        if(arr[i][0]=='13')
            break;
        scanf(" %c",&arr[i][1]);
        i++;
    }
    printf("Ready\n");
    n=0;
    while(n<i){

        if((arr[n][0]==32) && (arr[n][1]==32))
            break;
        while(1){
            if(arr[n][0]=='p'){
                if(arr[n][1]=='q'){
                    printf("Mirrored pair\n");
                    break;
                }
            }
            if(arr[n][0]=='q'){
                if(arr[n][1]=='p'){
                    printf("Mirrored pair\n");
                    break;
                }
            }
            if(arr[n][0]=='d'){
                if(arr[n][1]=='b'){
                    printf("Mirrored pair\n");
                    break;
                }
            }
            if(arr[n][0]=='b'){
                if(arr[n][1]=='d'){
                    printf("Mirrored pair\n");
                    break;
                }
            }

            printf("Ordinary pair\n");
            break;
        }
        n++;
    }
    return 0;
}

