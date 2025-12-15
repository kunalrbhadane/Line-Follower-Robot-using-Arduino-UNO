Line Follower Robot using Arduino
A simple and effective line follower robot based on the Arduino UNO platform. This project uses two IR sensors to detect a black line on a white surface and an L298N motor driver to control the robot's movement.
How it Works
The robot uses two IR sensors to navigate. The core logic is as follows:
On the Line: If both sensors are on the white surface (on either side of the black line), the robot moves forward.
Veering Left: If the right sensor detects the black line, it means the robot is drifting to the left. The robot then turns right to correct its path.
Veering Right: If the left sensor detects the black line, it means the robot is drifting to the right. The robot then turns left to get back on the line.
Stop Condition: If both sensors detect the black line (e.g., at a crossing or the end of the path), the robot stops.
Hardware Required
Arduino UNO
L298N Motor Driver Module
2 x IR (Infrared) Sensors
Robot Chassis with 2 DC motors and wheels
Power source (e.g., 9V battery or a LiPo battery pack)
Connecting wires
How to Use
Assemble the Hardware: Connect the motors and IR sensors to the Arduino UNO through the L298N motor driver as defined in the code's pinout section.
Upload the Code: Open the .ino file in the Arduino IDE, connect your Arduino UNO to your computer, and upload the sketch.
Run the Robot: Place the robot on a white surface with a black line, power it on, and watch it follow the line