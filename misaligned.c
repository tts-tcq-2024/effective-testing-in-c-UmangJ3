#include <stdio.h>
#include <assert.h>
#include <string.h>

int printColorMap(char* buffer) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);  // Bug: minorColor[i] should be minorColor[j]
            sprintf(buffer + strlen(buffer), "%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]); // Bug: same here
        }
    }
    return i * j;
}

int main() {
    char buffer[1000] = {0};
    int result = printColorMap(buffer);
    
    const char* expectedMajorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* expectedMinorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    char line[100];
    int index = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            sprintf(line, "%d | %s | %s\n", index, expectedMajorColors[i], expectedMinorColors[j]);
            assert(strncmp(buffer + strlen(buffer) - strlen(line), line, strlen(line)) == 0); 
            index++;
        }
    }
    
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
