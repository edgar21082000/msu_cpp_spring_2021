#include <iostream>
#include "allocator.hpp"

const size_t size_1 = 10, size_2 = 5, size_3 = 15;

void one_good_alloc(void){
    Allocator mem;
    mem.makeAllocator(size_1);
    size_t p_size = 4;
    char *p = mem.alloc(p_size);
    if(p) std::cout << "#one_good_alloc\n";
    for(size_t i = 0; i < p_size; i++){
        p[i] = 'a' + i; 
        std::cout << p[i];
    }
    std::cout << "\n";
}

void two_good_alloc(void){
    Allocator mem;
    mem.makeAllocator(size_1);
    size_t p_size = 4;
    char *p = mem.alloc(p_size);
    if(p) std::cout << "#first_good_alloc\n";
    for(size_t i = 0; i < p_size; i++){
        p[i] = 'a' + i;
        std::cout << p[i];
    }
    std::cout << "\n";
    
    size_t q_size = 5;
    char *q = mem.alloc(q_size);
    if(q) std::cout << "#second_good_alloc\n";
    for(size_t i = 0; i < q_size; i++){
        q[i] = 'a' + i;
        std::cout << q[i];
    }
    std::cout << "\n";
    
    std::cout << "in memory: ";
    for(size_t i = 0; i<p_size + q_size; i++)
        std::cout << p[i] << " ";
    
    std::cout << "\n";
}

void bad_alloc(void){
    Allocator mem;
    mem.makeAllocator(size_1);
    size_t p_size = 4;
    char *p = mem.alloc(p_size);
    if(p) std::cout << "#first_good_alloc\n";
    for(size_t i = 0; i < p_size; i++){
        p[i] = 'a' + i;
        std::cout << p[i];
    }
    std::cout << "\n";
    
    size_t q_size = 10;
    char *q = mem.alloc(q_size);
    if(!q) std::cout << "bad_alloc\n";
}

void twice_makeAlloc(void){
    Allocator mem;
    mem.makeAllocator(size_1);
    size_t p_size = 8;
    char *p = mem.alloc(p_size);
    if(p) std::cout << "#one_good_alloc\n";
    for(size_t i = 0; i < p_size; i++){
        p[i] = 'a' + i; 
        std::cout << p[i];
    }
    std::cout << "\n";
    
    mem.makeAllocator(size_2);
    char *q = mem.alloc(size_2);
    if(q) std::cout << "makeAllocator twice\n";
}

void reset_test(void){
    Allocator mem;
    mem.makeAllocator(size_1);
    size_t p_size = 4;
    char *p = mem.alloc(p_size);
    if(p) std::cout << "#first_good_alloc\n";
    for(size_t i = 0; i < p_size; i++){
        p[i] = 'a' + i;
        std::cout << p[i];
    }
    std::cout << "\n";
    
    size_t q_size = 5;
    char *q = mem.alloc(q_size);
    if(q) std::cout << "#second_good_alloc\n";
    for(size_t i = 0; i < q_size; i++){
        q[i] = 'a' + i;
        std::cout << q[i];
    }
    std::cout << "\n";
    
    std::cout << "in memory: ";
    for(size_t i = 0; i < p_size + q_size; i++)
        std::cout << p[i] << " ";
    
    std::cout << "\n";
    
    mem.reset();
    
    size_t r_size = 7;
    char *r = mem.alloc(r_size);
    for(size_t i = 0; i < r_size; i++){
        r[i] = 'z' - i;
        std::cout << r[i];
    }
    std::cout << "\n";
    
    std::cout << "in memory: ";
    size_t cur_size = r_size > p_size + q_size ? r_size : p_size + q_size;
    for(size_t i = 0; i < cur_size; i++)
        std::cout << p[i] << " ";
    
    std::cout << "\n";
}


int main(void){
    one_good_alloc(); std::cout << "\n";
    two_good_alloc(); std::cout << "\n";
    bad_alloc(); std::cout << "\n";
    twice_makeAlloc(); std::cout << "\n";
    reset_test(); std::cout << "\n";
    return 0;
}
