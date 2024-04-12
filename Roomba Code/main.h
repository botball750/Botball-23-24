// Use Both Motors
const int motor_one = 0;
const int motor_two = 3;

const int sensor_one = 0;
const int sensor_two = 1;

const int servo_one = 1;
const int servo_two = 3;

void mavs(int speed, int speed2)
{
  mav(motor_one, speed);
  mav(motor_two, speed2);
}

// Drive using GMPC
void drive(int distance, int speed)
{
  // Clear Motor Position Counter
  cmpc(motor_one);
  cmpc(motor_two);
  
  if (distance < 0)
  {
    while (gmpc(motor_one) || gmpc(motor_two) > distance)
    {
      mavs(-speed, -speed);
    }
  }
  else
  { 
    while (gmpc(motor_one) || gmpc(motor_two) < distance)
    {
      mavs(speed, speed);
    }
  }

  mavs(speed, speed);
}

void move_servo(int port, int position)
{
  enable_servos();

  set_servo_position(port, position);
}

void armdown()
{
    set_servo_position(1, 2047);
}

void armup()
{
    set_servo_position(1, 500);
}

void clawopen()
{
    set_servo_position(3, 300);
}

void clawclose()
{
    set_servo_position(3, 300);
}
