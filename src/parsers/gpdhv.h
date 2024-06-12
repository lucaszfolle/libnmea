#ifndef INC_NMEA_GPDHV_H
#define INC_NMEA_GPDHV_H

#include <stdlib.h>
#include <string.h>
#include <nmea.h>

typedef struct
{
	nmea_s base;
	nmea_time_date_t time;
	float speed_3d_mps;
	float speed_x_mps;
	float speed_y_mps;
	float speed_z_mps;
	float gndspd_kmph;
} nmea_gpdhv_s;

/* Value indexes */
enum
{
	NMEA_GPDHV_TIME,
	NMEA_GPDHV_3D_SPEED_MPS,
	NMEA_GPDHV_X_SPEED_MPS,
	NMEA_GPDHV_Y_SPEED_MPS,
	NMEA_GPDHV_Z_SPEED_MPS,
	NMEA_GPDHV_GROUND_SPEED_KMPH
};

#endif /* INC_NMEA_GPDHV_H */
