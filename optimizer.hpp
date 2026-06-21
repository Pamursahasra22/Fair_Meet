#ifndef OPTIMIZER_HPP
#define OPTIMIZER_HPP

#include <vector>
#include <string>

struct User {
    std::string name;
    double lat;
    double lng;
    double weight; // Base priority
    std::string mode; // "walk", "bike", or "drive"
};

struct Point {
    double lat;
    double lng;
};

class FairMeetOptimizer {
public:
    void addUser(const User& user);
    Point calculateGeometricMedian(); 
    double calculateTotalDistance(Point meetupPoint);
private:
    std::vector<User> users;
    double haversine(double lat1, double lon1, double lat2, double lon2);
    double getEffortMultiplier(std::string mode);
};

#endif