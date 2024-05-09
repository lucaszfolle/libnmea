#ifndef INC_NMEA_GPGSV_H
#define INC_NMEA_GPGSV_H

#include <stdlib.h>
#include <string.h>
#include <nmea.h>

typedef struct
{
	nmea_s base;
	uint8_t sentences;		 // Number of sentences for full data
	uint8_t sentence_number; // Current sentence number
	uint8_t satellites;		 // Number of satellites in view
	struct
	{
		int16_t prn;	   // Satellite PRN number
		uint16_t azimuth;  // Azimuth, degrees
		uint8_t elevation; // Elevation, degrees
		uint8_t snr;	   // SNR - higher is better
	} sat[4];
} nmea_gpgsv_s;

/* Value indexes */
enum
{
	NMEA_GPGSV_SENTENCES,
	NMEA_GPGSV_SENTENCE_NUMBER,
	NMEA_GPGSV_SATELLITES,
	NMEA_GPGSV_PRN,
	NMEA_GPGSV_ELEVATION,
	NMEA_GPGSV_AZIMUTH,
	NMEA_GPGSV_SNR
};

#endif /* INC_NMEA_GPGSV_H */
