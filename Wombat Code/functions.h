// Use Both Motors
const int motor_one = 0;
const int motor_two = 3;

const int sensor_one = 0;
const int sensor_two = 1;

const int servo_one = 1;
const int servo_two = 3;

void motors(int speed, int speed2)
{
    mav(motor_one, speed * 100);
    mav(motor_two, speed2 * 100);
}

void slowm(int speed, int speed2)
{
 	motor(motor_one, speed);
    motor(motor_two, speed2);
}

void move_servo(int port, int position)
{
  enable_servos();

  set_servo_position(port, position);
}

void armdown()
{
    set_servo_position(1, 1730);
}

void armup()
{
    set_servo_position(1, 600);
}

void clawopen()
{
    set_servo_position(3, 1600);
}

void servo(int port,int target_position, float tim)
{
    enable_servos();
    
    int current_position= get_servo_position(port);    
 
   while(current_position != target_position)
    {
        
       if(current_position < target_position)
       { current_position = current_position + 1;
           }   
           else
           {  
              current_position = current_position - 1;
           }  
        set_servo_position(port,current_position);
        msleep(tim);  
   }
    
}    
void clawclose()
{
    servo(3, 450, 1);
}

void sleep(float time)
{
    msleep(time * 1000);
    ao();
}
