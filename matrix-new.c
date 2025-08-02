#include<stdio.h>
int main(){
        int row, col;
        printf("Enter number of rows: ");
        scanf("%d",&row);
        printf("Enter number of columns: ");
        scanf("%d",&col);

        int mat1[row][col],mat2[row][col];
        printf("Enter elements of first matrix: \n");
        for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                        printf("Enter element at %d %d: ",i+1,j+1);
                        scanf("%d",&mat1[i][j]);
                }
        }

        printf("Enter elements of second matrix: \n");
        for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                        printf("Enter element at %d %d: ",i+1,j+1);
                        scanf("%d",&mat2[i][j]);
                }
        }

        int size1=0,size2=0;
        for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                        if(mat1[i][j]!=0){
                                size1++;
                        }
                }
        }

        for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                        if(mat2[i][j]!=0){
                                size2++;
                        }
                }
        }

        //Conversion from Sparse Matrix to Compact form
        int comp1[size1][3], comp2[size2][3],row1=0,row2=0;
        for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                        if(mat1[i][j]!=0){
                                comp1[row1][1]=i;
                                comp1[row1][2]=j;
                                comp1[row1][3]=mat1[i][j];
                                row1++;
                        }
                }
        }

        for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                        if(mat2[i][j]!=0){
                                comp2[row2][1]=i;
                                comp2[row2][2]=j;
                                comp2[row2][3]=mat2[i][j];
                        }
                }
        }
        //First compact matrix
        for(int i=0;i<size1;i++){
                for(int j=0;j<3;j++){
                        printf("%d\t",comp1[i][j]);
                }
                printf("\n");
        }

        //Second compact matrix
        for(int i=0;i<size2;i++){
                for(int j=0;j<3;j++){
                        printf("%d\t",comp2[i][j]);
                }
                printf("\n");
        }

        int size3;
        if(size1>size2){
                size3=size1;
        }
        else{
                size3=size2;
        }

        int resComp[size3][3];
        for(int i=0;i<size3;i++){
                for(int j=0;j<3;j++){
                        resComp[i][j]=comp1[i][j]+comp2[i][j];
                }
        }

        for(int i=0;i<size3;i++){
                for(int j=0;j<3;j++){
                        printf("%d\t",resComp[i][j]);
                }
                printf("\n");
        }



        return 0;
}