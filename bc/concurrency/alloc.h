/*************************************************************************
	> File Name:    alloc.h
	> Author:       candy7 
	> Mail:         bc970321@163.com
	> Created Time: 2019年08月05日 星期一 11时17分57秒
 ************************************************************************/
#pragma once

namespace toy {


template <bool clear_mem>
class StepAllocator {
public:

    void * alloc(size_t n);

    void * free(void * p, size_t n);

    void * realloc(void * p, size_t old_size, size_t new_size);

};

//class NodeAllocator {
//    void * free_list[16];
//    NodeAllocator() ;
//}

}
