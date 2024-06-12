#ifndef INC_NMEA_PARSE_H
#define INC_NMEA_PARSE_H

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE /* glibc2 needs this */
#endif

#include <stdlib.h>
#include <string.h>
#include "../nmea/nmea.h"

#define NMEA_TIME_FORMAT	"%H%M%S"
#define NMEA_TIME_FORMAT_LEN	10

#define NMEA_DATE_FORMAT	"%d%m%y"
#define NMEA_DATE_FORMAT_LEN	6

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Parse GPS position longitude or latitude
 *
 * s string containing the position. Ex: "4712.55", 47 degrees and
 *   12.55 minutes. Will be modified.
 * pos is a pointer to a double where the result should be stored.
 *
 * Returns 0 on success, otherwise -1.
 */
int nmea_position_parse(char *s, double *pos);

/**
 * Parse cardinal direction
 *
 * s is a string containing the letter representing the cardinal direction.
 *
 * Returns the cardinal direction (+1 for north/east or -1 for south/west).
 * On failure, 0 is returned.
 */
int nmea_cardinal_direction_parse(char *s);

/**
 * Parse time from a string
 *
 * s is a string containing the time in format "HHMMSS.ss".
 * time is a pointer to a struct where the parsed time will be stored.
 *
 * Returns 0 on success, otherwise -1.
 */
int nmea_time_parse(char *s, nmea_time_date_t *time);

/**
 * Parse date from a string
 *
 * s is a string containing the date in format "ddmmyy".
 * date is a pointer to a struct where the parsed date will be stored.
 *
 * Returns 0 on success, otherwise -1.
 */
int nmea_date_parse(char *s, nmea_time_date_t *date);

#ifdef __cplusplus
}
#endif

#endif  /* INC_NMEA_PARSE_H */
