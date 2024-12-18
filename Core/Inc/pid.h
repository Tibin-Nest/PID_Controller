/*
 * pid.c
 *
 *  Created on: Dec 18, 2024
 *      Author: tibin.mathew
 */

#ifndef INC_PID_C_
#define INC_PID_C_

typedef struct PID_TYPEDEF
{
//	int error;
	double lastError;
	double integral;
	double derivative;
	double kp;
	double ki;
	double kd;
	double targetPoint;
	double currentPoint;
	double output;
	double outputUpperLimit;
	double outputLowerLimit;
}PID_Typedef;

void PID_updateOutput(PID_Typedef* pid);
void PID_init(PID_Typedef* pid);

#endif /* INC_PID_C_ */
