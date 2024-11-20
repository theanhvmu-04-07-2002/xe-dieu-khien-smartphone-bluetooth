//Arduino Bluetooth Controlled Car
//Before uploading the code you have to install the necessary library
//Note - Disconnect the Bluetooth Module before hiting the upload button otherwise you'll get compilation error message.
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install 
//After downloading the library open Arduino IDE >> go to sketch >> Include Libray >> ADD. ZIP Libray >> Select the downloaded 
//ZIP File >> Open it >> Done
//Now You Can Upload the Code without any problem but make sure the bt module isn't connected with Arduino while uploading code

#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ); //tạo động cơ #1, 1KHz pwm
AF_DCMotor motor2(2, MOTOR12_1KHZ); //khai báo các chân cho động cơ, xung PWM
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module,mở port ở mức 9600, mở cổng serial với mức baudrate là 9600 để aduino giao tiếp với máy tính
}

void loop(){
  if(Serial.available() > 0){ //xuất tín hiệu khi nhận được tín hiệu, nếu có tín hiệu vào serial
    command = Serial.read();  // đọc các giá trị nhận được, lấy 1 bai ở trong bộ đệm ra
    Stop(); //initialize with motors stoped,
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command)
    //xuất ra những gì nhận được;
    switch(command){ //( command):là giá trị được truyền vào để so sánh với các điều kiện constant-expression.
    case 'F':  //;là điều kiện để so sánh với giá trị của command truyền vào.
      forward(); //nếu thõa điều kiện nào thì đoạn code bên trong điều kiện đó sẽ được thực thi.
      break; //Là lệnh để thoát khỏi cấu trúc điều khiển switch case
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    }
  } 
}

void forward()
{
  motor1.setSpeed(255); // chọn tốc độ maximum 255
  motor1.run(FORWARD);
  motor2.setSpeed(255); 
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void back()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void left()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void right()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
} 

void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
