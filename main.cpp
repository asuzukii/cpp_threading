#include <iostream>

#include "stretchy_buffer.h"

struct Point {
    int x, y, z;
};
int main() {
    Point *p_arr = nullptr;
    Point test;
    SB_PUSH(&p_arr, test);
}