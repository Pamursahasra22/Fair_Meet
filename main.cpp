#include <iostream>
#include <iomanip>
#include "optimizer.hpp"

int main() {
    FairMeetOptimizer optimizer;
    int userCount;

    std::cout << "--- FairMeet Pro: Optimized C++ Backend ---" << std::endl;
    std::cout << "Enter number of participants: ";
    std::cin >> userCount;

    for (int i = 0; i < userCount; ++i) {
        User u;
        std::cout << "\nParticipant " << i + 1 << " Name: ";
        std::cin >> u.name;
        std::cout << "Enter Latitude (X): ";
        std::cin >> u.lat;
        std::cout << "Enter Longitude (Y): ";
        std::cin >> u.lng;
        std::cout << "Enter Weight (1-10): ";
        std::cin >> u.weight;
        optimizer.addUser(u);
    }

    // Call the correct function name
    Point result = optimizer.calculateGeometricMedian();

    std::cout << "\n=====================================" << std::endl;
    std::cout << "OPTIMAL MEETUP POINT CALCULATED" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    // Use .lat and .lng instead of .x and .y
    std::cout << "Coordinate: (" << result.lat << ", " << result.lng << ")" << std::endl;
    std::cout << "Total Displacement: " << optimizer.calculateTotalDistance(result) << " km" << std::endl;
    std::cout << "=====================================" << std::endl;

    return 0;
}