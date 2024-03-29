// Variables
int Servo_Arm = 0;
int Servo_Claw = 1;

// Initialization
void init()
{
    create3_connect();
    printf("Starting Create3 Code!\n");
}

// Perform at end of each function
void End_Of_Code()
{
    create3_wait();
    printf("Process Executed Successfully.\n");
}

// Drive Distance in Meters
void driveM(float distance, int speed)
{
    create3_drive_straight(distance, speed);
    End_Of_Code();
}

// Drive Distance in Feet
void driveFT(float distance, int speed)
{
    create3_drive_straight(distance * 0.333, speed);
    End_Of_Code();
}

// Rotate Create3 in any degree
void rotate(int rotation, int speed)
{
    create3_rotate_degrees(rotation, speed);
    End_Of_Code();
}

// Move any servo in the arguemnts.
void moveServo(int port, int position)
{
    enable_servos();
    set_servo_position(port, position);

    End_Of_Code();
}
