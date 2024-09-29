/*
 * main.c
 *
 *  Created on: Apr 20, 2024
 *      Author: NP
 */
#include <stdio.h>

int main() {

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    // Declare variables
    char choice;
    char trafficLight;
    int roomTemperature, engineTemperature;
    int engineState = 0; // 0: OFF, 1: ON
    int acState = 0;// 0: OFF, 1: ON
    int EngineTemperatureController = 0;
    int vehicleSpeed = 0; // in km/hr

    while(1){

    	// Display main menu options
    	printf("Choose an option:\n");
    	printf("a. Turn on the vehicle engine\n");
    	printf("b. Turn off the vehicle engine\n");
    	printf("c. Quit the system\n");
    	scanf(" %c", &choice);

    	 // Read user choice
    	 switch (choice) {
    		case 'a':
    			// Turn on the vehicle engine
    			engineState = 1 ;
    			printf("Vehicle engine is ON.\n");

    		while(engineState)	{

    				// Display sensor menu options
    				printf("Choose an option:\n");
    				printf("a. Turn off the engine \n");
    			  	printf("b. Set the traffic light color.\n");
    		    	printf("c. Set the room temperature (Temperature Sensor)\n");
    		    	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
    		    	scanf(" %c", &choice);

    		    	// Read user choice
    		    	switch (choice) {
    		    	case 'a':
    		    		 // Turn off the engine
    		    		engineState = 0 ;
    		    		printf("Vehicle engine is OFF.\n");
    		    		break;
    		    	case 'b':
    		    		 // Set the traffic light color
    		    		 printf("Enter the traffic light color (G/O/R): ");
    		    		 scanf(" %c", &trafficLight);
    		    		 if(trafficLight == 'G'){
    		    			 vehicleSpeed = 100;
    		    		 }else if(trafficLight == 'o'){
    		    			 vehicleSpeed = 30;
    		    		 }else if(trafficLight == 'R'){
    		    			 vehicleSpeed = 0;
    		    		 }
    		    		 break;
    		    	case 'c':
    		    		// Set the room temperature
    		    		printf("Enter the Room Temperature: ");
    		    		scanf(" %d", &roomTemperature);
    		    		if(roomTemperature < 10 || roomTemperature > 30){
    		    			acState = 1;
    		    			roomTemperature =20;
    		    		}else{
    		    			acState = 0;
    		    		}
						break;
    		    	case 'd':
    		    		 // Set the engine temperature
    		    		printf("Enter the Engine Temperature: ");
    		    		scanf(" %d", &engineTemperature);
    		    		if(engineTemperature < 100 || engineTemperature > 150){
    		    			EngineTemperatureController = 1 ;
    		    			engineTemperature = 125;
    		    		}else{
    		    			EngineTemperatureController = 0;
    		    		}
    		    		break;
    		    	default:
    		    	printf("Invalid option!\n");
    		    	break;
    		    	}
    			if(vehicleSpeed == 30){
    				if(!acState){
    					acState = 1;
    					roomTemperature = roomTemperature * 5 / 4 + 1;
    				}
    				if(!EngineTemperatureController){
    					EngineTemperatureController = 1;
    					engineTemperature = engineTemperature * 5 / 4 + 1;
    				}
    			}
    			// Display current vehicle state
    			printf("\nCurrent vehicle state:\n");
    			printf("Engine state: %s\n", engineState ? "ON" : "OFF");
    			printf("AC: %s\n", acState ? "ON" : "OFF");
    			printf("Vehicle speed: %d km/hr\n", vehicleSpeed);
    			printf("Room temperature: %d\n", roomTemperature);
    			printf("Engine temperature: %d\n", engineTemperature);
    		}
    		break;
    	case 'b':
    		// Turn off the vehicle engine
    		printf("Vehicle engine is OFF.\n");
    		break;
    	case 'c':
    		// Quit the system
    		printf("Quitting the system.\n");
    		return 0;
    	default:
    		// Invalid option
    		printf("Invalid option!\n");
    		break;
    	}
    }

    return 0;
}
