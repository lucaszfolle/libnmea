#ifndef INC_NMEA_GPGSA_H
#define INC_NMEA_GPGSA_H

#include <stdlib.h>
#include <string.h>
#include <nmea.h>

#define NMEA_GPGSA_MAX_SATS (12)

typedef struct
{
	nmea_s base;
	char mode;	  /* M = manual (forced 2D or 3D), A = automatic */
	char fixtype; /* 1 = no fix, 2 = 2D, 3 = 3D */
	int8_t satID[NMEA_GPGSA_MAX_SATS];
	float pdop;
	float hdop;
	float vdop;
} nmea_gpgsa_s;

/* Value indexes */
enum
{
	NMEA_GPGSA_MODE = 0,
	NMEA_GPGSA_FIXTYPE,
	NMEA_GPGSA_SATID_00,
	NMEA_GPGSA_SATID_01,
	NMEA_GPGSA_SATID_02,
	NMEA_GPGSA_SATID_03,
	NMEA_GPGSA_SATID_04,
	NMEA_GPGSA_SATID_05,
	NMEA_GPGSA_SATID_06,
	NMEA_GPGSA_SATID_07,
	NMEA_GPGSA_SATID_08,
	NMEA_GPGSA_SATID_09,
	NMEA_GPGSA_SATID_10,
	NMEA_GPGSA_SATID_11,
	NMEA_GPGSA_PDOP,
	NMEA_GPGSA_HDOP,
	NMEA_GPGSA_VDOP
};

#endif /* INC_NMEA_GPGSA_H */
