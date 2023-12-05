#include <corecrt_malloc.h>
void* SbPushImpl(void** pp, void* val_ptr, size_t val_size) {
    size_t capacity, ctr;
    if (pp == nullptr) {
        *pp = calloc(val_size * 8);
    } else {
        // assume pp is valid, and the 16 bytes before it are the counter
        // and capacity
        ctr = *reinterpret_cast<size_t*>(pp - 1);
        capacity = *reinterpret_cast<size_t*>(pp - 2);
        if (ctr > capacity) {
            // realloc
        }
    }
    return nullptr;
}
#define SB_PUSH(pp, val)                      \
    (*pp = reinterpret_cast<decltype(pp[0])>( \
         SbPushImpl((void**)pp, (void*)&val, sizeof(val))))

//
//