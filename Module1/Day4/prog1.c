#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double volumec(struct Box* ptr) {
    return ptr->length * ptr->width * ptr->height;
}

double surfaceAreac(struct Box* ptr) {
    double length = ptr->length;
    double width = ptr->width;
    double height = ptr->height;

    double topBottomArea = length * width;
    double frontBackArea = length * height;
    double leftRightArea = width * height;

    return 2 * (topBottomArea + frontBackArea + leftRightArea);
}

int main() {
    struct Box myBox;
    struct Box* ptr = &myBox;

    ptr->length = 2.5;
    ptr->width = 3.0;
    ptr->height = 4.0;

    double volume = volumec(ptr);
    double surfaceArea =surfaceAreac(ptr);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
