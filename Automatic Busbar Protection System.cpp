#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AutomaticBusbarProtection {
private:
    double currentLimit;
    bool breakerStatus;

public:
    AutomaticBusbarProtection(double limit) {
        currentLimit = limit;
        breakerStatus = true;
    }

    void checkFeeder(string feederName, double current) {
        cout << "\nFeeder: " << feederName << endl;
        cout << "Measured Current: " << current << " A" << endl;

        if (current > currentLimit) {
            cout << "Fault Detected!" << endl;
            cout << "Overcurrent on " << feederName << endl;
            tripBreaker();
        }
        else {
            cout << "Status: NORMAL" << endl;
        }
    }

    void tripBreaker() {
        breakerStatus = false;
        cout << "Busbar Protection: TRIPPED" << endl;
        cout << "Circuit Breaker: OPEN" << endl;
        cout << "Busbar Supply: DISCONNECTED" << endl;
    }

    void resetBreaker() {
        breakerStatus = true;
        cout << "\nBreaker Reset." << endl;
        cout << "Circuit Breaker: CLOSED" << endl;
        cout << "Busbar Supply: RESTORED" << endl;
    }

    void displayStatus() {
        cout << "\n----- Busbar Protection Status -----" << endl;

        if (breakerStatus)
            cout << "System Status: NORMAL" << endl;
        else
            cout << "System Status: FAULT / TRIPPED" << endl;
    }
};

int main() {

    // Maximum permissible feeder current
    double currentLimit = 100.0;

    AutomaticBusbarProtection protection(currentLimit);

    cout << "===== AUTOMATIC BUSBAR PROTECTION SYSTEM =====" << endl;

    // Check different feeders
    protection.checkFeeder("Feeder 1", 75);
    protection.checkFeeder("Feeder 2", 85);
    protection.checkFeeder("Feeder 3", 130);

    // Display final status
    protection.displayStatus();

    // Reset after fault clearance
    protection.resetBreaker();

    protection.displayStatus();

    return 0;
}
