#ifndef INC_NMEA_GPGLL_H
#define INC_NMEA_GPGLL_H

#include <stdlib.h>
#include <string.h>
#include <nmea.h>

typedef struct
{
	nmea_s base;
	double longitude;
	double latitude;
	nmea_time_date_t time;
} nmea_gpgll_s;

/* Value indexes */
enum
{
	NMEA_GPGLL_LATITUDE = 0,
	NMEA_GPGLL_LATITUDE_CARDINAL,
	NMEA_GPGLL_LONGITUDE,
	NMEA_GPGLL_LONGITUDE_CARDINAL,
	NMEA_GPGLL_TIME
};

#endif /* INC_NMEA_GPGLL_H */
