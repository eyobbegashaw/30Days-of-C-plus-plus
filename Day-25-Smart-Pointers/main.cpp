#include <iostream>
#include <memory>
#include <vector>
#include "../utils/common.hpp"

using namespace std;

class Resource {
private:
    string name;
public:
    Resource(string n) : name(n) {
        cout << "Resource " << name << " created" << endl;
    }
    
    ~Resource() {
        cout << "Resource " << name << " destroyed" << endl;
    }
    
    void use() {
        cout << "Using resource: " << name << endl;
    }
};

void uniquePointerDemo() {
    cout << "\n🔒 Unique Pointer Demo:" << endl;
    unique_ptr<Resource> res1 = make_unique<Resource>("Unique1");
    res1->use();
    
    // Transfer ownership
    unique_ptr<Resource> res2 = move(res1);
    if (!res1) {
        cout << "res1 is now empty" << endl;
    }
    res2->use();
}

void sharedPointerDemo() {
    cout << "\n🤝 Shared Pointer Demo:" << endl;
    shared_ptr<Resource> res1 = make_shared<Resource>("Shared1");
    {
        shared_ptr<Resource> res2 = res1;
        cout << "Use count: " << res1.use_count() << endl;
        res2->use();
    }
    cout << "Use count after scope: " << res1.use_count() << endl;
    res1->use();
}

void weakPointerDemo() {
    cout << "\n🔄 Weak Pointer Demo:" << endl;
    shared_ptr<Resource> shared = make_shared<Resource>("WeakDemo");
    weak_ptr<Resource> weak = shared;
    
    if (auto temp = weak.lock()) {
        temp->use();
        cout << "Resource is still alive" << endl;
    } else {
        cout << "Resource has been destroyed" << endl;
    }
}

int main() {
    cout << "Day 25: Smart Pointers" << endl;
    cout << "======================" << endl;
    
    uniquePointerDemo();
    sharedPointerDemo();
    weakPointerDemo();
    
    return 0;
}