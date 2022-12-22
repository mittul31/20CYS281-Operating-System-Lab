#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>

// printWelcomeMessage will be called when the Thread is created in the main function 
// which takes string as an argument
void *addition() {
    int value1;
    int value2;
    printf("Enter the 1st element:");
    scanf("%d",&value1);
    printf("Enter the 2nd element:");
    scanf("%d",&value2);
    int total = value1 + value2;
    printf("%d",total);
   
}

int main () {

   // thread defintion
   pthread_t threads;
   int result;
   
      
      // Creating the threading and thus calling the function with parameter passed to it
      result = pthread_create(&threads, NULL, addition, NULL);
      
      if (result) {
      
         printf("Error in creating thread, %d ", result);
         exit(-1);
      }
      
   
   // Exit the thread
   pthread_exit(NULL);
}