#ifndef INC_NMEA_GPGST_H
#define INC_NMEA_GPGST_H

#include <stdlib.h>
#include <string.h>
#include <nmea.h>

typedef struct
{
	nmea_s base;
	nmea_time_date_t time;
	float stddev_rms_m;
	float stddev_lat_m;
	float stddev_lon_m;
	float stddev_alt_m;
} nmea_gpgst_s;

/* Value indexes */
enum
{
	NMEA_GPGST_TIME,
	NMEA_GPGST_STDDEV_RMS_M,
	NMEA_GPGST_RSV0,
	NMEA_GPGST_RSV1,
	NMEA_GPGST_RSV2,
	NMEA_GPGST_STDDEV_LAT_M,
	NMEA_GPGST_STDDEV_LON_M,
	NMEA_GPGST_STDDEV_ALT_M
};

#endif /* INC_NMEA_GPGST_H */
