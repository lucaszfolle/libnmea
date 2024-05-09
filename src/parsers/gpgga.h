#ifndef INC_NMEA_GPGGA_H
#define INC_NMEA_GPGGA_H

#include <stdlib.h>
#include <string.h>
#include <nmea.h>

typedef struct
{
	nmea_s base;
	nmea_time_date_t time;
	double latitude;
	double longitude;
	float altitude;
	float undulation;
	float hdop;
	uint8_t n_satellites;
	char altitude_unit;
	char undulation_unit;
	uint8_t position_fix;
} nmea_gpgga_s;

/* Value indexes */
enum
{
	NMEA_GPGGA_TIME = 0,
	NMEA_GPGGA_LATITUDE,
	NMEA_GPGGA_LATITUDE_CARDINAL,
	NMEA_GPGGA_LONGITUDE,
	NMEA_GPGGA_LONGITUDE_CARDINAL,
	NMEA_GPGGA_POSITION_FIX,
	NMEA_GPGGA_N_SATELLITES,
	NMEA_GPGGA_HDOP,
	NMEA_GPGGA_ALTITUDE,
	NMEA_GPGGA_ALTITUDE_UNIT,
	NMEA_GPGGA_UNDULATION,
	NMEA_GPGGA_UNDULATION_UNIT
};

#define INVALID_UNDULATION -9999.999

#endif /* INC_NMEA_GPGGA_H */
