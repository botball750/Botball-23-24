// Use Both Motors
void mavs(int speed)
{
  mav(motor_one, speed);
  mav(motor_two, speed);
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
      mavs(-speed);
    }
  }
  else
  { 
    while (gmpc(motor_one) || gmpc(motor_two) < distance)
    {
      mavs(speed);
    }
  }

  mavs(speed);
}

void move_servo(int port, int position)
{
  enable_servos();

  set_servo_position(port, position);
}
