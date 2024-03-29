/*************************************************************************
	> File Name:    map.h
	> Author:       candy7 
	> Mail:         bc970321@163.com
	> Created Time: 2019年08月05日 星期一 11时19分28秒
 ************************************************************************/
#pragma once

#include "bst.h"
#include "alloc.h"

#include<functional>

namespace toy {

// This map is a common interface, which supports different underlying algos.
template <typename Key, typename Value, typename Compare = std::less<Key>, typename Allocator = StepAllocator<true>, class TreeType = BinarySearchTree<Key, Compare, std::pair<Key, Value>> >
class map
{
public:
    using ValuePair = std::pair<Key, Value>;
    using Tree = TreeType;
    using iterator = typename Tree::iterator;
    using const_iterator = typename Tree::const_iterator;

    map() : tree() {}

    std::pair<iterator, bool> insert(const ValuePair & value_pair) 
    {
        return tree.insert_unique(value_pair);
    }

    size_t erase(const Key & key) {
        return tree.erase(key);
    }

    iterator find(const Key & key) {
        return tree.find(key);
    }

    const_iterator find(const Key & key) const {
        return tree.find(key);
    }

    iterator begin() {
        return tree.begin();
    }

    const_iterator begin() const {
        return tree.begin();
    }

    iterator end() {
        return tree.end();
    }

    const_iterator end() const {
        return tree.end();
    }

private:
    Tree tree;
};

}
