#ifndef SENSOR_CONF_H
#define SENSOR_CONF_H

#include "mymoo.h"

#if ENABLE_SESSIONS
#include "sessions.h"
#endif


#if SIMPLE_QUERY_ACK
#define ENABLE_READS                  0
#define READ_SENSOR                   0
#pragma message ("compiling simple query-ack application")
#endif
#if SENSOR_DATA_IN_ID
#define ENABLE_READS                  0
#define READ_SENSOR                   1
#pragma message ("compiling sensor data in id application")
#endif
#if SIMPLE_READ_COMMAND
#define ENABLE_READS                  1
#define READ_SENSOR                   0
#pragma message ("compiling simple read command application")
#endif
#if SENSOR_DATA_IN_READ_COMMAND
#define ENABLE_READS                  1
#define READ_SENSOR                   1
#pragma message ("compiling sensor data in read command application")
#endif



#if READ_SENSOR
  #if (ACTIVE_SENSOR == SENSOR_ACCEL_QUICK)
    #include "quick_accel_sensor.h"
  #elif (ACTIVE_SENSOR == SENSOR_ACCEL)
    #include "accel_sensor.h"
  #elif (ACTIVE_SENSOR == SENSOR_INTERNAL_TEMP)
    #include "int_temp_sensor.h"
  #elif (ACTIVE_SENSOR == SENSOR_EXTERNAL_TEMP)
	#include "temp_sensor.h"
  #elif (ACTIVE_SENSOR == SENSOR_NULL)
    #include "null_sensor.h"
  #elif (ACTIVE_SENSOR == SENSOR_COMM_STATS)
	#error "SENSOR_COMM_STATS not yet implemented"
  #endif
#endif

#endif //SENSOR_CONF_H