#include "optimizer.hpp"
#include <cmath>

#define PI 3.14159265358979323846
#define EARTH_RADIUS_KM 6371.0

void FairMeetOptimizer::addUser(const User& user) {
    users.push_back(user);
}

double FairMeetOptimizer::getEffortMultiplier(std::string mode) {
    if (mode == "walk") return 5.0;
    if (mode == "bike") return 3.0;
    return 1.0; // drive
}

double FairMeetOptimizer::haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * PI / 180.0;
    double dLon = (lon2 - lon1) * PI / 180.0;
    double a = std::sin(dLat/2) * std::sin(dLat/2) +
               std::cos(lat1 * PI / 180.0) * std::cos(lat2 * PI / 180.0) *
               std::sin(dLon/2) * std::sin(dLon/2);
    return EARTH_RADIUS_KM * 2 * std::atan2(std::sqrt(a), std::sqrt(1-a));
}

Point FairMeetOptimizer::calculateGeometricMedian() {
    if (users.empty()) return {0, 0};

    double currLat = 0, currLng = 0, totalEffort = 0;
    for (const auto& u : users) {
        double effectiveW = u.weight * getEffortMultiplier(u.mode);
        currLat += u.lat * effectiveW;
        currLng += u.lng * effectiveW;
        totalEffort += effectiveW;
    }
    Point p = {currLat / totalEffort, currLng / totalEffort};

    for (int iter = 0; iter < 50; iter++) {
        double nLat = 0, nLng = 0, denom = 0;
        for (const auto& u : users) {
            double d = haversine(p.lat, p.lng, u.lat, u.lng);
            if (d < 0.1) d = 0.1;
            
            double effectiveW = u.weight * getEffortMultiplier(u.mode);
            double weightDist = effectiveW / d;
            nLat += u.lat * weightDist;
            nLng += u.lng * weightDist;
            denom += weightDist;
        }
        if (denom > 0) { p.lat = nLat / denom; p.lng = nLng / denom; }
    }
    return p;
}

double FairMeetOptimizer::calculateTotalDistance(Point p) {
    double total = 0;
    for (const auto& u : users) { total += haversine(u.lat, u.lng, p.lat, p.lng); }
    return total;
}