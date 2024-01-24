#include <stdio.h>
#define ON 1
#define OFF 0
char menu(void){
    printf("a. Turn on the vehicle engine\n"
           "b. Turn off the vehicle engine\n"
           "c. Quit the system\n");
    char choice;
    scanf(" %c", &choice);
    return choice;
}
void quit(void){
    printf("Quit program\n");
}
void turn_off_vehicle(void){
    printf("Vehicle engine off!\n");
}
void turn_on_vehicle(void ){
    printf("Vehicle engine on\n");
}
char sensor_set_menu(void){
    printf("a. Turn off the engine\n"
           "b. Set traffic light color\n"
           "c. Set the room temperature\n"
           "d. Set the engine temperature\n");
    char choice;
    scanf(" %c", &choice);
    return choice;
}
void traffic_light(int *speed){
    printf("Enter traffic light color (g-o-r)\n");
    char color;
    scanf(" %c", &color);
    switch (color) {
        case 'g':
            *speed = 100;
            break;
        case 'o':
            *speed = 30;
            break;
        case 'r':
            *speed = 0;
            break;
    }
}
void room_temp(int *temp, int *Ac){
    printf("Enter the room temperature: \n");
    int roomtemp;
    scanf("%d", &roomtemp);
    if (roomtemp < 10 && roomtemp > 30){
        *Ac = ON;
        *temp = 20;
    } else{
        *Ac = OFF;
        *temp = roomtemp;
    }
}
void engine_temp(int *engineTemp, int *engineTempController){
    printf("Enter the engine temperature: \n");
    int enginetemperature;
    scanf("%d", &enginetemperature);
    if (enginetemperature < 100 && enginetemperature > 150){
        *engineTempController = ON;
        *engineTemp = 125;
    } else{
        *engineTempController = OFF;
        *engineTemp = enginetemperature;
    }
}
void status(int *engine, int *Ac, int *speed, int *temp,int *engineTempController, int *engineTemp){
    printf("\n");
    if (*engine)
        printf("i. Engine State: ON\n");
    else
        printf("i. Engine State: OFF\n");

    if (*Ac)
        printf("ii. AC: ON\n");
    else
        printf("ii. AC: OFF\n");

    printf("iii. Vehicle Speed is %d km/hr\n", *speed);
    printf("iv. Room Temperature is %d C\n", *temp);
    if (*engineTempController)
        printf("v. Engine Temperature Controller State: ON\n");
    else
        printf("v. Engine Temperature Controller State: OFF\n");
    printf("vi. Engine Temperature is %d C\n", *engineTemp);
    printf("\n");
}




int main() {
    int speed = 0, temp = 25, Ac = OFF, engine = OFF, engineTemp = 70, engineTempController = OFF;
    char choice;
    do {
        printf("Enter your choice from the list below: \n");
        choice = menu();
        if (choice == 'a'){
            turn_on_vehicle();
            engine = ON;
            while (engine) {
                char sensorChoice = sensor_set_menu();
                switch (sensorChoice) {
                    case 'a':
                        turn_off_vehicle();
                        engine = OFF, speed = 0;
                        status(&engine, &Ac, &speed, &temp, &engineTempController, &engineTemp);
                        break;
                    case 'b':
                        traffic_light(&speed);
                        if (&speed == 30){
                            Ac = ON;
                            temp = temp * (5/4) +1;
                        } else{
                            engine = ON;
                            temp = temp *(5/4) +1;
                        }
                        status(&engine, &Ac, &speed, &temp, &engineTempController, &engineTemp);
                        break;
                    case 'c':
                        room_temp(&temp, &Ac);
                        status(&engine, &Ac, &speed, &temp, &engineTempController, &engineTemp);
                        break;
                    case 'd':
                        engine_temp(&engineTemp, &engineTempController);
                        status(&engine, &Ac, &speed, &temp, &engineTempController, &engineTemp);
                        break;
                }
            }
        }
        else if (choice == 'b'){
            turn_off_vehicle();
            continue;
        }
        else if (choice == 'c'){
            quit();
            break;
        }
    }while(choice != 'c');

    return 0;
}
