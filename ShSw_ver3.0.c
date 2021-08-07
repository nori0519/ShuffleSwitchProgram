#include <stdio.h>
#include <stdlib.h>
//数字をランダムに並び替える関数
void shuffleArrayData(int* array, int size){
    int i, target, tmp;
    
    for(i = size -1; i > 0; i--){
        target = rand() % i;
        tmp = array[target];
        array[target] = array[i];
        array[i] = tmp;
    }
    //5連続を防ぐ.
    for(i = size -1; i > 0; i--){
        target = rand() % i;
        if(array[i] == array[i+1] && array[i] == array[i+2] && array[i] == array[i+3]){
            tmp = array[target];
            array[target] = array[i];
            array[i] = tmp;
        }
        
    }
    //2連続を防ぐ.
    for(i = size -1; i > 0; i--){
        target = rand() % i;
        if(array[i] == array[i+1]){
            if(array[i]==1){
                tmp = array[target];
                array[target] = array[i];
                array[i] = tmp;
            }
        }
        
    }
    
    // for(i = 0; i < size; i++){
    //     printf("%d ", array[i]);
    // }
}
//数字を置換する関数
void switchnum(int* array,int* array2,int size,int* array3){
    int i,j,j_i,k;
    j=0;
    
    for(i = 0; i < size; i++){
        //待機モーション
        if(array2[i]==3){
            j_i=j+15;
            for(j;j<j_i;j++){
                if(j<j_i/2){
                    array3[j]=1;
                }else{
                    array3[j]=-1;
                }
            }
        }else if(array2[i]==5){
            j_i=j+25;
            for(j;j<j_i;j++){
                if(j<j_i/2){
                    array3[j]=1;
                }else{
                    array3[j]=-1;
                }
            }
        }else{
            j_i=j+50;
            for(j;j<j_i;j++){
                if(j<j_i-40){
                    array3[j]=1;
                }else if(j<j_i-30){
                    array3[j]=-1;
                }else if(j<j_i-20){
                    array3[j]=1;
                }else if(j<j_i-15){
                    array3[j]=-1;
                }else{
                    array3[j]=1;
                }
            }
        }
        //移動モーション
        if(array[i]==-1){
            j_i=j+50;
            for(j;j<j_i;j++){
                array3[j]=-1;
            }
        }else{
            j_i=j+50;
            for(j;j<j_i;j++){
                array3[j]=1;
            }
        }
        //for debug
        // printf("array[i]:%d\n",array[i]);
        // printf("array2[i]:%d\n",array2[i]);
        // printf("i:%d\n",i);
        //printf("j:%d\n",j);
        //(void)printf("%lu\n", ( sizeof(array3) / sizeof(int) ) );	// 配列の要素数
    }
}

int main(){
    int array[] = {-1, -1, -1, -1, -1, -1, 1,1,1,1,1,1};
    int array2[]={3,3,3,3,3,3,3,3,3,5,5,5,10};
    //
    int data[910];
    //int array[] = {4, 2};
    //int array[] = {4};
    
    for(int i=0;i<16;i++){
        //printf("%d回目\n",i+1);
        shuffleArrayData(array, (int)(sizeof(array) / sizeof(array[0])));
        //printf("\n");
        shuffleArrayData(array2, (int)(sizeof(array2) / sizeof(array2[0])));
        
        ////////////////////////////////////////////////////////////////////////
        //arrayとarray2を交互に出力
        //for debug:AIパターンを簡略化して表示
        // for(int j = 0; j < (int)(sizeof(array) / sizeof(array[0])); j++){
        //      int size=(int)(sizeof(array) / sizeof(array[0]));
        //      printf("%d,%d,", array2[j],array[j]);
        //      //最後に追加
        //      if(j == size-1){
        //         printf("%d",array2[j+1]);
        //      }
        // }
        // printf("\n");
        
        switchnum(array,array2,(int)(sizeof(array2) / sizeof(array2[0])),data);
        //array3を出力
        for(int i = 0; i < (int)(sizeof(data) / sizeof(data[0])); i++){
            int size=(int)(sizeof(data) / sizeof(data[0]));
            if(i==0){
                printf("{");
            }
            if(i<size-1){
                //printf("%d,", data[i]);
                //printf("i:%d\n",i);
                printf("%d,",data[i]);
            }else{
                //printf("i:%d\n",i);
                printf("%d",data[i]);
            }
            if(i==(int)(sizeof(data) / sizeof(data[0]))-1){
                printf("},\n");
            }
        }
        //printf("\n");
    }
    return 0;
}

