#ifndef INC_NMEA_GPRMC_H
#define INC_NMEA_GPRMC_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <nmea.h>

typedef struct
{
	nmea_s base;
	nmea_time_date_t date_time;
	double latitude;
	double longitude;
	float gndspd_knots;
	float track_deg;
	// The direction of the magnetic variation determines whether or not it
	// is additive - Easterly means subtract magvar_deg from track_deg and
	// westerly means add magvar_deg to track_deg for the correct course.
	float magvar_deg;
	bool valid;
} nmea_gprmc_s;

/* Value indexes */
enum
{
	NMEA_GPRMC_TIME,
	NMEA_GPRMC_STATUS,
	NMEA_GPRMC_LATITUDE,
	NMEA_GPRMC_LATITUDE_CARDINAL,
	NMEA_GPRMC_LONGITUDE,
	NMEA_GPRMC_LONGITUDE_CARDINAL,
	NMEA_GPRMC_GNDSPD_KNOTS,
	NMEA_GPRMC_TRUECOURSE_DEG,
	NMEA_GPRMC_DATE,
	NMEA_GPRMC_MAGVAR_DEG,
	NMEA_GPRMC_MAGVAR_CARDINAL
};

#endif /* INC_NMEA_GPRMC_H */