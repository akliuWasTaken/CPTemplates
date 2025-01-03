#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Notable uses below:
// Init:               Tree<T> s;
// Insert:             s.insert(val);
// Find by Order:      auto it = s.find_by_order(val);
// Order of Key:       s.order_of_key(val);
