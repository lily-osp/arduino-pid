# Arduino PID

This repository contains example projects demonstrating the implementation of [PID (Proportional-Integral-Derivative)](explanation/what_is_pid.md) control using Arduino. PID control is a widely used technique in control systems for achieving precise and accurate control of a system's output based on desired setpoints.

## Projects

The repository includes the following example projects:

1. Line Follower: This project demonstrates how to use PID control to create a line-following robot. The robot utilizes sensors to detect a line on the ground and adjusts its movements to stay on the line.

2. Motor Position Control: In this project, PID control is employed to control the position of a motor. The system uses feedback from an encoder or a position sensor to maintain a desired position accurately.

3. Wall Follower: The wall follower project showcases how PID control can be utilized to create a robot that follows along the walls of a maze or an environment. The robot adjusts its movements based on the proximity of the walls to maintain a specific distance.

4. [Ball and Tunnel](https://github.com/lily-open-source/PID-controlled-Ultrasonic-Distance-Measurement): contains code for a PID-controlled system that combines an ultrasonic sensor for distance measurement and motor control based on a setpoint. The PID algorithm helps maintain a specified distance from an obstacle by adjusting the motor speed.

5. [temperature controll system with multiple point controll](https://github.com/1999AZZAR/Temperature-Control-System-with-Multiple-DHT11-Sensors-using-ESP8266): contains code for a temperature control system implemented using Arduino and ESP8266 boards. The system utilizes multiple DHT11 sensors to measure temperature and applies PID control to maintain a desired setpoint temperature. The system consists of two components: the master board and the slave board. The master board performs temperature calculation and control, while the slave board collects temperature data from DHT11 sensors. The master and slave boards communicate with each other over Wi-Fi.

Each project includes the necessary Arduino code, circuit diagrams, and additional documentation to help you understand and implement PID control for the specific application.

## Getting Started

To get started with any of the projects, follow these steps:

1. Clone the repository to your local machine using the following command:

   ```bash
   git clone https://github.com/1999AZZAR/arduino-pid.git
   ```

2. Choose the project you want to work on and navigate to its directory.

3. Open the Arduino IDE or your preferred Arduino development environment.

4. Connect the required hardware components as per the provided circuit diagrams.

5. Upload the Arduino code to your Arduino board.

6. Follow the instructions in the project documentation to calibrate and adjust the PID parameters as needed.

7. Test and observe the behavior of the system based on the specific project's requirements.

## Dependencies

The projects in this repository may require additional libraries or dependencies based on the specific hardware and components used. The necessary dependencies will be mentioned in each project's documentation.

## Contributing

If you would like to contribute to this repository, feel free to open an issue or submit a pull request. Contributions such as bug fixes, improvements, or additional project examples are highly appreciated.

## License

The code in this repository is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the code for personal and commercial purposes. However, please refer to the license file for more details and any limitations.

## Acknowledgements

This repository is inspired by the works of the Arduino community and various online resources. The contributions of individuals and open-source projects are acknowledged and appreciated for their valuable insights and guidance in PID control implementations.

Please refer to the project-specific documentation for any additional acknowledgements or references related to a particular project.

Enjoy exploring the Arduino PID projects and happy coding!

## Support

You can support me by buy me a coffee if u like to.

<div align="left">
  <a href="https://www.buymeacoffee.com/azzar" target="_blank">
    <img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Buy Me A Coffee" style="height: 42px !important;width: 151.9px !important; margin-top: 50px !important;">
  </a>
</div>

