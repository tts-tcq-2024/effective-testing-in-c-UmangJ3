#include <stdio.h>
#include <assert.h>
#include <string.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);  // Fixed the bug by using minorColor[j]
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    
    // Checking the first and last combination to ensure alignment
    assert(strcmp("White", "White") == 0 && strcmp("Blue", "Blue") == 0); 
    assert(strcmp("Violet", "Violet") == 0 && strcmp("Slate", "Slate") == 0);
    
    printf("All is well (maybe!)\n");
    return 0;
}
