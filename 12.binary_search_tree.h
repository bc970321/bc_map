#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

namespace haizei {

struct BaseNode {
    BaseNode(BaseNode *parents = nullptr) : 
        parents(parents),
        rchild(nullptr),
        lchild(nullptr);
    BaseNode *&plchild() { return this->parents->lchild; }
    BaseNode *&prchild() { return this->parents->rchild; }
    BaseNode *lchild, *rchild, *parents;
    virtual ~BaseNode() {}
};


template<typename VALUE_T>
struct TreeNode : BaseNode{
    TreeNode(VALUE_T value, TreeNode *parents = nullptr) :
        BaseNode(parents),
        value(value) {}
    VALUE_T value;
};

template<typename VALUE_T>
class BinarySearchTreeIteratorImpl {
public:
    using pTreeNode = TreeNode<VALUE_T> *;
    using Self = BinarySearchTreeIteratorImpl<VALUE_T>;
    BinarySearchTreeIteratorImpl(BaseNode *obj) : obj(obj) {}
    VALUE_T operator *();
    Self &operator++();
    Self operator++(int);
    Self &operator--();
    Self operator--(int); 
    bool operator != (const Self &iter) { return this->obj != iter.obj; }
    pTreeNode getObj() {return this->obj; };
private:
    BaseNode *obj;
}; 

class BinarySearchTreeHelper {
public:
    pTreeNode = BaseNode *;
    static pTreeNode descrement(pTreeNode node) {
        if (node->lchild) return BinarySearchTreeHelper::rightMost(node->lchild);
        while (node->parents != node && node->plchild() == node) node = node->parents;
        return node->parents;
    }
    static pTreeNode increment(pTreeNode node) {
        if (node->rchild) return BinarySearchTreeHelper::leftMost(node->rchild);
        while (node->parents != node && node->prchild() == node) node = node->parents;
        return node->parents;
    }
    static pTreeNode rightMost(pTreeNode node) {
        while (node->rchild) node = node->rchild;
        return node;
    }
    static pTreeNode leftMost(pTreeNode node) {
        while (node->lchild) node = node->lchild;
        return node;
    }
};

template<typename VALUE_T>
class BinarySearchTree{
public:
    using node = TreeNode<VALUE_T>
    using pNode = TreeNode<VALUE_T> *;
    using pBaseNode = BaseNode *;
    using iterator = BinarySearchTreeIteratorImpl<VALUE_T>;

    BinarySearchTree() : header(nullptr) {
        header = (node *)malloc(sizeof(node)); 
        header->lchild = header->rchild = nullptr;
        header->parents = header;
    }
    bool insert(VALUE_T value) {
        if (root() == nullptr) {
            header->lchild= new node(value, header);
            return true;
        }
        pNode p = root();
        for(;;) {
            if (value < p->value) {
                if (p->lchild) p = dynamic_cast<pNode>(p->lchild);
                else break;
            }
            if (value > p->value) {
                if (p->rchild) p = p->rchild;
                else break;
            }
            if (value == p->value) return false;
        }
        (value < p->value ? p->lchild : p->rchild) = new node(value, p);
        return true;
    }
    
    iterator find(const VALUE_T &value) {
        pNode p = root();
        while (p) {
            if (p->value > value) p = dynamic_cast<pNode>p->lchild;
            else if (p->value < value) p = dynamic_cast<pNode>p->rchild;
            else return iterator(p);
        }
        return end();
    }
    
    bool erase(const VALUE_T &value) {
        pNode p = find(value).getObj();
        if (p == end().getObj()) return false;
        if (p->lchild == nullptr || p->rchild == nullptr) {
            pNode temp = dynamic_cast<pNode>(p->lchild ? p->lchild : p->rchild);
            (p->plchild() == p ? p->plchild() : p->prchild()) = temp;
            delete p;
            return true;
        }
        pNode temp = dynamic_cast<pNode>(BinarySearchTreeHelper::descrement(p));
        swap(p->value, temp->value);
        p = temp;
        temp = dynamic_cast<pNode>((p->lchild ? p->lchild : p->rchild));
        (p->plchild() == p ? p->plchild() : p->prchild()) = temp;
        delete p;
        return true;
    }
    iterator begin() {return iterator(BinarySearchTreeHelper::leftMost(header)); }
    iterator end() { return iterator(header); }

    ~BinarySearchTree() {
        free(header);
    }

private:
    pNode header;
    pNode root() {
        return dynamic_cast<pNode>(header->lchild);
    }

};
template<typename T>
T BinarySearchTreeIteratorImpl::operator *() { 
    return dynamic_cast<TreeNode<T> *>(obj)->value; 
}

template<typename T>
BinarySearchTreeIteratorImpl &BinarySearchTreeIteratorImpl<T>::operator++() {
    obj = BinarySearchTreeHelper::increment(obj);
    return *this;
}

template<typename T>
BinarySearchTreeIteratorImpl BinarySearchTreeIteratorImpl<T>::operator++(int) {
    Self old = *this;
    obj = BinarySearchTreeHelper::increment(obj);
    return old;
}
template<typename T>
BinarySearchTreeIteratorImpl &BinarySearchTreeIteratorImpl<T>::operator--() {
    obj = BinarySearchTreeHelper::descrement(obj);
    return *this;
}   
template<typename T>
BinarySearchTreeIteratorImpl BinarySearchTreeIteratorImpl<T>::operator--(int) {
    Self old = *this;
    obj = BinarySearchTreeHelper::descrement(obj);
    return old;
}

} // namespace haizei

