#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct Drone {
    int x;
    int y;
};

int main() {
    // initialize random seed
    srand(time(0));

    // create a vector to store the drones
    vector<Drone> swarm;

    // initialize the swarm with 10 drones at random positions
    for (int i = 0; i < 10; i++) {
        Drone drone;
        drone.x = rand() % 100;
        drone.y = rand() % 100;
        swarm.push_back(drone);
    }

    // simulate the swarm moving for 100 time steps
    for (int t = 0; t < 100; t++) {
        cout << "Time step: " << t << endl;
        for (int i = 0; i < swarm.size(); i++) {
            // move the drone in a random direction
            swarm[i].x += rand() % 3 - 1;
            swarm[i].y += rand() % 3 - 1;

            // print the drone's position
            cout << "Drone " << i << ": (" << swarm[i].x << ", " << swarm[i].y << ")" << endl;
        }
    }

    return 0;
}
