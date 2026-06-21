📍 FairMeet Pro: Optimized C++ Backend
FairMeet Pro is a high-performance C++ tool designed to find the mathematically "fairest" meeting point for a group of people. It uses a Geometric Median algorithm to minimize the total weighted travel distance for all participants.

🚀 Features
Weighted Optimization: Assign "importance" (weights 1-10) to participants (useful for prioritizing those with limited mobility or higher travel costs).
Coordinate Precision: Processes Latitude and Longitude coordinates to pinpoint exact locations.
Displacement Analysis: Calculates the total combined travel distance (km) for the entire group.
Fast Execution: Built in C++ for near-instant calculation, even with a large number of participants.

📂 File Structure
main.cpp: The interactive command-line interface.
optimizer.hpp: Header file defining the User, Point, and FairMeetOptimizer structures.
optimizer.cpp: Contains the core mathematical logic for the Geometric Median calculation.
index.html: A web-based front-end/documentation (if applicable).

🛠️ Installation & Compilation
To compile this project, you will need a C++ compiler (like g++).
Clone the repository:
git clone https://github.com/Pamursahasra22/YOUR_REPO_NAME.git
cd FairMeet
Compile the source code:
g++ main.cpp optimizer.cpp -o FairMeetPro
Run the program:
./FairMeetPro

💡 How to Use
Enter the number of participants.
For each participant, provide:
Name
Latitude (X) and Longitude (Y)
Weight (1-10): How much weight their distance carries in the final result.
The system will output the Optimal Meetup Coordinate and the Total Displacement.

📊 The Math
Unlike a simple average (Centroid), the Geometric Median is more robust to outliers (participants living very far away), ensuring the meeting point is truly central and minimizes overall effort for the group.
