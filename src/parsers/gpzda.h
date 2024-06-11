#ifndef INC_NMEA_GPZDA_H
#define INC_NMEA_GPZDA_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <nmea.h>

typedef struct
{
	nmea_s base;
	nmea_time_date_t date_time;
} nmea_gpzda_s;

/* Value indexes */
enum
{
	NMEA_GPZDA_TIME,
	NMEA_GPZDA_DAY,
	NMEA_GPZDA_MONTH,
	NMEA_GPZDA_YEAR
};

#endif /* INC_NMEA_GPZDA_H */