#include <stdio.h>

int main() {
    int i = 0;
    do {
        printf("start %d \n", i);
        i++;
        if (i == 2) {
            continue;
        }
        printf("end %d \n", i);
    } while (i < 4);
    return 0;
}