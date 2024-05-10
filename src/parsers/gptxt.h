#ifndef INC_NMEA_GPTXT_H
#define INC_NMEA_GPTXT_H

#include <stdlib.h>
#include <string.h>
#include <nmea.h>

/* Value indexes */
enum
{
	NMEA_GPTXT_ID00,
	NMEA_GPTXT_ID01,
	NMEA_GPTXT_ID02,
	NMEA_GPTXT_TEXT
};
/* Text field length */
#define NMEA_GPTXT_TEXT_SIZE 64
/* Number of ID fields */
#define NMEA_GPTXT_ID_FIELDS (3)

typedef struct
{
	nmea_s base;
	int id[NMEA_GPTXT_ID_FIELDS];
	char text[NMEA_GPTXT_TEXT_SIZE];
} nmea_gptxt_s;

#endif /* INC_NMEA_GPTXT_H */
