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
	int lastError;
	int integral;
	int derivative;
	int kp;
	int ki;
	int kd;
	int targetPoint;
	int currentPoint;
	int output;
	int outputUpperLimit;
}PID_Typedef;

int PID_updateOutput(int targetPoint, int currentPoint);

#endif /* INC_PID_C_ */
