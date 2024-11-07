#include <iostream>
#include <memory>

using namespace std;

class VagonSystem {
public:
    virtual void chargeLaptop() = 0;  
};

class NewVagonSystem : public VagonSystem {
public:
    void chargeLaptop() override {
        cout << "The laptop is charged from a modern outlet" << endl;
    }
};

class OldVagonSystem {
public:
    void thinSocket() {
        cout << "Connected to a narrow socket (old railroad car)" << endl;
    }
};

class Adapter : public VagonSystem {
private:
    OldVagonSystem* oldSystem;

public:
    Adapter(OldVagonSystem* oldSys) : oldSystem(oldSys) {}

    void chargeLaptop() override {
        cout << "The adapter converts the connector... ";
        oldSystem->thinSocket();  
    }
};

int main() {
    unique_ptr<VagonSystem> newVagon = make_unique<NewVagonSystem>();
    newVagon->chargeLaptop();  

    OldVagonSystem oldVagon;
    unique_ptr<VagonSystem> adapter = make_unique<Adapter>(&oldVagon);
    adapter->chargeLaptop();  

    return 0;
}
