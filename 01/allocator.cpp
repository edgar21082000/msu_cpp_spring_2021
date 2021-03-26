#include <cstddef>
#include "allocator.hpp"


void Allocator::makeAllocator(size_t maxSize){
    char *newbegin = new char[maxSize];
    // При перевыделении памяти старые данные теряются
    
    delete[] begin;
    begin = newbegin;
    All_size = maxSize;
}

char* Allocator::alloc(size_t size){
    if(offset + size <= All_size){
        offset += size;
        return begin + (offset - size);
    } else
        return nullptr;
}

void Allocator::reset(){
    offset = 0;
}
