//program to calculate time it would take for two trains to crash and their position
#include <stdio.h>

int main() {
	double position_1, speed_1, position_2, speed_2; //initial speeds and positions read through input
	double combined_position, combined_speed; //combined position and speed used during addition to make calculations easier
	double final_time, distance; //final collision time and position

	printf("Please enter the starting position of train 1: "); //asking user for input
	scanf("%lf", &position_1); //storing the user input into the initialized variables
	printf("Please enter the speed of train 1: ");
	scanf("%lf", &speed_1);
	printf("Please enter the starting position of train 2: ");
	scanf("%lf", &position_2);
	printf("Please enter the speed of train 2: ");
	scanf("%lf", &speed_2);

	combined_position = position_2 - position_1; //gets the distance between the two trains
	combined_speed = speed_1 + speed_2; //add the speed of both trains together 

	final_time = combined_position/combined_speed; // time = distance/rate
	distance = ((final_time * speed_1) + position_1); //finding the position of the collision
	//find position by seeing where train 1 will be at the precise time of the collision

	printf("The two trains will collide in %.2lf hours %.2lf miles down the track.\n", final_time, distance);
	//print statement using a precision of two decimal places for the resulting numbers

	return 0;

}