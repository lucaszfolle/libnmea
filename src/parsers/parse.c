#include "parse.h"

#define RMC_YEAR_START 2000

int nmea_position_parse(char *s, double *pos)
{
	char *cursor;

	int degrees = 0;
	double minutes = 0;

	if ((s == NULL) || (*s == '\0'))
	{
		return -1;
	}

	/* decimal minutes */
	if (NULL == (cursor = strchr(s, '.')))
	{
		return -1;
	}

	/* minutes starts 2 digits before dot */
	cursor -= 2;
	minutes = atof(cursor);
	*cursor = '\0';

	/* integer degrees */
	cursor = s;
	degrees = atoi(cursor);

	/* combines both parts into the decimal form */
	*pos = ((double)degrees) + (minutes / 60);

	return 0;
}

int nmea_cardinal_direction_parse(char *s)
{
	if ((NULL == s) || ('\0' == *s))
	{
		return 0;
	}

	if ((*s == NMEA_CARDINAL_DIR_SOUTH) || (*s == NMEA_CARDINAL_DIR_WEST))
	{
		return -1;
	}
	else if ((*s == NMEA_CARDINAL_DIR_NORTH) || (*s == NMEA_CARDINAL_DIR_EAST))
	{
		return 1;
	}
	return 0;
}

int nmea_time_parse(char *s, nmea_time_date_t *time)
{
	char *rv;
	uint32_t x;

	if ((s == NULL) || (*s == '\0'))
	{
		return -1;
	}

	x = strtoul(s, &rv, 10);
	time->hour = x / 10000;
	time->minute = (x % 10000) / 100;
	time->second = x % 100;
	if (*rv == '.')
	{
		rv++;
		time->millisecond = atoi(rv) * 10;
		rv += 2;
	}
	if ((time->hour > 23) || (time->minute > 59) || (time->second > 59) || (time->millisecond > 999) || ((int)(rv - s) < NMEA_TIME_FORMAT_LEN))
	{
		return -1;
	}

	return 0;
}

int nmea_date_parse(char *s, nmea_time_date_t *date)
{
	char *rv;
	uint32_t x;

	if ((s == NULL) || (*s == '\0'))
	{
		return -1;
	}

	x = strtoul(s, &rv, 10);
	date->day = x / 10000;
	date->month = ((x % 10000) / 100);
	date->year = x % 100;
	return 0;
}
