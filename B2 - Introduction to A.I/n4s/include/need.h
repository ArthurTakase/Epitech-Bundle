/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** need
*/

#ifndef NEED_H_
#define NEED_H_

// Globals

#define FALSE           0
#define TRUE            1

// Infos

#define SEPARATOR       ":"
#define LEFT_LASER      4
#define MIDDLE_LASER    15
#define RIGHT_LASER     34
#define STATUS          35

// Commandes

#define START           "START_SIMULATION"
#define STOP            "STOP_SIMULATION"
#define GET_LASER       "GET_INFO_LIDAR"
#define GET_SPEED       "GET_CURRENT_SPEED"
#define GET_WHEELS      "GET_CURRENT_WHEELS"
#define MAXSPD          "GET_CAR_SPEED_MAX"
#define MINSPD          "GET_CAR_SPEED_MIN"
#define GET_TIME        "GET_INFO_SIMTIME"
#define MOVE            "CAR_FORWARD:"
#define ROTATE          "WHEELS_DIR:"

// Protos

int ia(void);
char **get_infos(void);
void clean_stdin(void);
void execute_cmd(char *cmd, char *sign, char *value);
int move_car(char **infos);

#endif /* !NEED_H_ */