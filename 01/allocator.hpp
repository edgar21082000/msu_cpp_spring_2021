#pragma once

class Allocator
{
    char *begin = nullptr;
    size_t All_size{}, offset{}; 
public:
    Allocator() = default;
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    ~Allocator(){
        delete[] begin;
    }
};
