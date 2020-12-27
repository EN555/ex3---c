#include<stdio.h>

int shift_element(int *arr, int i){
    
    for(int j= i ; j>0 ; j--){  
        
        *(arr+j) = *(arr+j-1);
    }
    
    return 0;
}


int insertion_sort(int *arr, int len){  //len sighnifies the number of integers in the array
    
    int i=0;    //counter at which index we point in the array
    
    while(i < len-1){
    
    if(*(arr +i) > *(arr+ i + 1)){
        
        int temp = *(arr + i + 1);
        
        //move fron this location to the start of the array anf search the correct location for this number 
        
        int j=i;

        while(*(arr + j) > temp && j>=0){       //find the new location 
          
            shift_element(arr + j, 1);
           
            j--;
        }
        
        *(arr+ j +1) = temp;
        
    }
    
    i++;  
    
    }
    
    return 0;
}


int main(){
	
	
	int arr[50] ={0};
	int num=0;
	
	int i=0;
	while(i<50){	
	scanf("%d", &num);
	arr[i++] = num;	
	}
	
	insertion_sort(arr, 50);
	
	int counter=0;
	while(counter<50){
		
		 printf(" %d" ,arr[counter++]);
	 }
	
return 0;	
	
}	