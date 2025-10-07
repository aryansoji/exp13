#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;

std_msgs::Int16 flex_msg;
ros::Publisher pub_flex("flex_sensor", &flex_msg);

const int FLEX_PIN = A0; // Pin connected to the flex sensor

void setup() {
  nh.initNode();
  nh.advertise(pub_flex);
}

void loop() {
  int flex_value = analogRead(FLEX_PIN);
  flex_msg.data = flex_value;
  pub_flex.publish(&flex_msg);
  
  nh.spinOnce();
  delay(100);
}
