/*
 * pid.c
 *
 *  Created on: Dec 18, 2024
 *      Author: tibin.mathew
 */


#include "pid.h"


void PID_init(PID_Typedef* pid)
{
	pid->integral = 0;
	pid->derivative = 0;
	pid->lastError = 0;

	pid->currentPoint = 0;
	pid->output = 0;

}

void PID_updateOutput(PID_Typedef* pid)
{
	// Get the error
	double error = pid->targetPoint - pid->currentPoint;

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
	if(pid->output < pid->outputLowerLimit)
	{
		pid->output = pid->outputLowerLimit;
	}

	// Update lastError
	pid->lastError = error;
}
