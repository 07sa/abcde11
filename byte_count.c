#include <stdio.h>
#include <string.h>
#define S 1000

char data2[S];

void sender(){
    char data1[S];
    char data[S];
    int data_len=0, i=0;
    
    // Prompt user to enter data
    printf("Enter Data:");
    scanf("%s", data);
    
    // Calculate length of input data
    data_len = strlen(data);

    // Reverse the input data and convert each character to integer
    for (int i = 0; i < data_len; i++) {
        data1[i] = data[data_len - i - 1] - '0';
    }
    
    // Store the length of the data followed by the reversed data in data2
    data2[0]=data_len+1;
    int k=1;
    for(int i=data_len-1; i>=0; i--){
        data2[k++]=data1[i];
    }
   
    // Print the data to be sent by the sender
    printf("Sender's data:");
    for(int i=0; i<data_len+1; i++){
        printf("%d",data2[i]);
    }
    printf("\n");
}

void receiver(char data[]){
    char rev_data[S];
    int data_sz = data[0];
    int j=0;
    
    // Retrieve the original data from the received data2 array
    for (int i = 1; i < data_sz; i++)
    {
        rev_data[j++]=data[i];
    }
    
    // Print the original received data
    printf("Original received data: ");
    for(int i=0; i<data_sz-1; i++){
        printf("%d",rev_data[i]);
    }
    printf("\n");
}

int main(){
    // Call sender function to initiate data transmission
    sender();
    
    // Call receiver function to process the received data
    receiver(data2);
    
    return 0;
}
