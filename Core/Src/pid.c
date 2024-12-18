/*
 * pid.c
 *
 *  Created on: Dec 18, 2024
 *      Author: tibin.mathew
 */


#include "pid.h"


void PID_updateOutput(PID_Typedef* pid)
{
	// Get the error
	int error = pid->targetPoint - pid->currentPoint;

	//	Get Integral
	pid->integral += pid->lastError;

	// Get Derivative
	pid->derivative = error - pid->lastError;

	// Update PID output
	pid->output = pid->kp * error + pid->ki * pid->integral + pid->kd * pid->derivative;

	// Limit PID output
	if(pid->output > pid->outputUpperLimit)
	{
		pid->output = pid->outputUpperLimit;
	}

	// Update lastError
	pid->lastError = error;
}
