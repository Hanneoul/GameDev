////#include <stdio.h>
////#include <stdlib.h>
////#include <time.h>
////#include <windows.h>
////
////#define RESET_COLOR "\033[0m"
////#define MAX_COLOR 7  // 0~7 color range for foreground and background (basic colors)
////#define ROWS 24
////#define COLS 80
////
////
////int main() {
////    // Seed the random number generator
////    srand(time(NULL));
////    
////    clock_t start_time, end_time;
////
////    int count = 0;
////    while (count<200) {
////        // Create a buffer to store the output string
////        char buffer[ROWS * (COLS+1) * 10];  // Allocate enough space for color codes and characters
////
////
////        int buffer_index = 0;  // Pointer to keep track of where we are in the buffer
////
////        // Generate the screen content
////        for (int i = 0; i < ROWS; i++) {
////            int color = rand() % (MAX_COLOR + 1);
////
////            for (int j = 0; j < COLS; j++) {
////            
////
////                // Write the color and character into the buffer using sprintf_s
////                buffer_index += sprintf_s(&buffer[buffer_index], sizeof(buffer) - buffer_index, "\033[4%dm ", color);
////            }
////            // Add a newline at the end of each row
////            buffer_index += sprintf_s(&buffer[buffer_index], sizeof(buffer) - buffer_index, "\033[0m\n");
////            if(i == ROWS-1)
////                sprintf_s(&buffer[buffer_index], sizeof(buffer) - buffer_index, "\033[0m\0");
////            
////        }
////
////        //0,0으로 이동
////        COORD coord = { 0, 0 };  // 좌표 (0, 0)
////        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
////        
////        start_time = clock();
////        // Output the entire buffer with a single printf
////        printf("%s", buffer);
////        end_time = clock();
////        printf("Time taken for direct assignment: %lf seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
////        count++;
////    }
////    return 0;
////}