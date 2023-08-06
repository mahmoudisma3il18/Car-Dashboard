## Car Dashboard
This is a virtual dashboard application for Ain Shams University's Formula Student car team. The application displays data collected from the car's sensors.

![image](https://github.com/mahmoudisma3il18/Car-Dashboard/assets/103974340/02eaf98c-02ac-43e6-9082-b566abd2df4e)


The data is received from the car via telemetry and sent to the PC using a UART protocol.

The application is built using Qt and QML.

Code structure
Qt project file
The ASU_RACING_TEAM_DASHBOARD.pro file is the Qt project file. It contains information about the project's name, dependencies, configuration, etc.

QML files
The main.qml file is the main QML file that contains the dashboard UI in QML.

The qml.qrc file is a resource file that contains images used in the QML UI.

C++ files
The communication_thread.cpp and communication_thread.h files contain the code for reading data from the UART connection. A separate thread is used for this.

The controller.cpp and controller.h files contain business logic and functions to be called from QML.

The main.cpp file contains the main function to start the Qt application.

Build and run
To build and run the project, you'll need Qt Creator installed. Then simply open the .pro file in Qt Creator and click Run.

The dashboard will be displayed, however data will not be received yet since it's not connected to the car's telemetry system.

