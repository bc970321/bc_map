/*************************************************************************
	> File Name:    construct.h
	> Author:       candy7 
	> Mail:         bc970321@163.com
	> Created Time: 2019年08月05日 星期一 11时14分36秒
 ************************************************************************/
#include <type_traits>

namespace toy {

class ConstructHelper {
    template <typename T, bool is_pod>
    static void CopyConstructAux(T* ptr, const T & obj) {
        if constexpr (is_pod) {
            *ptr = obj;
        } else {
            new(ptr) T(obj);
        }
    }
public:
    template <typename T>
    static void CopyConstruct(T* ptr, const T& obj) {
        CopyConstructAux<T, std::is_pod_v<T>>(ptr, obj);
    }

};

}
